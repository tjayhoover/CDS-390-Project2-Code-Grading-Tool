// Adam Rilatt and Brandon Bauer
// 30 January 2023
// BeetCode -- Database Implementation

#include <stdexcept>
#include <fstream>
#include <filesystem> // for remove(); C++17 required
// https://en.cppreference.com/w/cpp/filesystem

#include "database.hpp"

using std::string;
using std::vector;

namespace fs = std::filesystem;

/////////// TODO //////////////////
    // need to add ID system
    // and add constructor


bauer_DB::bauer_DB(const std::string& cfg_path = "../_database/cfg/default.cfg"){
  //string cur_path = fs::current_path();
  //fs::current_path("../plugins/");
  std::ifstream ifs(cfg_path);

  if (!ifs.is_open()) 
    throw std::runtime_error("Database configuration file not found!");

  string temp;


  // The additions of one are due to finding len from zero indexing
  // can use other methods and might explore those.....
  while (std::getline(ifs, temp)){
    int name_len    = temp.find_first_of(' ')+1;
    int param_start = temp.find_first_of('"')+1
    int param_len   = param_start - (temp.find_last_of('"') + 1);
    params[temp.substr(0,name_loc)] =
       temp.substr(param_start,param_len);
  }

  if(std::filesystem::exists(params[ID_to_path_loc])){
    std::ifstream ID_paths(ID_to_path_loc);

  }

}

void Database::create_defaultconfig(){
  
}

vector<string> Database::read_data(const string& ID) { 
  
  std::ifstream ifs(ID);
  
  if (!ifs.is_open())
    throw std::runtime_error("Database file not found.");
  
  vector<string> data;
  string temp;
  while (std::getline(ifs, temp))
    data.push_back(temp);
  
  ifs.close();
  
  return data;
  
}

void Database::write_data(const string& location, const vector<string>& data) {
  
  std::ofstream ofs(location);
  
  for (const string& line : data)
    ofs << line << std::endl;
  
}

void Database::delete_data(const string& location) {
  
  if (std::filesystem::remove(location))
    return;
  
  else
    throw std::runtime_error("Database file not found and could not be deleted.");

}
