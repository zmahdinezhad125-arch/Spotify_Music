#include "account.h"

Account::Account() {}
Account::Account(int id, const QString& fName, const QString& uName, const QString& password, const QString& bio, Role role)
{
    this->iD=id;
    this->fullName=fName;
    this->userName=uName;
    this->password=password;
    this->biography=bio;
    this->role=role;
    this->profileImagePath = "";
}
