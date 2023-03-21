#include "log_in_out_controller.hpp"

#include "../request_response_models/login_models.hpp"

#include <string>
#include <iostream>

using namespace std;

LogInOutController::LogInOutController(LoginInteractor li, LogoutInteractor lo) :
    login_interactor(li), logout_interactor(lo){}

void LogInOutController::start_login_process() {

    cout << "Please type in your username:" << endl;
    string username;
    cin >> username;
    cout << "Please type in your password:" << endl;
    string password;
    cin >> password;

    login_request data;
    data.username = username;
    data.password = password;
    
    // Use case activated!
    login_interactor.log_in(data);
}

void LogInOutController::start_logout_process() {


}