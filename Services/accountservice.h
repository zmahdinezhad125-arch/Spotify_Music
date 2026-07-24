#ifndef ACCOUNTSERVICE_H
#define ACCOUNTSERVICE_H

#include "../Repositories/artistrepository.h"
#include "../Repositories/listenerrepository.h"
class AccountService
{
private:
    ArtistRepository& artistRepository;
    ListenerRepository& listenerRepository;
public:
    AccountService(ArtistRepository& artistRepository, ListenerRepository& listenerRepository);
    bool editAccount(const Account& account);
    bool deleteAccount(int accountID, Role role);
};

#endif // ACCOUNTSERVICE_H
