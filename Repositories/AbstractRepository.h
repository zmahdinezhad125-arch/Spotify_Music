#ifndef ABSTRACTREPOSITORY_H
#define ABSTRACTREPOSITORY_H

#include <optional>

template <typename T>
class AbstractRepository
{
public:
    virtual int save(const T& entity)=0;
    virtual bool remove(int id)=0;
    virtual std::optional<T> search(int id)=0;
    virtual ~AbstractRepository()=default;
};

#endif // ABSTRACTREPOSITORY_H
