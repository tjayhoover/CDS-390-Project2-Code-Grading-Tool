#include "user_controller.hpp"

#include <iostream>
#include <string>

using namespace std;

UserController::UserController(CreateUserInteractor ci, DeleteUserInteractor di, ChangePasswordInteractor cpi) :
    create_user_interactor(ci), delete_user_interactor(di), change_password_interactor(cpi) {}

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

void UserController::change_password(string username) {

    // Initialize the request model object
    change_password_request request;

    cout << "Please type your new password: " << endl;
    string new_password;
    cin >> new_password;

    cout << "Please type it again:" << endl;
    string new_password_copy;
    cin >> new_password_copy;

    if(new_password == new_password_copy) {
        request.username = username;
        request.new_password = new_password;

        // Hand off the request to the interactor
        change_password_interactor.change_password(request);
    }
    else cout << "The passwords did not match. Try again." << endl;
}