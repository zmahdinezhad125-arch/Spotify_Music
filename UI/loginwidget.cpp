#include "loginwidget.h"
#include "ui_loginwidget.h"

#include <QMessageBox>
LoginWidget::LoginWidget(AuthenticationService* authService, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWidget)
    , authenticationService(authService)
{
    ui->setupUi(this);
    connect(ui->loginButton, &QPushButton::clicked, this, &LoginWidget::onLoginClicked);
    connect(ui->registerButton, &QPushButton::clicked, this, &LoginWidget::onRegisterClicked);
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::onLoginClicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    auto account = authenticationService->login(username, password);
    if(account.has_value())
    {
        QMessageBox::information(this, "Success", "Login successful");
    }
    else
    {
        QMessageBox::warning(this, "Error", "Wrong username or password");
    }
}

void LoginWidget::onRegisterClicked()
{
    RegisterWidget* registerWidget =new RegisterWidget(authenticationService);
    registerWidget->show();
}