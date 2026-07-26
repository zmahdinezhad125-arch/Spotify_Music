#ifndef ARTISTSERVICE_H
#define ARTISTSERVICE_H

#include"../Repositories/albumrepository.h"
#include"../Repositories/songrepository.h"

class ArtistService
{
private:
    static int nextAlbumID;
    static int nextSongID;
    AlbumRepository& albumRepository;
    SongRepository& songRepository;

public:
    ArtistService(AlbumRepository& albumRepository, SongRepository& songRepository);

    bool createAlbum(int artistID, const QString& name, const QString& coverPath);

    bool createSong(const QString& name, int releaseYear, Genre genre, const QString& audioFilePath, int artistID, const QString& coverPath, int albumID);

    bool editAlbum(const Album& album);

    bool editSong(const Song& song);

    bool deleteAlbum(int albumID);

    bool deleteSong(int songID);

    QVector<Album> getAlbums(int artistID);

    QVector<Song> getSongs(int artistID);

    QVector<Song> getSongsByAlbum(int albumID);

    QVector<Song> getSingles(int artistID);
};

#endif // ARTISTSERVICE_H
