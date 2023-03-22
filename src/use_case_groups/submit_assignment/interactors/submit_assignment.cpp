#include "submit_assignment.hpp"

#include <iostream>

SubmissionInteractor::SubmissionInteractor(AbstractDatabase* d, AbstractGrader* g, PresenterInterface* p)
 : presenter(p), storage(d), grader(g) {}

double SubmissionInteractor::submit_assignment(incoming_submission sub) {

    // Get the assigment corresponding to this submission:
   // Assignment assignment = storage->get_assignment(sub.assignment_name);

    //Submission submission(sub.student_name, sub.program, sub.submission_time);
    
   // assignment

    std::cout << "The interactor has successfully interacted." << std::endl;

    // Now that the work is done, compile the results in the return data struct
    return_data data;
    data.grade = 69;

    // Now hand that struct, and control, to the presenter,
    // which will format the data for the view
    presenter->presentResult(data);

    return 0.0;
}