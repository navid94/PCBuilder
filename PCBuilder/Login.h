#ifndef LOGIN_H
#define LOGIN_H

#include <QString>

class Login{
private:
    QString Username;
    QString Password;
public:
    Login(const QString&,const QString&);
    QString getUsername() const;
    QString getPassword() const;

    void setUsername(const QString&);
    void setPassword(const QString&);
};


#endif // LOGIN_H
