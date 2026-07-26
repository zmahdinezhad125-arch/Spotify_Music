#include "listenerwidget.h"
#include "ui_listenerwidget.h"

#include "../Entities/song.h"

#include <QInputDialog>
#include <QMessageBox>

ListenerWidget::ListenerWidget(const Account& account, ListenerService* listenerService, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ListenerWidget)
    , account(account)
    , listenerService(listenerService)
{
    ui->setupUi(this);
    connect(ui->filterTypeComboBox, &QComboBox::currentTextChanged, this,
        [this]()
        {
            QString type =
                ui->filterTypeComboBox->currentText();

            if(type == "Genre")
            {
                ui->genreComboBox->setEnabled(true);
                ui->yearSpinBox->setEnabled(false);
            }
            else if(type == "Year")
            {
                ui->genreComboBox->setEnabled(false);
                ui->yearSpinBox->setEnabled(true);
            }
            else
            {
                ui->genreComboBox->setEnabled(false);
                ui->yearSpinBox->setEnabled(false);
            }
        });
    ui->genreComboBox->setEnabled(false);
    ui->yearSpinBox->setEnabled(false);
    refreshPlaylists();
    refreshSongs();
    ui->welcomeLabel->setText("Welcome " + account.getFullName());
    connect(ui->createPlaylistButton,&QPushButton::clicked, this, &ListenerWidget::onCreatePlaylistClicked);
    connect(ui->likeSongButton, &QPushButton::clicked, this, &ListenerWidget::onLikeSongClicked);
    connect(ui->logoutButton, &QPushButton::clicked, this,
        [this]()
        {
            emit logoutRequested();
            this->close();
        });
    connect(ui->deletePlaylistButton, &QPushButton::clicked, this, &ListenerWidget::onDeletePlaylistClicked);
    connect(ui->addSongToPlaylistButton, &QPushButton::clicked, this, &ListenerWidget::onAddSongToPlaylistClicked);
    connect(ui->playlistsListWidget, &QListWidget::itemClicked, this, &ListenerWidget::onPlaylistSelected);
    connect(ui->removeSongFromPlaylistButton, &QPushButton::clicked, this, &ListenerWidget::onRemoveSongFromPlaylistClicked);
    connect(ui->searchButton, &QPushButton::clicked, this, &ListenerWidget::onSearchSongClicked);
    connect(ui->applyFilterButton, &QPushButton::clicked, this, &ListenerWidget::onApplyFilterClicked);
}

ListenerWidget::~ListenerWidget()
{
    delete ui;
}

void ListenerWidget::onCreatePlaylistClicked()
{
    bool ok;
    QString playlistName = QInputDialog::getText(this, "Create Playlist", "Playlist Name:", QLineEdit::Normal, "", &ok);
    if(!ok || playlistName.trimmed().isEmpty())
    {
        return;
    }
    bool result = listenerService->createPlaylist(playlistName, account.getId());
    if(result)
    {
        QMessageBox::information(this, "Success", "Playlist created successfully");
        refreshPlaylists();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Playlist creation failed");
    }
}

void ListenerWidget::refreshPlaylists()
{
    ui->playlistsListWidget->clear();
    QVector<Playlist> playlists = listenerService->getPlaylists(account.getId());
    for(const Playlist& playlist :playlists)
    {
        ui->playlistsListWidget->addItem(playlist.getName());
    }
}

void ListenerWidget::refreshSongs()
{
    ui->songsListWidget->clear();
    QVector<Song> songs =listenerService->getSongs();
    for(const Song& song : songs)
    {
        ui->songsListWidget->addItem(song.getName());
    }
}

void ListenerWidget::onLikeSongClicked()
{
    int row = ui->songsListWidget->currentRow();
    if(row<0)
    {
        QMessageBox::warning(this, "Error", "Please select a song");
        return;
    }
    QVector<Song> songs = listenerService->getSongs();
    int songID = songs[row].getSongID();
    bool result = listenerService->likeSong(account.getId(), songID);
    if(result)
    {
        QMessageBox::information(this, "Success", "Song added to favorites");
        refreshPlaylists();
    }
    else
    {
        QMessageBox::warning( this, "Error", "Operation failed");
    }
}

