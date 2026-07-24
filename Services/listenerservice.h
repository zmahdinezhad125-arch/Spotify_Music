#ifndef LISTENERSERVICE_H
#define LISTENERSERVICE_H

#include "../Repositories/playlistrepository.h"
#include "../Repositories/songrepository.h"

class ListenerService
{
private:
    PlaylistRepository& playlistRepository;
    SongRepository& songRepository;
    static int nextPlaylistID;
public:
    ListenerService(PlaylistRepository& playlistRepository, SongRepository& songRepository);

    bool createPlaylist(const QString& name, int listenerID);

    bool deletePlaylist(int playlistID);

    bool editPlaylist(const  Playlist& playlist);

    bool addSongToPlaylist(int playlistID, int songID);

    bool removeSongFromPlaylist(int playlistID, int songID);

    bool likeSong(int listenerID, int songID);

    bool unlikeSong(int listenerID, int songID);
};

#endif // LISTENERSERVICE_H
