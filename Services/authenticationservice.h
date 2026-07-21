#ifndef AUTHENTICATIONSERVICE_H
#define AUTHENTICATIONSERVICE_H

#include "../Repositories/artistrepository.h"
#include "../Repositories/listenerrepository.h"
#include <optional>

class AuthenticationService
{
private:
    static int nextAccountID;
    ArtistRepository& artistRepository;
    ListenerRepository& listenerRepository;

public:
    AuthenticationService(ArtistRepository& artistRepository, ListenerRepository& listenerRepository);

    bool registerArtist(const QString& fullName, const QString& userName, const QString& password, const QString& biography);

    bool registerListener(const QString& fullName, const QString& userName, const QString& password, const QString& biography);

    std::optional<Account> login(const QString& userName, const QString& password);
};

#endif // AUTHENTICATIONSERVICE_H
