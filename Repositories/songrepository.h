#ifndef SONGREPOSITORY_H
#define SONGREPOSITORY_H


#include <QVector>
#include <optional>

#include"../Entities/song.h"
#include"../Entities/playlist.h"
#include"AbstractRepository.h"

class SongRepository : public AbstractRepository<Song>
{
private:
    QVector<Song>songs;

public:
    SongRepository();
    int save(const Song& song) override;
    bool remove(int id) override;
    std::optional<Song> search(int id) override;
    QVector<Song> singleSongs(int artistID);
    QVector<Song> getByAlbum(int albumID);
    QVector<Song> getByArtist(int artistID);
    QVector<Song> getByPlaylist(const Playlist& playlist);
    QVector<Song> getByLikedSongs(int listenerID);
    QVector<Song> searchByName(const QString& name);
    QVector<Song> filterByGenre(Genre genre);
    QVector<Song> filterByYear(int year);
    QVector<Song> sortByName();
    QVector<Song> sortByYear();
};

#endif // SONGREPOSITORY_H
