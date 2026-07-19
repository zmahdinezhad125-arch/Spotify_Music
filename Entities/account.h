#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>
enum class Role
{
    Artist,
    Listener
};

class Account
{
private:
    QString fullName;
    QString userName;
    QString biography;
    int iD;
    QString password;
    Role role;
    QString profileImagePath;
public:
    Account();
    Account(int id, const QString& fName, const QString& uName, const QString& password, const QString& bio, Role role);
    void setFullName(const QString& fName);
    void setUserName(const QString& uName);
    void setPassword(const QString& password);
    void setBiography(const QString& bio);
    void setProfileImagePath(const QString& Path);
    int getId() const;
    QString getFullName() const;
    QString getUsername() const;
    QString getPassword() const;
    QString getBiography() const;
    QString getProfileImagePath() const;
    Role getRole() const;
};

#endif // ACCOUNT_H
