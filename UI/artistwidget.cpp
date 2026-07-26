#include "artistwidget.h"
#include "ui_artistwidget.h"

#include <QInputDialog>
#include <QMessageBox>

ArtistWidget::ArtistWidget(const Account& account, ArtistService* artistService, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ArtistWidget)
    , account(account)
    , artistService(artistService)
{
    ui->setupUi(this);
    ui->welcomeLabel->setText("Welcome " + account.getFullName());
    refreshAlbums();
    refreshSongs();
    connect(ui->createAlbumButton, &QPushButton::clicked, this, &ArtistWidget::onCreateAlbumClicked);
    connect(ui->createSongButton, &QPushButton::clicked, this, &ArtistWidget::onCreateSongClicked);
    connect(ui->logoutButton, &QPushButton::clicked, this,
            [this]()
            {
                emit logoutRequested();
                this->close();
    });
    connect(ui->albumsListWidget, &QListWidget::itemClicked, this, &ArtistWidget::onAlbumSelected);
}

ArtistWidget::~ArtistWidget()
{
    delete ui;
}


void ArtistWidget::onCreateAlbumClicked()
{
    bool ok;
    QString albumName = QInputDialog::getText(this, "Create Album", "Album Name", QLineEdit::Normal, "", &ok);
    if(!ok || albumName.isEmpty())
        return;
    bool result = artistService->createAlbum(account.getId(), albumName, "");
    if(result)
    {
        QMessageBox::information(this, "Success", "Album created successfully");
        refreshAlbums();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Album creation failed");
    }
}

void ArtistWidget::refreshAlbums()
{
    ui->albumsListWidget->clear();
    ui->albumsListWidget->addItem("Singles");
    QVector<Album> albums = artistService->getAlbums(account.getId());
    for(const Album& album : albums)
    {
        ui->albumsListWidget->addItem(album.getName());
    }
}

void ArtistWidget:: onCreateSongClicked()
{
    bool ok;
    QVector<Album> albums = artistService->getAlbums(account.getId());
    QStringList albumNames;
    albumNames << "Singles";
    for(const Album& album : albums)
    {
        albumNames << album.getName();
    }
    QString selectedAlbum = QInputDialog::getItem( this, "Album", "Choose album:", albumNames, 0, false, &ok);
    if(!ok)
    {
        return;
    }
    int albumID = 0;
    for(const Album& album : albums)
    {
        if(album.getName()==selectedAlbum)
        {
            albumID = album.getAlbumID();
            break;
        }
    }
    QString songName = QInputDialog::getText(this, "Create Song", "Song \
Name:", QLineEdit::Normal, "", &ok);
    int year = QInputDialog::getInt(this, "REease Year", "Year:",2026, 1900, 2026, 1, &ok);
    QStringList genres = {"Pop", "Rock", "Classical", "Jazz", "Rap", "Traditional"};
    QString selectedGenre = QInputDialog::getItem(this, "Genre", "Select Genre:", genres, 0, false, &ok);

    Genre genre = Genre::Pop;

    if(selectedGenre == "Rock")
        genre = Genre::Rock;
    else if(selectedGenre == "Classical")
        genre = Genre::Classical;
    else if(selectedGenre == "Jazz")
        genre = Genre::Jazz;
    else if(selectedGenre == "Rap")
        genre = Genre::Rap;
    else if(selectedGenre == "Traditional")
        genre = Genre::Traditional;

    if(!ok)
        return;
    bool result = artistService->createSong(songName, year, genre, "", account.getId(), "", albumID);
    if(result)
    {
        QMessageBox::information(this, "Success", "Song created successfully");
        refreshSongs();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Song creation failed");
    }
}

void ArtistWidget::refreshSongs()
{
    ui->songsListWidget->clear();
    QVector<Song> songs =artistService->getSongs(account.getId());
    for(const Song& song : songs)
    {
        ui->songsListWidget->addItem(song.getName());
    }
}
void ArtistWidget::onAlbumSelected()
{
    ui->songsListWidget->clear();
    QListWidgetItem* item = ui->albumsListWidget->currentItem();
    if(item == nullptr)
    {
        return;
    }
    QString selectedAlbumName = item->text();
    if(selectedAlbumName == "Singles")
    {
        QVector<Song> songs = artistService->getSingles(account.getId());
        for(const Song& song : songs)
        {
            ui->songsListWidget->addItem(song.getName());
        }
        return;
    }
    QVector<Album> albums = artistService->getAlbums(account.getId());
    for(const Album& album : albums)
    {
        if(album.getName() == selectedAlbumName)
        {
            QVector<Song> songs = artistService->getSongsByAlbum(album.getAlbumID());
            for(const Song& song : songs)
            {
                ui->songsListWidget->addItem(song.getName());
            }
            return;
        }
    }
}