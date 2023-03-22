#include "delete_user_presenter.hpp"

void DeleteUserPresenter::presentResult(delete_user_response data) {
    ViewModel vm;
    vm.output = data.message;
    
    view->display(vm);
}