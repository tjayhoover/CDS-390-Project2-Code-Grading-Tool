#include "student_report_presenter.hpp"

void StudentReportPresenter::presentResult(student_report_response data) {
    ViewModel vm;
    
    view->display(vm);
}