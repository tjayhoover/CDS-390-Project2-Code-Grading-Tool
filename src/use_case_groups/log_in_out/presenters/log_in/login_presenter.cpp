#include "login_presenter.hpp"

#include <string>
#include "../entities/user/user.hpp"

void LoginPresenter::presentResult(login_response data) {
    ViewModel vm;

    if(data.success) {
        std::string role_string;
        if(data.role == PermissionLevel::Admin) {
            role_string = "admin";
        }
        else if(data.role == PermissionLevel::Instructor) {
            role_string = "instructor";
        }
        else if(data.role == PermissionLevel::Student) {
            role_string = "student";
        }
        vm.output = "Welcome, " + data.name + "\nYou have successfully logged in as a(n) " + role_string;
    }
    else vm.output = "Login was not successful.";
 
    view->display(vm);
}