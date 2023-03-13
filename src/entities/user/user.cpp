#include <string>
#include <ctime> // this will be swapped with boost time same for saving etc

#include "user.hpp"
//#include "../Hash/hash.h"


// Constructor for initializing variables for building users from database
User::User(std::vector<std::string> params): 
permission((PermissionLevel)std::stoi(params[0])), username(params[1]), password(std::stoi(params[2])), salt(std::stoi(params[3])){}

// Constructor for creating new users with default password
User::User(PermissionLevel level,const std::string& username):
    permission(level), username(username), salt(time(nullptr)){
        this->set_password("password");
}

std::string User::get_username() const{
    return username;
}

int User::get_password() const{
    return password;
}

int User::get_salt() const{
    return salt;
}

PermissionLevel User::get_permission() const{
    return permission;
}

void User::set_password(const std::string& new_password){
    /*
    THIS IS NOT SECURE AND IS MAINLY PROOF OF CONCEPT
    DO NOT DO THIS, AGAIN THIS IS NOT SECURE.
    STD::HASH IS NOT SECURE FOR CRYPTOGRAPHIC PURPOSES
    */
    //password = Hash{}(salt,new_password);
}

// Saves User info as string vector for saving in database
std::vector<std::string> User::save(){
    std::vector<std::string> data;

    data.push_back(std::to_string(permission));
    data.push_back(username);
    data.push_back(std::to_string(password));
    data.push_back(std::to_string(salt));

    return data;
}
