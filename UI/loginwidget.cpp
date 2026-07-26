#include "loginwidget.h"
#include "ui_loginwidget.h"

#include "artistwidget.h"
#include "listenerwidget.h"

#include <QMessageBox>

LoginWidget::LoginWidget(AuthenticationService* authService, ArtistService* artistService, ListenerService* listenerService, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWidget)
    , authenticationService(authService)
    , artistService(artistService)
    , listenerService(listenerService)
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
    std::optional<Account> account;
    try
    {
        account = authenticationService->login(username, password);
    }
    catch (const std::exception& e)
    {
        QMessageBox::warning(this, "Error", e.what());
        return;
    }

    if(account.has_value())
    {
        if(account->getRole()==Role::Artist)

        {
            ArtistWidget* artistWidget = new ArtistWidget(*account, artistService);
            connect(artistWidget, &ArtistWidget::logoutRequested, this,
                    [this]()
                    {
                        this->show();
            } );
            artistWidget->show();
            this->hide();
        }
        else
        {
            ListenerWidget* listenerWidget = new ListenerWidget(*account, listenerService);
            connect(listenerWidget, &ListenerWidget::logoutRequested, this,
                    [this]()
                    {
                        this->show();
                    });
            listenerWidget->show();
            this->hide();
        }
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