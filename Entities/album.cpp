#include "album.h"

Album::Album()
{
    this->albumID=0;
    this->artistID=0;
}
Album::Album(int albumID, const QString& name, int artistID, const QString& path)
{
    this->albumID=albumID;
    this->name=name;
    this->artistID=artistID;
    this->coverPath=path;
}
int Album::getAlbumID()const
{
    return this->albumID;
}
QString Album::getName()const
{
    return this->name;
}
int Album::getArtistID()const
{
    return this->artistID;
}
QString Album::getCoverPath()const
{
    return this->coverPath;
}
void Album::setName(const QString& name)
{
    this->name=name;
}
void Album::setCoverPath(const QString& path)
{
    this->coverPath=path;
}