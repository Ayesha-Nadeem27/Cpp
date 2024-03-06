#ifndef POSTMANGER_H
#define POSTMANGER_H

#include "post.h"
#include "user.h"

#include <stdexcept>
#include <vector>

class PostManager {
    private:
        std::vector<Post> posts;

    public:
        PostManager ();

        void loadPosts();
        void savePosts();
        void viewPosts() const;
        void postMessage(const Post& newPost);
        void clearPosts();
        void searchPost(const std::string& searchTerm, const std::string& username) const;

};

#endif