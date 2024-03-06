#pragma once
#include "entity.h"

class User : public Entity {
    private:
        std::string password;
    public:
    User (const std::string& name,const std::string& password);

    void setUserName(const std::string&) ;
    void setPassword(const std::string&) ;

    std::string getPassword() const;
    
    std::string getUserName() const override;
    void displayDetails() const override;
};