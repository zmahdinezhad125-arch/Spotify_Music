#include "songrepository.h"
#include <algorithm>

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

QVector<Song> SongRepository:: searchByName(const QString& name)
{
    QVector<Song> result;
    for(const Song& song : songs)
    {
        if(song.getName().contains(name, Qt::CaseInsensitive))
        {
            result.push_back(song);
        }
    }
    return result;
}

QVector<Song> SongRepository:: filterByGenre(Genre genre)
{
    QVector<Song> result;
    for(const Song& song : songs)
    {
        if(song.getGenre()==genre)
        {
            result.push_back(song);
        }
    }
    return result;
}

QVector<Song> SongRepository:: filterByYear(int year)
{
    QVector <Song> result;
    for(const Song& song : songs)
    {
        if(song.getReleaseYear()==year)
        {
            result.push_back(song);
        }
    }
    return result;
}
QVector<Song> SongRepository :: sortByName()
{
    QVector<Song> result =songs;
    std::sort(
        result.begin(),
        result.end(),
        [](const Song& a, const Song& b)
        {
          return a.getName()< b.getName();
        });
    return result;
}

QVector<Song> SongRepository:: sortByYear()
{
    QVector<Song> result =songs;
    std::sort(
        result.begin(),
        result.end(),
        [](const Song& a, const Song& b)
        {
            return a.getReleaseYear()< b.getReleaseYear();
        });
    return result;
}

QVector<Song> SongRepository::getByPlaylist(const Playlist& playlist)
{
    QVector<Song> result;
    QVector<int> ids = playlist.getSongIDs();
    for(int songID : ids)
    {
        auto song = search(songID);
        if(song.has_value())
        {
            result.push_back(*song);
        }
    }
    return result;
}