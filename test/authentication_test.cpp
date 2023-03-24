#include <fstream>
#include <string>
#include <filesystem>
#include <iostream>

using namespace std;
namespace fs = std::filesystem;

void Yarnall_authentication(const string& username, const string& password, int permission,const std::string& output_file){
    std::string command = "curl -s --header \"Content-Type: application/json\" --request POST  --data '{\"user\":\"" +
    username + "\", \"password\":\"" + password + "\", \"permission_level\":\"" +
    std::to_string(permission) + "\" }' http://127.0.0.1:5000 >> " + output_file;
    system(command.c_str());

}   

std::pair<int,string> authenticate_user(const std::string& username, const std::string& password, int permission) {
    string curr_dir = fs::current_path();
    string temp_dir = fs::temp_directory_path();
    
    fs::current_path(temp_dir);

    string output_file {"./temp.text"};

    Yarnall_authentication(username, password, permission, output_file);

    ifstream ifs{output_file};

    string permission_level;
    string token;

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
    else{
        throw std::runtime_error("authentication failed: json return not found");
    }
    ifs.close();

    fs::current_path(curr_dir);
    return {stoi(permission_level),token};
}  


int main(){
    auto temp = authenticate_user("bubba", "asdasdasd", 1);
    cout << temp.first << " " << temp.second << endl;
}