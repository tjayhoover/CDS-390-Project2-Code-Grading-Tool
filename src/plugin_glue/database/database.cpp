#include "database.hpp"

#include <iostream>

using namespace std;

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

// However, the following are definitely required
void Database::add_user(User& user) {
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