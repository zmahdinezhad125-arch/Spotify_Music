#ifndef LISTENERWIDGET_H
#define LISTENERWIDGET_H

#include "../Entities/account.h"
#include "../Services/listenerservice.h"
#include <QWidget>

namespace Ui {
class ListenerWidget;
}

class ListenerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ListenerWidget(const Account& account, ListenerService* listenerService, QWidget *parent = nullptr);
    ~ListenerWidget();

private:
    Ui::ListenerWidget *ui;
    ListenerService* listenerService;
    Account account;
    void refreshPlaylists();
    void refreshSongs();
private slots:
    void onCreatePlaylistClicked();
    void onLikeSongClicked();
    void onDeletePlaylistClicked();
    void onAddSongToPlaylistClicked();
    void onPlaylistSelected();
    void onRemoveSongFromPlaylistClicked();
    void onSearchSongClicked();
    void onApplyFilterClicked();
signals:
    void logoutRequested();
};

#endif // LISTENERWIDGET_H
