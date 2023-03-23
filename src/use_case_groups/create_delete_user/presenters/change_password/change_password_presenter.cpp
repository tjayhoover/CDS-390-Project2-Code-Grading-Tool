#include "change_password_presenter.hpp"

void ChangePasswordPresenter::presentResult(change_password_response data) {

    // Initialize the view model object
    ViewModel vm;

    if(data.success) {
        vm.output = "Password successfully changed.";
    }
    else vm.output = "Error; password reset failed.";
    
    view->display(vm);
}