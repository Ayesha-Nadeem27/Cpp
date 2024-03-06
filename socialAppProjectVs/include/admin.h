#if !defined (ADMIN_H)
#define ADMIN_H

#include "user.h"
#include "adminException.h"

#include <string>
#include <vector>

class Admin : public Entity {
    private:
        std::string adminUserName;
        std::string adminPassword;

    public:
        Admin (const std::string& adnm, const std::string& adps);
        Admin ();

        std::string getAdminUserName() const;
        std::string getAdminPassword() const;

        //overides
        std::string getUserName() const override;
        void displayDetails() const override;

        //methods
        bool authenticateAdmin(const std::string& adminUserName, const std::string& adminPassword) const;
        void viewUsers(const std::vector<User>& users) const;
        bool deleteUser(std::vector<User>& users, const std::string& userName);
};

#endif