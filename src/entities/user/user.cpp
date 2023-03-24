#include <string>
#include <chrono>

#include "user.hpp"


// Constructor for initializing variables for building users from database
User::User(std::vector<std::string> params): 
permission((PermissionLevel)std::stoll(params[0])), username(params[1]), password(std::stoll(params[2])), salt(std::stoi(params[3])){}

// Constructor for creating new users with default password
User::User(PermissionLevel level,const std::string& username):
    permission(level), username(username), salt(time(nullptr)){
        this->set_password("password");
}

std::string User::get_username() const{
    return username;
}

std::size_t User::get_password() const{
    return password;
}

long long User::get_salt() const{
    return salt;
}

PermissionLevel User::get_permission() const{
    return permission;
}


// Proof of concept for hashing passwords and not storing plaintext
// THIS IS NOT A SECURE HASH DO NOT USE THIS FOR SECURITY PURPOSES
// https://en.cppreference.com/w/cpp/utility/hash
struct Hash{
    std::size_t operator()(int salt, std::string password) const noexcept{
        std::size_t h1 = std::hash<int>{}(salt);
        std::size_t h2 = std::hash<std::string>{}(password);
        return h1 ^ (h2 << 1); // bit-shift then XOR
    }
};

std::size_t User::hash_password(const std::string& password) {
    return Hash{}(salt, password);
}

void User::set_password(const std::string& new_password){   
    // Proof of concept for hashing passwords and not storing plaintext
    // THIS IS NOT A SECURE HASH DO NOT USE THIS FOR SECURITY PURPOSES
    // https://en.cppreference.com/w/cpp/utility/hash
    password = Hash{}(salt,new_password);
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
