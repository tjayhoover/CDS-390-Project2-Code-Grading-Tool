#ifndef SUBMISSION_CONTROLLER_HPP
#define SUBMISSION_CONTROLLER_HPP

#include "../interactors/submit_assignment.hpp"

#include <string>
#include <iostream>

class SubmissionController {

public:
    SubmissionController(SubmissionInteractor);
    void start_submission(std::string student_name);

private:
    SubmissionInteractor submission_interactor;
};

#endif