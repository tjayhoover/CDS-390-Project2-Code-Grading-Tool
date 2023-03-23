#include "student_report_presenter.hpp"

#include <boost/date_time/posix_time/posix_time.hpp>
#include <string>
#include <sstream>

void StudentReportPresenter::presentResult(student_report_response data) {
    ViewModel vm;

    for(int i = 0; i < data.assignment_names.size(); ++i) {
        double grade_percentage = ((double)data.cases_passed[i]/(double)data.total_cases[i]) * 100;
        std::stringstream ss;
        ss << std::setprecision(2) << std::fixed << grade_percentage;
        std::string grade_percentage_str = ss.str();
        vm.output += ("Assignment Name: " + data.assignment_names[i] + "\n"
                    + "Due Date: " + to_simple_string(data.due_dates[i]) + "\n"
                    + "Submission Date: " + to_simple_string(data.submission_dates[i]) + "\n"
                    + "Cases Passed: " + std::to_string(data.cases_passed[i]) + "/" + std::to_string(data.total_cases[i]) + "\n"
                    + "Grade: " + grade_percentage_str + "%\n");
    }
    
    view->display(vm);
}