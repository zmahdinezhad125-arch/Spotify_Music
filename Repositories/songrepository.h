#ifndef SONGREPOSITORY_H
#define SONGREPOSITORY_H


#include <QVector>
#include <optional>

#include"../Entities/song.h"
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
    QVector<Song> getByPlaylist(int playlistID);
    QVector<Song> getByLikedSongs(int listenerID);
};

#endif // SONGREPOSITORY_H
