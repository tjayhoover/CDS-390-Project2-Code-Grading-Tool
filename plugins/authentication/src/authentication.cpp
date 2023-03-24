#include <string>

using namespace std;


void Yarnall_authentication(const string& username, const string& password, int permission,const std::string& output_file){
    std::string command = "curl -s --header \"Content-Type: application/json\" --request POST  --data '{\"user\":\"" +
        username + "\", \"password\":\"" + password + "\", \"permission_level\":\"" +
        std::to_string(permission) + "\" }' http://127.0.0.1:5000 >> " + output_file;
    system(command.c_str());
}   