#include "user_controller.hpp"

#include <iostream>
#include <string>

using namespace std;

UserController::UserController(CreateUserInteractor ci, DeleteUserInteractor di) :
    create_user_interactor(ci), delete_user_interactor(di) {}

void UserController::create_user() {

    // Initialize the request model object
    create_user_request request;
    cout << "Type the permission level of the new user:" << endl;
    string permission_level;
    cin >> permission_level;

    PermissionLevel pl;

    if(tolower(permission_level.front()) == 'a') {
        pl = PermissionLevel::Admin;
    }
    else if(tolower(permission_level.front()) == 'i') {
        pl = PermissionLevel::Instructor;
    }
    else if(tolower(permission_level.front()) == 's') {
        pl = PermissionLevel::Student;
    }
    
    cout << "Type the username of the new user:" << endl;
    string username;
    cin >> username;

    // Put the data in the request model object
    request.username = username;
    request.permission_level = pl;

    create_user_interactor.createUser(request);
}

void UserController::delete_user() {

    delete_user_request request;
    

    delete_user_interactor.deleteUser(request);
}