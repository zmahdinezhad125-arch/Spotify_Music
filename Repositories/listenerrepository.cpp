#include "listenerrepository.h"

ListenerRepository::ListenerRepository() {}

int ListenerRepository::save(const Account& listener)
{
    for(int i=0;i<allListeners.size();i++)
    {
        if (allListeners[i].getId() == listener.getId())
        {
            allListeners[i] = listener;
            return listener.getId();
        }
    }
    allListeners.push_back(listener);
    return listener.getId();
}

bool ListenerRepository::remove(int id)
{
    for(int i=0;i<allListeners.size();i++)
    {
        if (allListeners[i].getId() == id)
        {
            allListeners.removeAt(i);
            return true;
        }
    }
    return false;
}

std::optional<Account> ListenerRepository::search(int id)
{
    for(int i=0;i<allListeners.size();i++)
    {
        if (allListeners[i].getId() == id)
        {
            return allListeners[i];
        }
    }
    return std::nullopt;
}

std::optional<Account> ListenerRepository::searchByUserName(const QString& username)
{
    for(int i=0;i<allListeners.size();i++)
    {
        if(allListeners[i].getUsername()==username)
        {
            return allListeners[i];
        }
    }
    return std::nullopt;
}

bool ListenerRepository::updateLiked(int listenerID, int songID, bool liked)
{
    return false;
}

bool ListenerRepository::isLiked(int listenerID, int songID)
{
    return false;
}