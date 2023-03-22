// Brandon Bauer
// 21/3/2023
// BeetCode -- Minimal Database Test, derived from Adam Rilatt <3

#include <iostream>
#include <vector>
#include <string>

#include "database.hpp"

using namespace std;

void creation_test(){
  cout << "Starting" << endl;

  bauer_DB d;
  
  cout << "Created database." << endl;
  vector<string> temp {"this is a test","wowzer"};
  int ID = d.write_data(temp);

  cout << ID << endl;

  vector<string> file = d.read_data(ID);

  for(auto& str : file) cout << str << endl;

  cout << "This RAN!" << endl;
}

void reload_test(){
  bauer_DB d;

  vector<string> file = d.read_data(0);

 for(auto& str : file) cout << str << endl;

 cout << "RELOAD WORKS" << endl;
}

int main() {
  creation_test();

  cout << endl;
  cout << endl;
  cout << endl;

  reload_test();

}
