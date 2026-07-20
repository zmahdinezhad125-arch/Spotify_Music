#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QString>
#include <QVector>
class Playlist
{
private:
    QString name;
    int listenerID;
    int playlistID;
    QVector<int> songIDs;
public:
    Playlist();
    Playlist(int pLID, const QString& name, int lID);
    void setName(const QString& name);
    QString getName()const;
    int getListenerID()const;
    int getPlaylistID()const;
    QVector <int> getSongIDs()const;
};

#endif // PLAYLIST_H
