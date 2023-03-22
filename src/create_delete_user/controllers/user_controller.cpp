#include "user_controller.hpp"

UserController::UserController(CreateUserInteractor ci, DeleteUserInteractor di) :
    create_user_interactor(ci), delete_user_interactor(di) {}

void UserController::create_user() {

    create_user_request request;


    create_user_interactor.createUser(request);
}

void UserController::delete_user() {

    delete_user_request request;
    

    delete_user_interactor.deleteUser(request);
}