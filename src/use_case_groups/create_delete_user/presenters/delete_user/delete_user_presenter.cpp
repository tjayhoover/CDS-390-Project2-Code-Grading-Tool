#include "delete_user_presenter.hpp"

void DeleteUserPresenter::presentResult(delete_user_response data) {
    ViewModel vm;
    if(data.success) {
        vm.output = "The user was successfully deleted.";
    }
    else vm.output = "Error: the delete operation failed.\n" + data.error;
    
    view->display(vm);
}