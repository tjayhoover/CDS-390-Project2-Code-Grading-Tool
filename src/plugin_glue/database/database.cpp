#include "database.hpp"

using namespace std;

vector<Assignment> database::get_assignments() {
    vector<Assignment> v;
    return v;
}

vector<User> database::get_users() {
    vector<User> u;
    return u;
}

vector<Submission> database::get_submissions() {
    vector<Submission> s;
    return s;
}


// However, the following are definitely required
void database::add_user(User& user) {

}

void database::add_assignment(Assignment& assignment) {

}

void database::add_submission(Submission& submission) {

}

void database::del_user(User& user) {

}

void database::del_assignment(Assignment& assignment) {

}

void database::del_submission(Submission& submission) {

}