#include "delete_assignment_presenter.hpp"

void DeleteAssignmentPresenter::presentResult(delete_assignment_response data) {
    ViewModel vm;
    
    if(data.success) {
        vm.output = "The assignment was successfully deleted.";
    }
    else vm.output = "Error: the delete operation failed.\n" + data.error;
    
    view->display(vm);
}
