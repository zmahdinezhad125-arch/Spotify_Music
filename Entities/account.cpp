#include "account.h"

Account::Account() {}
Account::Account(int id, const QString& fName, const QString& uName, const QString& password, const QString& bio, Role role, const QString& path)
{
    this->iD=id;
    this->fullName=fName;
    this->userName=uName;
    this->password=password;
    this->biography=bio;
    this->role=role;
    this->profileImagePath = path;
}
int Account::getId()const
{
    return this->iD;
}
QString Account::getFullName() const
{
    return this->fullName;
}
QString Account::getUsername() const
{
    return this->userName;
}
QString Account::getPassword() const
{
    return this->password;
}
QString Account::getProfileImagePath() const
{
    return this->profileImagePath;
}
Role Account::getRole() const
{
    return this->role;
}
void Account::setBiography(const QString& bio)
{
    this->biography=bio;
}
void Account::setFullName(const QString& fName)
{
    this->fullName=fName;
}
void Account::setUserName(const QString& uName)
{
    this->userName=uName;
}
void Account::setPassword(const QString& password)
{
    this->password=password;
}
void Account::setProfileImagePath(const QString& path)
{
    this->profileImagePath=path;
}