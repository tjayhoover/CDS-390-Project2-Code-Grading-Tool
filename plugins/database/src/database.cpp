// Adam Rilatt and Brandon Bauer
// 30 January 2023
// BeetCode -- Database Implementation

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem> // for remove(); C++17 required
// https://en.cppreference.com/w/cpp/filesystem

#include "database.hpp"

using std::string;
using std::vector;

namespace fs = std::filesystem;

/////////// TODO //////////////////
    // need to add ID system
    // and add constructor


bauer_DB::bauer_DB(const std::string& cfg_path){

  if(!std::filesystem::exists(cfg_path)){
    create_default_structure();
  }

  std::ifstream ifs(cfg_path);

  if (!ifs.is_open()) 
    throw std::runtime_error("Database configuration file not found!");

  string temp;


  // The additions of one are due to finding len from zero indexing
  // can use other methods and might explore those.....
  while (std::getline(ifs, temp)){
    int name_len    = temp.find_first_of(' ');
    int param_start = temp.find_first_of('"')+1;
    int param_len   = (temp.find_last_of('"')) - param_start;
    params[temp.substr(0,name_len)] =
       temp.substr(param_start,param_len);
  }

  if(std::filesystem::exists(params["ID_to_path_loc"])){
    std::ifstream ID_paths(params["ID_to_path_loc"]);
    while (std::getline(ID_paths, temp)){
    int name_len    = temp.find_first_of(' ');
    int param_start = temp.find_first_of('"')+1;
    int param_len   = (temp.find_last_of('"')) - param_start;
      ID_to_path[temp.substr(0,name_len)] = 
        temp.substr(param_start,param_len);
    }
  }

  for(auto& str : ID_to_path) std::cout << str.second << std::endl;
}

bauer_DB::~bauer_DB(){
  std::ofstream ofs(params["ID_to_path_loc"]);
  for(auto& pair : ID_to_path) ofs << (pair.first + " = \"" + pair.second + "\"\n");
  ofs.close();
}

bool bauer_DB::create_default_structure(){
  // create file structure, default config, ID_to_path.dat etc
  // return true 
  bool files_created {false};
  if(fs::create_directory("./_database"))
    if(fs::create_directory("./_database/data") && fs::create_directory("./_database/cfg"))
      if(fs::create_directory("./_database/data/ID_path") && fs::create_directory("./_database/data/files"))
        files_created = true;
  
  if(!files_created)
    throw std::runtime_error("Database directory creation failed");

  if(create_default_config()){
     std::ifstream temp(params["ID_to_path_loc"]);
     temp.close();
  }
  else
    throw std::runtime_error("ID_to_path creation failed");
  return true;
}

bool bauer_DB::create_default_config(){
  std::ofstream ofs("./_database/cfg/default.cfg");
  ofs << "files_loc = \"./_database/data/files/\"\n";
  ofs << "ID_to_path_loc = \"./_database/data/ID_path/ID_to_path.dat\"\n";
  ofs.close();
  return true;
}


vector<string> bauer_DB::read_data(const std::string& ID) { 
  
  std::ifstream ifs(ID_to_path[ID]);
  
  if (!ifs.is_open())
    throw std::runtime_error("Database file not found.");
  
  vector<string> data;
  string temp;
  while (std::getline(ifs, temp))
    data.push_back(temp);
  
  ifs.close();
  
  return data;
  
}

void bauer_DB::write_data(const std::string& ID,const vector<string>& data) {
  // if file exists, nuke and pave it..... this prevents possible issues
  // could definitely be better implemented....
  if(existance(ID)) delete_data(ID);

  ID_to_path[ID] = (params["files_loc"]+ID+"_file.dat");
  std::ofstream ofs(ID_to_path[ID]);
  
  for (const string& line : data)
    ofs << line << std::endl;

  ofs.close();
}

void bauer_DB::delete_data(const std::string& ID) {
  
  if (std::filesystem::remove(ID_to_path[ID])){
    ID_to_path.erase(ID);
    return;
  }
  
  else
    throw std::runtime_error("Database file not found and could not be deleted.");

}


bool bauer_DB::existance(const std::string& ID){
  return ID_to_path.find(ID)!=end(ID_to_path);
}