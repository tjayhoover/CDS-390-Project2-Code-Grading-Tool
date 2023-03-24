#include "submission_presenter.hpp"
#include "view_model.hpp"

#include <iostream>

// This is the presenter. It recieves data from the interactor
// puts it in the view model, and hands it to the view.
void SubmissionPresenter::presentResult(submission_response data) {

    // Put the data in the view model
    ViewModel vm;
    if(data.success) {
        if(!data.on_time) {
            vm.output += ("Late submission! The project was due " + data.duration_late + " hours ago.\n");
        }
        vm.output += "You passed " + std::to_string(data.num_passed)
                    + "/" + std::to_string(data.num_cases) + " test cases.";
    }
    else {
        vm.output = "That assignment does not exist.";
    }
    view->display(vm);
}