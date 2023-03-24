#include <fstream>
#include <string>
#include <filesystem>

#include "authenticator.hpp"
#include "authentication.hpp"

namespace fs = std::filesystem;
using namespace std;

std::pair<int,string> Authenticator::authenticate_user(const std::string& username, const std::string& password, int permission) {
    auto curr_dir = fs::current_path();
    auto temp_dir = fs::temp_directory_path();
    
    fs::current_path(temp_dir);

    string output_file {"./temp.text"};

    Yarnall_authentication(username, password, permission, output_file);

    ifstream ifs{output_file};

    string permission_level;
    string token;
    try{
        if(ifs.is_open()){
            string temp;

            ifs >> temp;
            ifs >> temp;
            ifs >> temp;
            permission_level = temp.substr(1,1);
            ifs >> temp;
            ifs >> temp;
            token = temp.substr(1,size(temp)-2);
        }
    }
    catch (std::exception ex) {
        throw std::runtime_error("Authentication failed: server return not found. Check if server is running.");
    }
    ifs.close();

    fs::current_path(curr_dir);

    return {stoi(permission_level),token};
}   