// main.cpp
#include "user.h"
#include "post.h"
#include "admin.h"
#include "userManager.h"
#include "postManager.h"
#include "instagramConsole.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {
    InstagramConsole instagram;

    instagram.run();

    return 0;   
}
  // // Create a PostManager object
    // PostManager postManager;

    // // Add some posts (you can modify this as needed)
    // Post newPost1("User1", "Hello, world!");
    // Post newPost2("User2", "Testing postManager class.");
    // Post newPost3("User3", "This is another post.");

    // // Add the posts to the manager
    // postManager.postMessage(newPost1);
    // postManager.postMessage(newPost2);
    // postManager.postMessage(newPost3);

    // // View all posts
    // postManager.viewPosts();
//----------------------------------------------------------------
 //  // Create a UserManager object
    // UserManager userManager;

    // // Add some users
    // cout << "Adding users..." << endl;
    // // userManager.addUser(User("Alice", "password1"));
    // // userManager.addUser(User("Bob", "password2"));
    // // userManager.addUser(User("Charlie", "password3"));
    // userManager.addUser(User("Harry", "password4"));
    // userManager.addUser(User("Ron", "password5"));
    // userManager.addUser(User("Doe", "password6"));
    // cout << endl;
 
    // // Save the users to a file
    // // userManager.saveUsers();

    // // Load the users from the file
    // cout << "Loading users..." << endl;
    // userManager.loadUsers();

    // cout << "users Displayed directly through vectors after load..." << endl;
    // userManager.displayUsers();

    // // Check if a user exists
    // if (userManager.userExists("Alice")) {
    //     cout << "User Alice exists.\n";
    // } else {
    //     cout << "User Alice does not exist.\n";
    // }

    // // Authenticate a user
    // if (userManager.authenticateUser("Bob", "password2")) {
    //     cout << "User Bob authenticated successfully.\n";
    // } else {
    //     cout << "Failed to authenticate user Bob.\n";
    // }

    // return 0;
//----------------------------------------------------------------
    // User user1("harry", "123");
    // User user2("ron", "456");
    // User user3("hermione", "789");
    // Post post("Harry", "testing post");

    // // Add the users to a vector
    // vector<User> users = {user1, user2, user3};

    // // Create an Admin object
    // Admin admin("dumbledore", "admin123");

    // // Use the Admin object to view the users
    // admin.viewUsers(users);

    // // Use the Admin object to delete a user
    // bool deleted = admin.deleteUser(users, "ron");

    // if (deleted) {
    //     cout << "\nUser deleted successfully.\n";
    // } else {
    //     cout << "\nUser not found.\n";
    // }

    // // View the users again to confirm the deletion
    // admin.viewUsers(users);
    
    // post.displayDetails();

    // return 0;
