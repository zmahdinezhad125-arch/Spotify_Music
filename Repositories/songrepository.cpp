#include "songrepository.h"

SongRepository::SongRepository() {}
int SongRepository::save(const Song& song)
{
    for(int i=0;i<songs.size();i++)
    {
        if(songs[i].getSongID()==song.getSongID())
        {
            songs[i]=song;
            return song.getSongID();
        }
    }
    songs.push_back(song);
    return song.getSongID();
}
bool SongRepository::remove(int id)
{
    for(int i=0;i<songs.size();i++)
    {
        if(songs[i].getSongID()==id)
        {
            songs.removeAt(i);
            return true;
        }
    }
    return false;
}
std::optional<Song> SongRepository::search(int id)
{
    for(int i=0;i<songs.size();i++)
    {
        if(songs[i].getSongID()==id)
        {
            return songs[i];
        }
    }
    return std::nullopt;
}
QVector<Song> SongRepository::singleSongs(int artistID)
{
    QVector<Song> result;
    for(int i=0;i<songs.size();i++)
    {
        if(songs[i].getAlbumID()==0 && songs[i].getArtistID()==artistID)
        {
            result.push_back(songs[i]);
        }
    }
    return result;
}
QVector<Song> SongRepository::getByAlbum(int albumID)
{
    QVector<Song> result;
    for(int i=0;i<songs.size();i++)
    {
        if(songs[i].getAlbumID()==albumID)
        {
            result.push_back(songs[i]);
        }
    }
    return result;
}
QVector<Song> SongRepository::getByArtist(int artistID)
{
    QVector<Song> result;
    for(int i=0;i<songs.size();i++)
    {
        if(songs[i].getArtistID()==artistID)
        {
            result.push_back(songs[i]);
        }
    }
    return result;
}