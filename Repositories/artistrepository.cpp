#include "artistrepository.h"

ArtistRepository::ArtistRepository() {}
int ArtistRepository::save(const Account& artist)
{
    for(int i=0;i<allArtists.size();i++)
    {
        if (allArtists[i].getId() == artist.getId())
        {
            allArtists[i] = artist;
            return artist.getId();
        }
    }
    allArtists.push_back(artist);
    return artist.getId();
}

bool ArtistRepository::remove(int id)
{
    for(int i=0;i<allArtists.size();i++)
    {
        if (allArtists[i].getId() == id)
        {
            allArtists.removeAt(i);
            return true;
        }
    }
    return false;
}

std::optional<Account> ArtistRepository::search(int id)
{
    for(int i=0;i<allArtists.size();i++)
    {
        if (allArtists[i].getId() == id)
        {
            return allArtists[i];
        }
    }
    return std::nullopt;
}
std::optional<Account> ArtistRepository::searchByUserName(const QString& username)
{
    for(int i=0;i<allArtists.size();i++)
    {
        if(allArtists[i].getUsername()==username)
        {
            return allArtists[i];
        }
    }
    return std::nullopt;
}