#include "listenerwidget.h"
#include "ui_listenerwidget.h"

#include <QInputDialog>
#include <QMessageBox>

ListenerWidget::ListenerWidget(const Account& account, ListenerService* listenerService, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ListenerWidget)
    , account(account)
    , listenerService(listenerService)
{
    ui->setupUi(this);
    refreshPlaylists();
    ui->welcomeLabel->setText("Welcome " + account.getFullName());
    connect(ui->createPlaylistButton,&QPushButton::clicked, this, &ListenerWidget::onCreatePlaylistClicked);
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
