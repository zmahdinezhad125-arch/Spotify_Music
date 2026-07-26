#include "authenticationservice.h"
#include <stdexcept>
int AuthenticationService::nextAccountID = 1;

AuthenticationService::AuthenticationService(ArtistRepository& artistRepository, ListenerRepository& listenerRepository)
: artistRepository(artistRepository),listenerRepository(listenerRepository)
{
}

bool AuthenticationService::registerArtist(const QString& fullName, const QString& userName, const QString& password, const QString& biography)
{
    if(fullName.trimmed().isEmpty())
    {
        throw std::runtime_error(
            "Full name is empty");
    }

    if(userName.trimmed().isEmpty())
    {
        throw std::runtime_error(
            "Username is empty");
    }

    if(password.trimmed().isEmpty())
    {
        throw std::runtime_error(
            "Password is empty");
    }
    if(artistRepository.searchByUserName(userName).has_value() || listenerRepository.searchByUserName(userName).has_value())
    {
        throw std::runtime_error("Username already exists");
    }
    Account newArtist(nextAccountID++, fullName, userName, password, biography, Role::Artist, "");
    artistRepository.save(newArtist);
    return true;
}

bool AuthenticationService::registerListener(const QString& fullName, const QString& userName, const QString& password, const QString& biography)
{
    if(fullName.trimmed().isEmpty())
    {
        throw std::runtime_error(
            "Full name is empty");
    }

    if(userName.trimmed().isEmpty())
    {
        throw std::runtime_error(
            "Username is empty");
    }

    if(password.trimmed().isEmpty())
    {
        throw std::runtime_error(
            "Password is empty");
    }
    if(artistRepository.searchByUserName(userName).has_value() || listenerRepository.searchByUserName(userName).has_value())
    {
        throw std::runtime_error("Username already exists");
    }
    Account newListener(nextAccountID++, fullName, userName, password, biography, Role::Listener, "");
    listenerRepository.save(newListener);
    return true;
}

std::optional<Account> AuthenticationService::login(const QString& userName, const QString& password)
{
    if(userName.trimmed().isEmpty())
    {
        throw std::runtime_error("Username is empty");
    }
    if(password.trimmed().isEmpty())
    {
        throw std::runtime_error("Password is empty");
    }
    auto artist= artistRepository.searchByUserName(userName);
    if(artist.has_value())
    {
        if(artist->getPassword()==password)
        {
            return artist;
        }
        return std::nullopt;
    }
    auto listener =listenerRepository.searchByUserName(userName);
    if(listener.has_value())
    {
        if(listener->getPassword()==password)
        {
            return listener;
        }
        return std::nullopt;
    }
    return std::nullopt;
}