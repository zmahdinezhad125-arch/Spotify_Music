#include "listenerwidget.h"
#include "ui_listenerwidget.h"

ListenerWidget::ListenerWidget(const Account& account, ListenerService* listenerService, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ListenerWidget)
    , account(account)
{
    ui->setupUi(this);
    ui->welcomeLabel->setText("Welcome " + account.getFullName());
}

ListenerWidget::~ListenerWidget()
{
    delete ui;
}
