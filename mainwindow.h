#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Repositories/artistrepository.h"
#include "Repositories/listenerrepository.h"
#include "Services/authenticationservice.h"
#include "UI/loginwidget.h"

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
    AuthenticationService authenticationService;
    LoginWidget* loginWidget;
};
#endif // MAINWINDOW_H