void ListenerWidget::onDeletePlaylistClicked()
{
    QListWidgetItem* item = ui->playlistsListWidget->currentItem();
    if(item == nullptr)
    {
        QMessageBox::warning(this, "Error", "Select a playlist first");
        return;
    }
    QString playlistName =item->text();
    QVector<Playlist> playlists =listenerService->getPlaylists(account.getId());
    for(const Playlist& playlist : playlists)
    {
        if(playlist.getName() == playlistName)
        {
            listenerService->deletePlaylist(playlist.getPlaylistID());
            refreshPlaylists();
            QMessageBox::information(this, "Success", "Playlist deleted");
            return;
        }
    }
}

void ListenerWidget::onAddSongToPlaylistClicked()
{
    int songRow = ui->songsListWidget->currentRow();
    int playlistRow = ui->playlistsListWidget->currentRow();
    if(songRow < 0 || playlistRow < 0)
    {
        QMessageBox::warning(this, "Error", "Select both a song and a playlist");
        return;
    }
    QVector<Song> songs = listenerService->getSongs();
    QVector<Playlist> playlists = listenerService->getPlaylists(account.getId());
    int songID = songs[songRow].getSongID();
    int playlistID = playlists[playlistRow].getPlaylistID();
    bool result = listenerService->addSongToPlaylist( playlistID, songID);
    if(result)
    {
        QMessageBox::information(this, "Success", "Song added to playlist");
    }
    else
    {
        QMessageBox::warning(this, "Error", "Operation failed");
    }
}

void ListenerWidget::onPlaylistSelected()
{
    int row = ui->playlistsListWidget->currentRow();
    if(row < 0)
    {
        return;
    }
    QVector<Playlist> playlists = listenerService->getPlaylists(account.getId());
    int playlistID = playlists[row].getPlaylistID();
    QVector<Song> songs = listenerService->getPlaylistSongs(playlistID);
    ui->playlistSongsListWidget->clear();
    for(const Song& song : songs)
    {
        ui->playlistSongsListWidget->addItem(song.getName());
    }
}

void ListenerWidget::onRemoveSongFromPlaylistClicked()
{
    int playlistRow = ui->playlistsListWidget->currentRow();
    int songRow = ui->playlistSongsListWidget->currentRow();
    if(playlistRow < 0 || songRow < 0)
    {
        QMessageBox::warning(this, "Error", "Select a playlist and a song");
        return;
    }
    QVector<Playlist> playlists = listenerService->getPlaylists(account.getId());
    int playlistID = playlists[playlistRow].getPlaylistID();
    QVector<Song> songs = listenerService->getPlaylistSongs(playlistID);
    int songID = songs[songRow].getSongID();
    bool result = listenerService->removeSongFromPlaylist(playlistID, songID);
    if(result)
    {
        onPlaylistSelected();
        QMessageBox::information(this, "Success", "Song removed");
    }
}

void ListenerWidget::onSearchSongClicked()
{
    QString text = ui->searchLineEdit->text().trimmed();
    ui->songsListWidget->clear();
    QVector<Song> songs;
    if(text.isEmpty())
    {
        songs = listenerService->getSongs();
    }
    else
    {
        songs = listenerService->searchSongs(text);
    }
    for(const Song& song : songs)
    {
        ui->songsListWidget->addItem(song.getName());
    }
}

void ListenerWidget::onApplyFilterClicked()
{
    ui->songsListWidget->clear();
    QString filterType = ui->filterTypeComboBox->currentText();
    QVector<Song> songs;
    if(filterType == "All")
    {
        songs = listenerService->getSongs();
    }
    else if(filterType == "Genre")
    {
        QString genreText = ui->genreComboBox->currentText();
        Genre genre;
        if(genreText == "Pop")
            genre = Genre::Pop;
        else if(genreText == "Rock")
            genre = Genre::Rock;
        else if(genreText == "Classical")
            genre = Genre::Classical;
        else if(genreText == "Jazz")
            genre = Genre::Jazz;
        else if(genreText == "Rap")
            genre = Genre::Rap;
        else
            genre = Genre::Traditional;
        songs = listenerService->filterSongsByGenre(genre);
    }
    else if(filterType == "Year")
    {
        int year = ui->yearSpinBox->value();
        songs = listenerService->filterSongsByYear(year);
    }
    for(const Song& song : songs)
    {
        ui->songsListWidget->addItem(song.getName());
    }
}