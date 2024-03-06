#include "InstagramConsole.h"
#include <iostream>
#include <string>

using namespace std;

InstagramConsole::InstagramConsole() : userManager(), postManager(), admin(),currentUser("defaultUser", "defaultPassword") { 
    loadUsers();  
    if (!userManager.authenticateUser("admin", "123")) {
        userManager.addUser(User("admin", "123"));
        saveUsers(); 
    }
}

void InstagramConsole::setCurrentUser(const User& user) {
    currentUser = user;
}
const User& InstagramConsole::getCurrentUser() const {
    return currentUser;
}

void InstagramConsole::loadUsers() {
    userManager.loadUsers();
}

void InstagramConsole::saveUsers() {
    userManager.saveUsers();
}

void InstagramConsole::loadPosts() {
    postManager.loadPosts();
}

void InstagramConsole::savePosts() {
    postManager.savePosts();
}

void InstagramConsole::searchPost(const std::string& searchTerm) {
    postManager.searchPost(searchTerm, currentUser.getUserName()); // Passing the username
}


void InstagramConsole::showMenu() {
    cout << "\n======= Instagram Console =======\n";
    cout << "1. View Posts\n";
    cout << "2. Post a Message\n";
    cout << "3. Logout (and Save)\n";
    cout << "4. Clear Posts\n"; 
    cout << "5. Search Posts\n";
    cout << "6. Admin Options\n";  //only for admin
    cout << "q. Quit without Saving\n";
}

void InstagramConsole::processChoice(char choice) {
    string searchTerm;
    switch (choice) {
        case '1':
            postManager.viewPosts();
            break;
        case '2':
            cout << "\n";
            postMessage();
            break;
        case '3':
            saveUsers();
            savePosts();
            cout << "Data saved. Logging out.\n\n";
            break;
        case '4':
            postManager.clearPosts();  
            cout << "Posts cleared.\n";
            break;

        case '5':
            cout << "Enter search term: ";
            cin.ignore();
            getline(cin, searchTerm);
            postManager.searchPost(searchTerm, currentUser.getUserName());
            break;
        case '6':
            if (admin.authenticateAdmin(currentUser.getUserName(), currentUser.getPassword())) {
                adminOptions();
            } else {
                cout << "Authentication failed. Admin username or password is incorrect.\n";
            }
            break;
        case 'q':
            postManager.clearPosts();
            cout << "Exiting without saving.\n\n";
            postManager.loadPosts();
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
    }
}

void InstagramConsole::adminOptions() {
    char adminChoice;
    do {
        cout << "\n======= Admin Options =======\n";
        cout << "1. View Users\n";
        cout << "2. Delete User\n";
        cout << "3. Go Back\n";
        cout << "Enter your choice: ";
        cin >> adminChoice;

        switch (adminChoice) {
            case '1':
                admin.viewUsers(userManager.getUsers());
                break;
            case '2':
                deleteUsers();
                break;
            case '3':
                cin.ignore();
                cout << "Going back to the main menu.\n";
                return;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (true);
}

void InstagramConsole::deleteUsers() {
    string userName;
    
    cout << "Enter the user name you want to delete: ";
    cin >> userName;

    if (userName == admin.getUserName()){
        cerr << "Admin can not delete itself!.\n";
        adminOptions();
        return;  
    }
    else {
        if (admin.deleteUser(userManager.getUsers() , userName)) {
            cout << "user '" << userName << "' deleted successfully.\n";
        } else {
            cout << "User not found or admin privileges required. Deletion failed.\n";
        }
    }
}

void InstagramConsole::postMessage() {
    string content;
    cin.ignore();
    cout << "Enter your message: ";
    getline(cin, content);

    Post newPost{currentUser.getUserName(), content};
    postManager.postMessage(newPost);
}

void InstagramConsole::runInstagramFunctionality() {
    char choice;
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            processChoice(choice);
        } catch (const AdminException& e) {
            cout << "Error: " << e.what() << endl;
            continue; 
        }

        if (choice == '3' || choice == 'q') {
            break;
        }
    } while (true);
}


void InstagramConsole::loginOrSignup() {
    char choice;
    do {
        cout << "======= Login or Signup =======\n";
        cout << "1. Login\n";
        cout << "2. Signup\n";
        cout << "q. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                login();
                break;
            case '2':
                signup();
                break;
            case 'q':
                cout << "Exiting.\n";
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (true);
}

void InstagramConsole::login() {
    string username, password;
    cout << "Enter your username: ";
    //clearing buffer
    cin.ignore();

    getline(cin, username);

    string validationMessage = validateUserName(username);
    if (!validationMessage.empty()) {
        cout << validationMessage;
        return;
    }

    cout << "Enter your password: ";
    cin >> password;


    if (userManager.authenticateUser(username, password)) {
        cout << "Authentication successful. Welcome, " << username << "!\n";
        currentUser.setUserName(username);
        currentUser.setPassword(password);
        runInstagramFunctionality(); 
    } else {
        cout << "Authentication failed. Username or password is incorrect.\n";
        loginOrSignup();
    }
}

std::string InstagramConsole::validateUserName (const std::string& userName) {
    if (userName.empty()) {
        return "Invalid! Username cannot be empty.\n";
    }

    if (userName.find(' ') != string::npos) {
        return "Invalid! Username cannot contain space.\n";
    }
    return "";
}


void InstagramConsole::signup() {
    string username, password;
    cin.ignore();
    cout << "Enter a new username: ";
    getline(cin, username);

    string validationMessage = validateUserName(username);
    if (!validationMessage.empty()) {
        cout << validationMessage;
        return;
    }

    if (userManager.userExists(username)) {
        cout << "Username already exists. Please choose a different username.\n";
        return;
    }

    cout << "Enter a password: ";
    cin >> password;

    User newUser{username, password};
    userManager.addUser(newUser);
    cout << "Signup successful. Welcome, " << username << "!\n";

    currentUser.setUserName(username);
    currentUser.setPassword(password);

    runInstagramFunctionality();
}


void InstagramConsole::run() {
    cout << "======= Welcome to Instagram Console =======\n";
    loginOrSignup();
}
