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