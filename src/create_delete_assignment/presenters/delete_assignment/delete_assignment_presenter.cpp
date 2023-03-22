#include "delete_assignment_presenter.hpp"

void DeleteAssignmentPresenter::presentResult(delete_assignment_response data) {
    ViewModel vm;
    vm.output = data.message;
    
    view->display(vm);
}
