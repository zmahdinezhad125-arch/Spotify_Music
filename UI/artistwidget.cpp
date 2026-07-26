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
    connect(ui->createAlbumButton, &QPushButton::clicked, this, &ArtistWidget::onCreateAlbumClicked);
    connect(ui->createSongButton, &QPushButton::clicked, this, &ArtistWidget::onCreateSongClicked);
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
    QVector<Album> albums = artistService->getAlbums(account.getId());
    for(const Album& album : albums)
    {
        ui->albumsListWidget->addItem(album.getName());
    }
}

void ArtistWidget:: onCreateSongClicked()
{
    bool ok;
    QString songName = QInputDialog::getText(this, "Create Song", "Song \
Name:", QLineEdit::Normal, "", &ok);
    int year = QInputDialog::getInt(this, "REease Year", "Year:",2026, 1900, 2010, 1, &ok);
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
    bool result = artistService->createSong(songName, year, genre, "", account.getId(), "", 0);
    if(result)
    {
        QMessageBox::information(this, "Success", "Song created successfully");
    }
    else
    {
        QMessageBox::warning(this, "Error", "Song creation failed");
    }
}