#include "playlist.h"

Playlist::Playlist()
{
    this->playlistID=0;
    this->listenerID=0;
}
Playlist::Playlist(int pLID, const QString& name, int lID)
{
    this->playlistID=pLID;
    this->name=name;
    this->listenerID=lID;
}
int Playlist::getPlaylistID()const
{
    return this->playlistID;
}
QString Playlist::getName()const
{
    return this->name;
}
int Playlist::getListenerID()const
{
    return this->listenerID;
}
QVector<int> Playlist::getSongIDs()const
{
    return this->songIDs;
}
void Playlist::setName(const QString& name)
{
    this->name=name;
}