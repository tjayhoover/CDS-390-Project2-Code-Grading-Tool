// Author: Brandon Bauer
// Date: 10/2/2023

#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>

// This should stay basically the same unless we want to change the way we
// save and load from database using a different method

enum PermissionLevel {
    Admin,
    Instructor,
    Student,
    Null
};


class User {
    public:

    User() = default;

    // Constructor for database
    User(std::vector<std::string>);

    // Constructor for controller
    User(PermissionLevel level, const std::string& username);

    ~User() = default;

    std::string get_username() const;
    int get_password() const;
    int get_salt() const;
    PermissionLevel get_permission() const;
    void set_password(const std::string& new_password);

    // save Function for database
    std::vector<std::string> save();

    private:

    // Listed at Top of file
    PermissionLevel permission;
    std::string username;
    int password;
    int salt;
};

#endif