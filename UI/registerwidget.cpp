#include "registerwidget.h"
#include "ui_registerwidget.h"

#include <QMessageBox>

RegisterWidget::RegisterWidget(AuthenticationService* authService, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegisterWidget)
    , authenticationService(authService)
{
    ui->setupUi(this);
    connect(ui->registerButton, &QPushButton::clicked, this, &RegisterWidget::onRegisterClicked);
}

RegisterWidget::~RegisterWidget()
{
    delete ui;
}

void RegisterWidget::onRegisterClicked()
{
    QString fullName = ui->fullNameLineEdit->text();
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString role = ui->roleComboBox->currentText();
    QString biography = ui->biographyTextEdit->toPlainText();

    bool success = false;
    try
    {
        if(role=="Artist")
        {
            success = authenticationService->registerArtist(fullName, username, password, biography);
        }
        else
        {
            success = authenticationService->registerListener(fullName, username, password, biography);
        }
    }
    catch (const std::exception& e)
    {
        QMessageBox::warning(this, "Error", e.what());
        return;
    }
    if(success)
    {
        QMessageBox::information(this, "Success", "Registeration successful");
    }
    else
    {
        QMessageBox::information(this, "Error", "Registeration failed");
    }
}