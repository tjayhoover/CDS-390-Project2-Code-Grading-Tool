#include "login_presenter.hpp"

void LoginPresenter::presentResult(login_response data) {
    ViewModel vm;
    vm.output = "Hello, " + data.name + "\n" + "As an " + data.role + 
                " you can do the following:\n" + data.menu;
 
    view->display(vm);
}