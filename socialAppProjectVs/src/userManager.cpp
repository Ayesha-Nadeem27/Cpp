#include "userManager.h"

#include <fstream>
#include <iostream>
#include <algorithm>

//CONSTRUCTOR
UserManager::UserManager () { 
    try {
        loadUsers();
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
};

//METHODS
std::vector<User>& UserManager::getUsers() {
    return users;
}

//FILE-HANDLIING METHODS
void UserManager::loadUsers() {
    std::ifstream userFile("users.txt");
    if (!userFile.is_open()) {
        throw std::runtime_error("Error loading users");
    } else {
        std::string line;
        while (std::getline(userFile, line)) {
            size_t pos = line.find(",");
            if (pos != std::string::npos) {
                std::string userName = line.substr(0, pos);
                std::string password = line.substr(pos + 1);

                User user(userName, password);
                if (userName != "admin" && !userExists(userName)) { // Check for duplicates
                    users.push_back(user);
                }
            }
        }
    }
    userFile.close();
}

void UserManager::saveUsers() {
    std::ofstream usersFile("users.txt");
    if (usersFile.is_open()) {
        for (const auto& user : users) {
            if (!userExistsInFile(user.getUserName())) {
                usersFile << user.getUserName() << "," << user.getPassword() << '\n';
            } else {
                std::cerr << "User with username '" << user.getUserName() << "' already exists in the file!" << std::endl;
            }
        }
        usersFile.close();
    } else {
        std::cerr << "Error opening users file for writing." << std::endl;
    }
}

// void UserManager::saveUsers() {
//     std::ofstream usersFile("users.txt");
//     if(usersFile.is_open()) {
//         for (const auto& user : users) {
//             usersFile << user.getUserName() <<"," << user.getPassword() <<'\n';
//     }
//     usersFile.close();
//     }
// }
bool UserManager::userExistsInFile(const std::string& username) const {
    std::ifstream usersFile("users.txt");
    if (usersFile.is_open()) {
        std::string line;
        while (std::getline(usersFile, line)) {
            size_t pos = line.find(",");
            if (pos != std::string::npos) {
                std::string userNameInFile = line.substr(0, pos);
                if (userNameInFile == username) {
                    usersFile.close();
                    return true;
                }
            }
        }
        usersFile.close();
    } else {
        std::cerr << "Error opening users file for reading." << std::endl;
    }
    return false;
}

//----------------------------------------------------------------

bool UserManager::authenticateUser(const std::string& userName, const std::string& password) const {
    auto it = std::find_if(users.begin(), users.end(),
                            [&](const User& user) {return user.getUserName() == userName && user.getPassword() == password; });
    return it != users.end();
}
// bool UserManager::authenticateUser(const std::string& userName, const std::string& password) const {
//     for (auto it = users.begin(); it != users.end(); ++it) {
//         if (it->getUserName() == userName && it->getPassword() == password) {
//             return true;
//         }
//     }
//     return false;
//}


bool UserManager::userExists(const std::string& userNm) const {
    return std::any_of(users.begin(), users.end(),
                        [&](const User& user) { return user.getUserName() == userNm; });
}
// bool UserManager::userExists(const std::string& userNm) const {
//     for (auto it = users.begin(); it != users.end(); ++it) {
//         if (it->getUserName() == userNm) {
//             return true;
//         }
//     }
//     return false;
// }
// void UserManager::addUser(const User& newUser) {
//     const std::string& newUserName = newUser.getUserName();

void UserManager::addUser(const User& newUser) {
    if(!userExists(newUser.getUserName())) {
        users.push_back(newUser);
        saveUsers();
    } else { std::cerr << "user already Exists!!" << std::endl; }
}
//     if (!userExists(newUserName)) {
//         users.push_back(newUser);
//         saveUsers();
//     } else {
//         std::cerr << "User with username '" << newUserName << "' already exists!" << std::endl;

//         std::string alternativeUsername;
//         std::cout << "Please enter a different username: ";
//         std::cin >> alternativeUsername;

//         User alternativeUser(alternativeUsername, newUser.getPassword());
//         addUser(alternativeUser);
//     }
// }

//----------------------------------------------------------------
//DISPLAY USERS
void UserManager::displayUsers() {
    for (auto& user : users) {
        user.displayDetails();
        std::cout << std::endl;
    }
}