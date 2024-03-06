#if !defined(POST_H)
#define POST_H

#include "entity.h"

class Post : public Entity {
    private:
        std::string content;
    
    public:
        //constructor
        Post(const std::string& nm, const std::string& cnt);
        
        //get-set
        void setContent(const std::string& newcnt);
        std::string getContent() const;

        //overrides
        std::string getUserName() const override;
        void displayDetails() const override;
};

#endif