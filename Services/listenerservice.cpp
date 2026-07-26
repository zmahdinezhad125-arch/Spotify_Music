#include "listenerservice.h"

int ListenerService:: nextPlaylistID = 1;
ListenerService:: ListenerService(PlaylistRepository& playlistRepository, SongRepository& songRepository)
    : playlistRepository(playlistRepository), songRepository(songRepository)
{

}

bool ListenerService::createPlaylist(const QString& name, int listenerID)
{
    Playlist playlist(nextPlaylistID++, name, listenerID);
    playlistRepository.save(playlist);
    return true;
}

bool ListenerService:: deletePlaylist(int playlistID)
{
    return playlistRepository.remove(playlistID);
}

bool ListenerService:: editPlaylist(const  Playlist& playlist)
{
    if(!playlistRepository.search(playlist.getPlaylistID()).has_value())
    {
        return false;
    }
    playlistRepository.save(playlist);
    return true;
}

bool ListenerService:: addSongToPlaylist(int playlistID, int songID)
{
    auto playlist = playlistRepository.search(playlistID);
    if(!playlist.has_value())
    {
        return false;
    }

    if(!songRepository.search(songID).has_value())
    {
        return false;
    }
    QVector <int> ids =playlist->getSongIDs();
    if(ids.contains(songID))
    {
        return false;
    }
    ids.push_back(songID);
    playlist->setSongIDs(ids);
    playlistRepository.save(*playlist);
    return true;
}

bool ListenerService:: removeSongFromPlaylist(int playlistID, int songID)
{
    auto playlist = playlistRepository.search(playlistID);
    if(!playlist.has_value())
    {
        return false;
    }
    QVector <int> ids =playlist->getSongIDs();
    for(int i=0;i<ids.size();i++)
    {
        if(ids[i]==songID)
        {
            ids.removeAt(i);
            playlist->setSongIDs(ids);
            playlistRepository.save(*playlist);
            return true;
        }
    }
    return false;

}

bool ListenerService:: likeSong(int listenerID, int songID)
{
    auto playlists = playlistRepository.playlists(listenerID);
    for(const Playlist& playlist : std::as_const(playlists))
    {
        if(playlist.getName()=="Favorite Songs")
        {
            return addSongToPlaylist(playlist.getPlaylistID(), songID);

        }
    }
    createPlaylist("Favorite Songs", listenerID);
    playlists = playlistRepository.playlists(listenerID);
    for(const Playlist& playlist : std::as_const(playlists))
    {
        if(playlist.getName()=="Favorite Songs")
        {
            return addSongToPlaylist(playlist.getPlaylistID(), songID);

        }
    }
    return false;
}

bool ListenerService:: unlikeSong(int listenerID, int songID)
{
    auto playlists = playlistRepository.playlists(listenerID);
    for(const Playlist& playlist : std::as_const(playlists))
    {
        if(playlist.getName()=="Favorite Songs")
        {
            return removeSongFromPlaylist(playlist.getPlaylistID(), songID);

        }
    }
    return false;
}

QVector<Playlist> ListenerService::getPlaylists(int listenerID)
{
    return playlistRepository.playlists(
        listenerID);
}

QVector<Song> ListenerService::getSongs()
{
    return songRepository.sortByName();
}

QVector<Song> ListenerService::getPlaylistSongs(int playlistID)
{
    auto playlist = playlistRepository.search(playlistID);
    if(!playlist.has_value())
    {
        return {};
    }
    return songRepository.getByPlaylist(*playlist);
}

QVector<Song> ListenerService::searchSongs(const QString& name)
{
    return songRepository.searchByName(name);
}

QVector<Song> ListenerService::filterSongsByGenre(
    Genre genre)
{
    return songRepository.filterByGenre(genre);
}

QVector<Song> ListenerService::filterSongsByYear(
    int year)
{
    return songRepository.filterByYear(year);
}