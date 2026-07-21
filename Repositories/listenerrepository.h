#ifndef LISTENERREPOSITORY_H
#define LISTENERREPOSITORY_H

#include "AccountRepository.h"
#include <QVector>

class ListenerRepository: public AccountRepository
{
private:
    QVector<Account> allListeners;
public:
    ListenerRepository();
    int save(const Account& listener) override;
    bool remove(int id) override;
    std::optional<Account> search(int id) override;
    std::optional<Account> searchByUserName(const QString& username) override;
    bool updateLiked(int listenerID, int songID, bool liked);
    bool isLiked(int listenerID, int songID);
};

#endif // LISTENERREPOSITORY_H
