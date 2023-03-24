#ifndef SUBMISSION_CONTROLLER_HPP
#define SUBMISSION_CONTROLLER_HPP

#include "../interactors/submit_assignment.hpp"
#include "input_request_models.hpp"

#include <string>
#include <iostream>

class SubmissionController {

public:
    SubmissionController(SubmissionInteractor);
    void start_submission(submit_assignment_input);

private:
    SubmissionInteractor submission_interactor;
};

#endif