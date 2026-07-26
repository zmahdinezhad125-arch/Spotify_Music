#include "artistservice.h"

int ArtistService::nextAlbumID=1;
int ArtistService::nextSongID=1;

ArtistService::ArtistService(AlbumRepository& albumRepository, SongRepository& songRepository)
    : albumRepository(albumRepository), songRepository(songRepository)
{

}

bool ArtistService::createAlbum(int artistID, const QString& name, const QString& coverPath)
{
    Album album(nextAlbumID++, name, artistID, coverPath);
    albumRepository.save(album);
    return true;
}

bool ArtistService::createSong(const QString& name, int releaseYear, Genre genre, const QString& audioFilePath, int artistID, const QString& coverPath, int albumID)
{
    Song song(nextSongID++,
              name,
              releaseYear,
              genre,
              audioFilePath,
              artistID,
              coverPath,
              albumID);
    songRepository.save(song);
    return true;
}

bool ArtistService:: editAlbum(const Album& album)
{
    if(!albumRepository.search(album.getAlbumID()).has_value())
    {
        return false;
    }
    albumRepository.save(album);
    return true;
}

bool ArtistService:: editSong (const Song& song)
{
    if(!songRepository.search(song.getSongID()).has_value())
    {
        return false;
    }
    songRepository.save(song);
    return true;
}

bool ArtistService::deleteAlbum(int albumID)
{
    QVector<Song> songs=songRepository.getByAlbum((albumID));
    for(const Song& song : songs)
    {
        songRepository.remove(song.getSongID());
    }
    return albumRepository.remove(albumID);
}

bool ArtistService::deleteSong(int songID)
{
    return songRepository.remove(songID);
}

QVector<Album> ArtistService::getAlbums(
    int artistID)
{
    return albumRepository.albums(artistID);
}

QVector<Song> ArtistService::getSongs(int artistID)
{
    return songRepository.getByArtist(artistID);
}
QVector<Song> ArtistService::getSongsByAlbum(int albumID)
{
    return songRepository.getByAlbum(albumID);
}

QVector<Song> ArtistService::getSingles(int artistID)
{
    QVector<Song> result;

    QVector<Song> songs = songRepository.getByArtist(artistID);

    for(const Song& song : songs)
    {
        if(song.getAlbumID() == 0)
        {
            result.push_back(song);
        }
    }

    return result;
}