#include "post.h"
#include <iostream>

//constructor
Post::Post(const std::string& nm, const std::string& cnt) 
        : Entity(nm), content(cnt) {}

//get-set
void Post::setContent(const std::string& cnt) {
    content = cnt;
}
std::string Post::getContent() const {
    return content;
}

//overrides
std::string Post::getUserName() const {
    return userName;
}
void Post::displayDetails() const {
    std::cout << "Post message: " << getUserName() << std::endl;
    std::cout << "[" << getUserName() << "]: " << getContent() << std::endl;
}