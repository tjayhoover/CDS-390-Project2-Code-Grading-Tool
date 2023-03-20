#ifndef SUBMISSION_CONTROLLER_HPP
#define SUBMISSION_CONTROLLER_HPP

#include "../interactors/submit_assignment.hpp"


#include <string>
#include <iostream>

class SubmissionController {

public:
    void start_submission(SubmissionUseCase* suc);
};


#endif