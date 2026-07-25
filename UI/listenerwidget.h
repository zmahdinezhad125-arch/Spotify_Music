#ifndef LISTENERWIDGET_H
#define LISTENERWIDGET_H

#include "../Entities/account.h"
#include "../Services/listenerservice.h"
#include <QWidget>

namespace Ui {
class ListenerWidget;
}

class ListenerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ListenerWidget(const Account& account, ListenerService* listenerService, QWidget *parent = nullptr);
    ~ListenerWidget();

private:
    Ui::ListenerWidget *ui;    Account account;
};

#endif // LISTENERWIDGET_H
