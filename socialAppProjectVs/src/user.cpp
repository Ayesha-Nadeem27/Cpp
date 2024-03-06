#include "User.h"
#include <iostream>

User::User(const std::string& name,const std::string& password)
    : Entity(name), password(password) {}

void User::setUserName(const std::string& name)  {
    userName = name;
}

void User::setPassword(const std::string& pass) {
    password = pass;
}

std::string User::getUserName() const {
    return userName;
}

std::string User::getPassword() const {
    return password;
}

void User::displayDetails() const {
    std::cout << "Username: " << getUserName() << "\n";
    std::cout << "Password: " << getPassword() << "\n";
}
