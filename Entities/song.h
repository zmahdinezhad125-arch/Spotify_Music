#ifndef SONG_H
#define SONG_H
#include <QString>

enum class Genre
{
    Pop,
    Rock,
    Classical,
    Jazz,
    Rap,
    Traditional
};
class Song
{
private:
    QString name;
    int releaseYear;
    Genre genre;
    QString audioFilePath;
    int artistID;
    int songID;
    QString coverPath;
    int albumID;
public:
    Song();
    Song(int songID,
         const QString& name,
         int releaseYear,
         Genre genre,
         const QString& audioFilePath,
         int artistID,
         const QString& coverPath,
         int albumID=0);
    void setName(const QString& name);
    void setReleaseYear(int releaseYear);
    void setGenre(Genre genre);
    void setAudioFilePath(const QString& audioFilePath);
    void setCoverPath(const QString& coverPath);
    void setAlbumID(int albumID);
    QString getName() const;
    int getReleaseYear() const;
    Genre getGenre() const;
    QString getAudioFilePath() const;
    int getArtistID() const;
    int getSongID() const;
    QString getCoverPath() const;
    int getAlbumID() const;
};

#endif // SONG_H
