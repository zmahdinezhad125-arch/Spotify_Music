#ifndef ALBUMREPOSITORY_H
#define ALBUMREPOSITORY_H

#include <QVector>
#include <optional>

#include "../Entities/album.h"
#include "abstractrepository.h"
class AlbumRepository : public AbstractRepository<Album>
{
private:
    QVector<Album> allAlbums;
public:
    AlbumRepository();
    int save (const Album& album) override;
    bool remove(int id) override;
    std::optional<Album> search (int id) override;
    QVector<Album> albums(int artistID);
};

#endif // ALBUMREPOSITORY_H
