#include "Login.h"

QString Login::getPassword() const{
    return Password;
}

QString Login::getUsername() const{
    return Username;
}

Login::Login(const QString& usr, const QString& pwd):Username(usr),Password(pwd){}

void Login::setUsername(const QString& input_username){
    Username=input_username;
}

void Login::setPassword(const QString& input_password){
    Password=input_password;
}
