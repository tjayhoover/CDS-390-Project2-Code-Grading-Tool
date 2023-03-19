#ifndef SUBMIT_ASSIGNMENT_HPP
#define SUBMIT_ASSIGNMENT_HPP

#include "../request_response_models/submission_models.hpp"
#include "abstract_grader.hpp"
#include "abstract_database.hpp"
#include "abstract_UI.hpp"

class SubmissionUseCase {

public:
    SubmissionUseCase(AbstractDatabase*, AbstractGrader*);

    double submit_assignment(incoming_submission sub);

private:
    AbstractGrader* grader;
    AbstractDatabase* storage;
    AbstractUI* ui;
};

#endif