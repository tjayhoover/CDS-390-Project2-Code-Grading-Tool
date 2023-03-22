// Brandon Bauer
// 17/3/2023
// 

#include <string>
#include <vector>

#include "db_adapter.hpp"
#include "../../entities/user/user.hpp"
#include "../../entities/assignment/assignment.hpp"
#include "../../entities/submission/submission.hpp"

using namespace std;

DB_adapter::DB_adapter(){
    /*
    I've clearly made a mistake here...
    maintain files of user, assignment, and submission IDs
    Then use these lists to load and create objects...

    this means the destructor creates theses files in the database
    */

    bauer_DB db{};
    this->db = db;

    if(db.existance("User_list")){
        vector<string> temp = db.read_data("User_list");
        for(auto& user : temp){
            users[user] = User(db.read_data(user));
        }
    }

     if(db.existance("Assignment_list")){
        vector<string> temp = db.read_data("Assignment_list");
        for(auto& assignment : temp){
            assignments[assignment] = Assignment(db.read_data(assignment));
        }
    }

     if(db.existance("Submission_list")){
        vector<string> temp = db.read_data("Submission_list");
        for(auto& submission : temp){
            submissions[submission] = Submission(db.read_data(submission));
        }
    }



}

DB_adapter::~DB_adapter(){
    // Basically create the list files, save em, and then save all objects

    // Users
    vector<string> user_list;
    for(auto& user : users){
        user_list.push_back(user.first);
        db.write_data(user.first,user.second.save());
    }
    db.write_data("User_list",user_list);

    // Assignments
    vector<string> assignment_list;
    for(auto& assignment : assignments){
        assignment_list.push_back(assignment.first);
        db.write_data(assignment.first,assignment.second.save());
    }
    db.write_data("Assignment_list",assignment_list);

    // Submissions
    vector<string> submission_list;
    for(auto& submission : submissions){
        submission_list.push_back(submission.first);
        db.write_data(submission.first,submission.second.save());
    }
    db.write_data("Submission_list",submission_list);

    //theoretically we are done... need to test the adapter with the database
}


// Adds to database
void DB_adapter::add_user(User user){
    users[user.get_username()] = user;
}

void DB_adapter::add_assignment(Assignment assignment){
    assignments[assignment.get_name()] = assignment;
}

void DB_adapter::add_submission(Submission submission){
    submissions[submission.get_sub_name()] = submission;
}

// Removes from database
void DB_adapter::del_user(const std::string& ID){
    users.erase(ID);
}

void DB_adapter::del_assignment(const std::string& ID){
    assignments.erase(ID);
}

void DB_adapter::del_submission(const std::string& ID){
    submissions.erase(ID);
}

// Gets all from database
std::vector<Assignment> DB_adapter::get_assignments(){
    std::vector<Assignment> temp;
    for(auto& assignment : assignments) temp.push_back(assignment.second);
    return temp;
}

std::vector<User> DB_adapter::get_users(){
    std::vector<User> temp;
    for(auto& user : users) temp.push_back(user.second);
    return temp;
}

std::vector<Submission> DB_adapter::get_submissions(){
    std::vector<Submission> temp;
    for(auto& submission : submissions) temp.push_back(submission.second);
    return temp;
}

// Gets single based on ID
Assignment DB_adapter::get_assignment(const std::string& ID){
    return assignments[ID];
}

User DB_adapter::get_user(const std::string& ID){
    return users[ID];
}

Submission DB_adapter::get_submission(const std::string& ID){
    return submissions[ID];
}

// Gets all names for from database
std::vector<std::string> DB_adapter::get_assignment_names(){
    std::vector<std::string> temp;
    for(auto& assignment : assignments) temp.push_back(assignment.first);
    return temp;
}
std::vector<std::string> DB_adapter::get_user_names(){
    std::vector<std::string> temp;
    for(auto& user : users) temp.push_back(user.first);
    return temp;
}
std::vector<std::string> DB_adapter::get_submission_names(){
    std::vector<std::string> temp;
    for(auto& submission : submissions) temp.push_back(submission.first);
    return temp;
}