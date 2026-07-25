#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

#include "../Services/authenticationservice.h"
#include "registerwidget.h"
#include "../Services/artistservice.h"
#include "../Services/listenerservice.h"

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(AuthenticationService* authService, ArtistService* artistService, ListenerService* listenerService, QWidget *parent = nullptr);
    ~LoginWidget();

private:
    Ui::LoginWidget *ui;
    AuthenticationService* authenticationService;
    ArtistService* artistService;
    ListenerService* listenerService;
private slots:
    void onLoginClicked();
    void onRegisterClicked();
};

#endif // LOGINWIDGET_H
