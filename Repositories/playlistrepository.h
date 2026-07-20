#ifndef PLAYLISTREPOSITORY_H
#define PLAYLISTREPOSITORY_H

#include <QVector>
#include <optional>

#include "../Entities/playlist.h"
#include "AbstractRepository.h"
class PlaylistRepository : public AbstractRepository<Playlist>
{
private:
    QVector<Playlist> allPlaylists;
public:
    PlaylistRepository();
    int save(const Playlist& playlist) override;
    bool remove(int id) override;
    std::optional<Playlist> search(int id) override;
    bool insertSong(int playlistID, int songID);
    bool removeSong(int playlistID, int songID);
    QVector<Playlist> playlists(int listenerID);
};

#endif // PLAYLISTREPOSITORY_H
