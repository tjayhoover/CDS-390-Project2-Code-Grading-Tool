#ifndef BAUER_DATABASE_HPP
#define BAUER_DATABASE_HPP

#include <string>
#include <unorderd_map>

class bauer_DB{
    public:

    bauer_DB(const std::string& cfg_path = "../_database/cfg/default.cfg");
    ~bauer_DB() = default;

    vector<string> Database::read_data(const string& ID);
    int Database::write_data(const vector<string>& data);

    // Maybe return type as bool
    void Database::delete_data(const string& ID);


    private:

    int ID_generation();

    // create default config
    bool create_defaultconfig();
    
    // stores database parameters from config
    // files_loc
    // ID_to_path_loc
    std::unorderd_map<std::string,std::string> params {};
    std::unorderd_map<int,std::string> ID_to_path {};

};

#endif