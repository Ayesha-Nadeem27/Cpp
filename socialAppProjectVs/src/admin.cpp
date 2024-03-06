#include "admin.h"
#include <iostream>

//CONSTRUCTOR--parameterized/non-parameterized
Admin::Admin(const std::string& admn, const std::string& adps)
            :Entity(admn), adminUserName(admn), adminPassword(adps) {}

Admin::Admin() 
            :Entity("admin"), adminUserName("admin"), adminPassword("123") {}

//GETTER/SETTER
std::string Admin::getAdminUserName() const {
    return adminUserName;
}
std::string Admin::getAdminPassword() const {
    return adminPassword;
}

//METHODS   
bool Admin::authenticateAdmin(const std::string& adminUserName, const std::string& adminPassword) const {
        if (adminUserName == this->adminUserName && adminPassword == this->adminPassword) {
            return true;
        } else {
            throw AdminException("Authentication failed! Admin username or password is incorrect.");
        }
}

void Admin::viewUsers(const std::vector<User>& users) const {
    std::cout << "\n======= User List =======\n";
    for (const auto& user : users) {
        std::cout << "Username: " << user.getUserName() << "\n";
    }
}

bool Admin::deleteUser(std::vector<User>& users, const std::string& userName)  {
    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->getUserName() == userName) {
            users.erase(it);
            return true;
        }
    }
    throw AdminException("Deletion Failed! User not found or Administrators privileges required.");
    return false;
}

//if(user& tmpUser: users) second if which can be used for iteration

//overrides
std::string Admin::getUserName() const {
    return adminUserName;
}

void Admin::displayDetails() const {
    std::cout << "Admin Username: " << getAdminUserName() << "\n";
    std::cout << "Admin Password: " << getAdminPassword() << "\n";
}
