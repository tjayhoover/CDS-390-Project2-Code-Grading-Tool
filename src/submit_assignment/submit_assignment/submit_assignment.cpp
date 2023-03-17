#include "submit_assignment.hpp"

#include <iostream>


SubmissionUseCase::SubmissionUseCase(AbstractDatabase* db_ptr, AbstractGrader* grd_ptr) {
    this->grader = grd_ptr;
    this->storage = db_ptr;
}

double SubmissionUseCase::submit_assignment(incoming_submission sub) {

    
    Submission submission(sub.assignment_name);

    return 0.0;
}