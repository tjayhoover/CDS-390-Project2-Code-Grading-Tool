#include "user_controller.hpp"

#include <iostream>
#include <string>

using namespace std;

UserController::UserController(CreateUserInteractor ci, DeleteUserInteractor di, ChangePasswordInteractor cpi) :
    create_user_interactor(ci), delete_user_interactor(di), change_password_interactor(cpi) {}

void UserController::create_user(create_user_input input_data) {

    // Initialize the request model object
    create_user_request request;

    PermissionLevel pl;

    if(tolower(input_data.permission_level.front()) == 'a') {
        pl = PermissionLevel::Admin;
    }
    else if(tolower(input_data.permission_level.front()) == 'i') {
        pl = PermissionLevel::Instructor;
    }
    else if(tolower(input_data.permission_level.front()) == 's') {
        pl = PermissionLevel::Student;
    }
    
    // Put the data in the request model object
    request.permission_level = pl;
    request.username = input_data.username;

    // Hand the request to the interactor
    create_user_interactor.createUser(request);
}

void UserController::delete_user(delete_user_input input_data) {
    // Create the request
    delete_user_request request;
    request.username = input_data.username;

    // Hand the request to the interactor
    delete_user_interactor.deleteUser(request);
}

void UserController::change_password(change_password_input input_data) {

    // Initialize the request model object
    change_password_request request;

    request.current_password = input_data.old_password;
    request.new_password = input_data.new_password;
    request.username = input_data.username;

    change_password_interactor.change_password(request);
}