#ifndef ACCOUNTREPOSITORY_H
#define ACCOUNTREPOSITORY_H

#include "abstractrepository.h"
#include "../Entities/account.h"

class AccountRepository : public AbstractRepository<Account>
{
public:
    virtual std::optional<Account> searchByUserName(const QString& username)=0;
    virtual ~AccountRepository() = default;
};
#endif // ACCOUNTREPOSITORY_H
