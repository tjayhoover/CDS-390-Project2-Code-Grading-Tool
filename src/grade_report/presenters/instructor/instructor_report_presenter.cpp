#include "instructor_report_presenter.hpp"

void InstructorReportPresenter::presentResult(instructor_report_response data) {
    ViewModel vm;
    
    view->display(vm);
}