#include "playlistrepository.h"

PlaylistRepository::PlaylistRepository() {}
int PlaylistRepository::save(const Playlist& playlist)
{
    for(int i=0;i<allPlaylists.size();i++)
    {
        if(allPlaylists[i].getPlaylistID()==playlist.getPlaylistID())
        {
            allPlaylists[i]=playlist;
            return allPlaylists[i].getPlaylistID();
        }
    }
    allPlaylists.push_back(playlist);
    return playlist.getPlaylistID();
}
bool PlaylistRepository::remove(int id)
{
    for(int i=0;i<allPlaylists.size();i++)
    {
        if(allPlaylists[i].getPlaylistID()==id)
        {
            allPlaylists.removeAt(i);
            return true;
        }
    }
    return false;
}
std::optional<Playlist> PlaylistRepository::search(int id)
{
    for(int i=0;i<allPlaylists.size();i++)
    {
        if(allPlaylists[i].getPlaylistID()==id)
        {
            return allPlaylists[i];
        }
    }
    return std::nullopt;
}
bool PlaylistRepository::insertSong(int playlistID, int songID)
{
    for(int i=0;i<allPlaylists.size();i++)
    {
        if(allPlaylists[i].getPlaylistID()==playlistID)
        {
            QVector<int> ids=allPlaylists[i].getSongIDs();
            ids.push_back(songID);
            allPlaylists[i].setSongIDs(ids);
            return true;
        }
    }
    return false;
}
bool PlaylistRepository::removeSong(int playlistID, int songID)
{
    for(int i=0;i<allPlaylists.size();i++)
    {
        if(allPlaylists[i].getPlaylistID()==playlistID)
        {
            QVector<int> ids=allPlaylists[i].getSongIDs();
            for(int j=0;j<ids.size();j++)
            {
                if(ids[j]==songID)
                {
                    ids.removeAt(j);
                    allPlaylists[i].setSongIDs(ids);
                    return true;
                }
            }
            return false;
        }
    }
    return false;
}
QVector<Playlist> PlaylistRepository::playlists(int listenerID)
{
    QVector<Playlist> result;
    for(int i=0;i<allPlaylists.size();i++)
    {
        if(allPlaylists[i].getListenerID()==listenerID)
        {
            result.push_back(allPlaylists[i]);
        }
    }
    return result;
}