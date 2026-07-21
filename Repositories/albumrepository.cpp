#include "albumrepository.h"

AlbumRepository::AlbumRepository() {}
int AlbumRepository::save(const Album& album)
{
    for(int i=0;i<allAlbums.size();i++)
    {
        if(allAlbums[i].getAlbumID()==album.getAlbumID())
        {
            allAlbums[i]=album;
            return allAlbums[i].getAlbumID();
        }
    }
    allAlbums.push_back(album);
    return album.getAlbumID();
}
bool AlbumRepository::remove(int id)
{
    for(int i=0;i<allAlbums.size();i++)
    {
        if(allAlbums[i].getAlbumID()==id)
        {
            allAlbums.removeAt(i);
            return true;
        }
    }
    return false;
}
std::optional<Album> AlbumRepository::search(int id)
{
    for(int i=0;i<allAlbums.size();i++)
    {
        if(allAlbums[i].getAlbumID()==id)
        {
            return allAlbums[i];
        }
    }
    return std::nullopt;
}
QVector<Album> AlbumRepository::albums(int artistID)
{
    QVector<Album> result;
    for(int i=0;i<allAlbums.size();i++)
    {
        if(allAlbums[i].getArtistID()==artistID)
        {
            result.push_back(allAlbums[i]);
        }
    }
    return result;
}