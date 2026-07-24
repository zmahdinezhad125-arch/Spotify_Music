#include "accountservice.h"

AccountService::AccountService(ArtistRepository& artistRepository, ListenerRepository& listenerRepository)
    :artistRepository(artistRepository), listenerRepository(listenerRepository)
{

}
bool AccountService:: editAccount(const Account& account)
{
    auto artist =artistRepository.searchByUserName(account.getUsername());
    if(artist.has_value() && artist->getId()!=account.getId())
    {
        return false;
    }
    auto listener =listenerRepository.searchByUserName(account.getUsername());
    if(listener.has_value() && listener->getId()!=account.getId())
    {
        return false;
    }
    if(account.getRole()==Role::Artist)
    {
        artistRepository.save(account);
        return true;
    }
    if(account.getRole()==Role::Listener)
    {
        listenerRepository.save(account);
        return true;
    }
    return false;
}
bool AccountService::deleteAccount(int accountID, Role role)
{
    if(role==Role::Artist)
    {
        return artistRepository.remove(accountID);
    }
    if(role==Role::Listener)
    {
        return listenerRepository.remove(accountID);
    }
    return false;
}