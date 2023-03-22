#include "login_presenter.hpp"

void LoginPresenter::presentResult(login_response data) {
    ViewModel vm;
    vm.output = "Welcome, " + data.name + "! " + "You are a(n) " + data.role;
 
    view->display(vm);
}