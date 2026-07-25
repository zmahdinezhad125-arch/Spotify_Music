#ifndef ARTISTWIDGET_H
#define ARTISTWIDGET_H

#include "../Entities/account.h"
#include "../Services/artistservice.h"

#include <QWidget>

namespace Ui {
class ArtistWidget;
}

class ArtistWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ArtistWidget(const Account& account, ArtistService* artistService, QWidget *parent = nullptr);
    ~ArtistWidget();

private:
    Ui::ArtistWidget *ui;
    Account account;
    ArtistService* artistService;
private slots:
    void onCreateAlbumClicked();
};

#endif // ARTISTWIDGET_H
