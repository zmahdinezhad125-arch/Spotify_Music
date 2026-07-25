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
    }
    else
    {
        QMessageBox::warning(this, "Error", "Album creation failed");
    }
}