#include "song.h"

Song::Song() {}
Song::Song(int songID,
           const QString& name,
           int releaseYear,
           Genre genre,
           const QString& audioFilePath,
           int artistID,
           int albumID)
{
    this->songID=songID;
    this->name=name;
    this->releaseYear=releaseYear;
    this->genre=genre;
    this->audioFilePath=audioFilePath;
    this->artistID=artistID;
    this->albumID=albumID;
}
void Song::setName(const QString& name)
{
    this->name = name;
}

void Song::setReleaseYear(int releaseYear)
{
    this->releaseYear = releaseYear;
}

void Song::setGenre(Genre genre)
{
    this->genre = genre;
}

void Song::setAudioFilePath(const QString& audioFilePath)
{
    this->audioFilePath = audioFilePath;
}

void Song::setCoverPath(const QString& coverPath)
{
    this->coverPath = coverPath;
}

void Song::setAlbumID(int albumID)
{
    this->albumID = albumID;
}
QString Song::getName() const
{
    return name;
}

int Song::getReleaseYear() const
{
    return releaseYear;
}

Genre Song::getGenre() const
{
    return genre;
}

QString Song::getAudioFilePath() const
{
    return audioFilePath;
}

int Song::getArtistID() const
{
    return artistID;
}

int Song::getSongID() const
{
    return songID;
}

QString Song::getCoverPath() const
{
    return coverPath;
}

int Song::getAlbumID() const
{
    return albumID;
}
