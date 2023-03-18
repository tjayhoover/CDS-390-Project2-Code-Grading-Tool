// Brandon Bauer
// 17/3/2023
// 

#include <string>
#include <vector>

#include "db_adapter.hpp"
#include "../../../src/entities/user/user.hpp"
#include "../../../src/entities/assignment/assignment.hpp"
#include "../../../src/entities/submission/submission.hpp"

using namespace std;
///////////// Might use these with modifications ////////////////

// Adds to database
std::string DB_adapter::add_user(User& user){

}

std::string DB_adapter::add_assignment(Assignment& assignment){

}

std::string DB_adapter::add_submission(Submission& submission){

}

// Removes from database
void DB_adapter::del_user(const std::string& ID){

}

void DB_adapter::del_assignment(const std::string& ID){

}

void DB_adapter::del_submission(const std::string& ID){

}

// Gets all from database
std::vector<Assignment> DB_adapter::get_assignments(){

}

std::vector<User> DB_adapter::get_users(){

}

std::vector<Submission> DB_adapter::get_submissions(){

}

// Gets single based on ID
Assignment DB_adapter::get_assignment(const std::string& ID){

}

User DB_adapter::get_user(const std::string& ID){

}

Submission DB_adapter::get_submission(const std::string& ID){
  
}