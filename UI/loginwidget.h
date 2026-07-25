#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

#include "../Services/authenticationservice.h"
#include "registerwidget.h"

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(AuthenticationService* authService, QWidget *parent = nullptr);
    ~LoginWidget();

private:
    Ui::LoginWidget *ui;
    AuthenticationService* authenticationService;
private slots:
    void onLoginClicked();
    void onRegisterClicked();
};

#endif // LOGINWIDGET_H
