#ifndef BAUER_DATABASE_HPP
#define BAUER_DATABASE_HPP

#include <string>
#include <unordered_map>

class bauer_DB{
    public:

    bauer_DB(const std::string& cfg_path = "./_database/cfg/default.cfg");
    ~bauer_DB();

    std::vector<std::string> read_data(const std::string& ID);
    void write_data(const std::string& ID,const std::vector<std::string>& data);

    // Maybe return type as bool
    void delete_data(const std::string& ID);

    bool existance(const std::string& ID);


    private:

    int ID_generation();

    // creates folder structure
    bool create_default_structure();
    // create default config
    bool create_default_config();
    
    // stores database parameters from config
    // files_loc
    // ID_to_path_loc
    std::unordered_map<std::string,std::string> params {};
    std::unordered_map<std::string,std::string> ID_to_path {};

};

#endif