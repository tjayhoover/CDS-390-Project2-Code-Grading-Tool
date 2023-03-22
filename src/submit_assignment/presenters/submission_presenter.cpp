#include "submission_presenter.hpp"
#include "view_model.hpp"

#include <iostream>

// This is the presenter. It recieves data from the interactor
// puts it in the view model, and hands it to the view.
void SubmissionPresenter::presentResult(return_data data) {

    // Put the data in the view model
    ViewModel vm;
    vm.output = "Your grade is " + std::to_string(data.grade);
    std::cout << "Presenter Running" << std::endl;
    // Hand control to the view to do UI stuff
    view->display(vm);
}