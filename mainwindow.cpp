#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , authenticationService(
          artistRepository,
          listenerRepository)
    , artistService(
        albumRepository,
        songRepository)
    , listenerService(
          playlistRepository,
          songRepository)
{
    ui->setupUi(this);
    loginWidget =new LoginWidget(&authenticationService, &artistService, &listenerService, this);
    setCentralWidget(loginWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
