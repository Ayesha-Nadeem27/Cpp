#if !defined(ENTITY_H)
#define ENTITY_H

#include <string>

class Entity{
    protected:
        std::string userName;
    public:
        Entity(const std::string& name) 
            : userName(name) {} 

        virtual std::string getUserName() const = 0;
        virtual void displayDetails() const = 0;

        virtual ~Entity() {};
};

#endif