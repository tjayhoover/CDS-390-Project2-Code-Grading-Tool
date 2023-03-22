#include "create_user_presenter.hpp"

void CreateUserPresenter::presentResult(create_user_response data) {
    ViewModel vm;
    vm.output = data.message;
    
    view->display(vm);
}