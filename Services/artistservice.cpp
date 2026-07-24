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