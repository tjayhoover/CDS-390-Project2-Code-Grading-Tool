#include "log_in_out_controller.hpp"

#include "../request_response_models/login_models.hpp"

#include <string>
#include <iostream>

using namespace std;

LogInOutController::LogInOutController(LoginInteractor li, LogoutInteractor lo) :
    login_interactor(li), logout_interactor(lo){}

std::pair<bool, User> LogInOutController::start_login_process(log_in_input input_data) {

    login_request data;

    data.username = input_data.username;
    data.password = input_data.password;

    // Use case activated!
    return login_interactor.log_in(data);
}

void LogInOutController::start_logout_process() {

}