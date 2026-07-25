#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Repositories/artistrepository.h"
#include "Repositories/listenerrepository.h"
#include "Services/authenticationservice.h"
#include "Repositories/albumrepository.h"
#include "Repositories/songrepository.h"
#include "Repositories/playlistrepository.h"
#include "UI/loginwidget.h"
#include "Services/artistservice.h"
#include "Services/listenerservice.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    ArtistRepository artistRepository;
    ListenerRepository listenerRepository;
    AlbumRepository albumRepository;
    SongRepository songRepository;
    PlaylistRepository playlistRepository;
    AuthenticationService authenticationService;
    LoginWidget* loginWidget;
    ArtistService artistService;
    ListenerService listenerService;
};
#endif // MAINWINDOW_H
