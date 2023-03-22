#include "create_user_presenter.hpp"

void CreateUserPresenter::presentResult(create_user_response data) {

    // Initialize the view model object
    ViewModel vm;

    if(data.success) {
        vm.output = "New user successfully added.";
    }
    else vm.output = "Error; no user was added.";
    
    view->display(vm);
}