#ifndef REGISTERWIDGET_H
#define REGISTERWIDGET_H

#include <QWidget>

#include "../Services/authenticationservice.h"

namespace Ui {
class RegisterWidget;
}

class RegisterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterWidget( AuthenticationService* authService, QWidget *parent = nullptr);
    ~RegisterWidget();

private:
    Ui::RegisterWidget *ui;
    AuthenticationService* authenticationService;
private slots:
    void onRegisterClicked();
};

#endif // REGISTERWIDGET_H
