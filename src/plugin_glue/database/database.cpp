#include "database.hpp"

#include <iostream>
#include <string>

using namespace std;

Database::Database() {
}

User Database::get_user(std::string username) {
    User u(PermissionLevel::Student, "test_user");
    return u;
}

Assignment Database::get_assignment(std::string name) {
    time_t due_date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    Assignment a(name, boost::posix_time::second_clock::local_time());
    return a;
}

vector<Assignment> Database::get_assignments() {
    vector<Assignment> v;
    return v;
}

vector<User> Database::get_users() {
    vector<User> u;
    return u;
}

vector<Submission> Database::get_submissions() {
    vector<Submission> s;
    return s;
}

void Database::add_user(User& user) {
    std::cout << "adding " << user.get_username() << std::endl;
    return;
}

void Database::add_assignment(Assignment& assignment) {
    return;
}

void Database::add_submission(Submission& submission) {
    return;
}   

void Database::del_user(User& user) {
    return;
}

void Database::del_assignment(Assignment& assignment) {
    return;
}

void Database::del_submission(Submission& submission) {
    return;
}