#include "create_assignment_presenter.hpp"

void CreateAssignmentPresenter::presentResult(create_assignment_response data) {
    ViewModel vm;

    if(data.success) {
        vm.output = "The assignment was added successfully.";
    }
    else vm.output = "Error. No Assignment was added.";
    
    view->display(vm);
}