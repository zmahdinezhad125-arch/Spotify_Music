#ifndef ARTISTREPOSITORY_H
#define ARTISTREPOSITORY_H

#include "AccountRepository.h"
#include <QVector>

class ArtistRepository : public AccountRepository
{
private:
    QVector<Account> allArtists;
public:
    ArtistRepository();
    int save(const Account& artist) override;
    bool remove(int id) override;
    std::optional<Account> search(int id) override;
    std::optional<Account> searchByUserName(const QString& username) override;

};

#endif // ARTISTREPOSITORY_H
