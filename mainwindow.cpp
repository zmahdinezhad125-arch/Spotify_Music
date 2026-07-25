#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , authenticationService(
          artistRepository,
          listenerRepository)
{
    ui->setupUi(this);
    loginWidget =new LoginWidget(&authenticationService, this);
    setCentralWidget(loginWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
