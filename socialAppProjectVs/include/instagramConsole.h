// InstagramConsole.h

#ifndef INSTAGRAM_CONSOLE_H
#define INSTAGRAM_CONSOLE_H

#include "UserManager.h"
#include "PostManager.h"
#include "Admin.h"

class InstagramConsole {
private:
    UserManager userManager;
    PostManager postManager;
    Admin admin;
    User currentUser;  // Added member variable to store the current user

public:
    InstagramConsole();

    // Load and save functions
    void loadUsers();
    void saveUsers();
    void loadPosts();
    void savePosts();

    // Menu-related functions
    void showMenu();
    void processChoice(char choice);
    void adminOptions();
    void deleteUsers();
    void postMessage();
    void searchPost(const std::string& searchTerm);

    // Functionality-related functions
    void runInstagramFunctionality();
    void loginOrSignup();
    void login();
    void signup();
    void run();

    std::string validateUserName(const std::string& userName );
 //   std::string validatePassword (const std::string& password);


private:
    // Helper functions to manage the current user
    void setCurrentUser(const User& user);
    const User& getCurrentUser() const;
};

#endif // INSTAGRAM_CONSOLE_H
