#ifndef ALBUM_H
#define ALBUM_H

#include<QString>
#include<QVector>
class Album
{
private:
    int albumID;
    QString name;
    int artistID;
    QString coverPath;
public:
    Album();
    Album(int albumID, const QString& name, int artistID, const QString& path);
    int getAlbumID()const;
    QString getName()const;
    int getArtistID()const;
    QString getCoverPath()const;
    void setName(const QString& name);
    void setCoverPath(const QString& path);
};

#endif // ALBUM_H
