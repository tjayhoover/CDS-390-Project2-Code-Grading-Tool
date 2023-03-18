#include "submit_assignment.hpp"

#include <iostream>


// SubmissionUseCase::SubmissionUseCase(AbstractDatabase* db_ptr, AbstractGrader* grd_ptr) {
//     this->grader = grd_ptr;
//     this->storage = db_ptr;
// }

SubmissionUseCase::SubmissionUseCase(AbstractGrader* grd_ptr) {
    this->grader = grd_ptr;
    std::cout << "Use case created" << std::endl;
}

double SubmissionUseCase::submit_assignment(incoming_submission sub) {

    // Get the assigment corresponding to this submission:
    Assignment assignment = storage->get_assignment(sub.assignment_name);

    //Submission submission(sub.student_name, sub.program, sub.submission_time);
    
   // assignment

    std::cout << "Fat Shits" << std::endl;

    return 0.0;
}