#include "create_assignment_presenter.hpp"

void CreateAssignmentPresenter::presentResult(create_assignment_response data) {
    ViewModel vm;
    vm.output = data.message;
    
    view->display(vm);
}