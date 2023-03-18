// Adam Rilatt and Brandon Bauer
// 30 January 2023
// BeetCode -- Database Implementation

#include <stdexcept>
#include <fstream>
#include <filesystem> // for remove(); C++17 required
#include <iostream>

#include "database.hpp"

using std::string;
using std::vector;


/////////// TODO //////////////////
    // need to add ID system


vector<string> Database::read_data(const string& location) { 
  
  std::ifstream ifs(location);
  
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
