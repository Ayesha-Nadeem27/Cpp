#include "postManager.h"

#include <fstream>
#include <iostream>
#include <algorithm>

//CONSTRUCTOR
PostManager::PostManager () { 
    try {
        loadPosts();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
};

//FILE-HANDLING
void PostManager::loadPosts () {
    std::ifstream postsFile("posts.txt");
    if (postsFile.is_open()) {
        std::string line;
        while (std::getline(postsFile >> std::ws , line)) {
            size_t pos = line.find(",");
            if (pos != std::string::npos) {
                std::string userName = line.substr(0,pos);
                std::string content = line.substr(pos + 1);

                Post post(userName, content);
                posts.push_back(post);
            }
        }
    }
    postsFile.close();
}

void PostManager::savePosts() {
    std::ofstream postFile("posts.txt");
    if ( postFile.is_open() ) {
        for (const auto& post : posts) {
            postFile << post.getUserName() << "," << post.getContent() << "\n"; 
        }
    }
    postFile.close();
}
//OTHER METHODS
void PostManager::viewPosts() const {
    if(posts.empty()) {
        std::cout << "No post avalailable" << std::endl;
    } else {
        std::cout << "\n======= Posts =======\n";
        for (const auto& post : posts) {
            post.displayDetails();
        }
    }
}

void PostManager::postMessage(const Post& newPost) {
    posts.push_back(newPost);
    std::cout << "Message Posted successfully!" << std::endl;
}

void PostManager::clearPosts() {
    posts.clear();
}

//Search Posts
void PostManager::searchPost(const std::string& searchTerm, const std::string& username) const {
    bool found = false;
    for (const auto& post : posts) {
        if (post.getUserName() == username && (post.getContent().find(searchTerm) != std::string::npos)) {
            post.displayDetails();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No posts found for the given search term.\n";
    }
}