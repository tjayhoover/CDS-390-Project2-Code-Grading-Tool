#include "student_assignments_presenter.hpp"

#include <string>

void StudentAssignmentsPresenter::presentResult(student_view_assignments_response data) {
    ViewModel vm;

    for(int i = 0; i < data.names.size(); ++i) {
        vm.output += ("Name: " + data.names[i] + "\n"
                    + "Due: " + to_simple_string(data.due_dates[i]) + "\n"
                    + "Description: " + data.descriptions[i] + "\n\n");
    }
 
    view->display(vm);
}