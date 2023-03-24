#include "instructor_report_presenter.hpp"

#include <boost/date_time/posix_time/posix_time.hpp>

void InstructorReportPresenter::presentResult(instructor_report_response data) {

    ViewModel vm;

    for(int i = 0; i < data.student_names.size(); ++i) {

        // Calculate the grade as a percentage
        double grade_percentage = ((double)data.cases_passed[i]/(double)data.total_cases) * 100;
        std::stringstream ss;
        ss << std::setprecision(2) << std::fixed << grade_percentage;
        std::string grade_percentage_str = ss.str();

        vm.output += ("Student Name: " + data.student_names[i] + "\n"
                    + "Submission Date: " + to_simple_string(data.submission_dates[i]) + "\n"
                    + "Cases Passed: " + std::to_string(data.cases_passed[i]) + "/" + std::to_string(data.total_cases) + "\n"
                    + "Grade: " + grade_percentage_str + "%\n");
    }

    if(data.student_names.size() == 0) {
        vm.output = "No students submitted work.";
    }
    
    view->display(vm);
}