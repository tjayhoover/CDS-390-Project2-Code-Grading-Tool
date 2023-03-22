#ifndef SUBMIT_ASSIGNMENT_HPP
#define SUBMIT_ASSIGNMENT_HPP

#include "../request_response_models/submission_models.hpp"
#include "presenter_interface.hpp"
#include "abstract_grader.hpp"
#include "abstract_database.hpp"
#include <memory>

class SubmissionInteractor {

public:
    SubmissionInteractor(AbstractDatabase* d, AbstractGrader* g, PresenterInterface* p);

    void submit_assignment(submission_request sub);

private:
    AbstractGrader* grader;
    AbstractDatabase* storage;
    PresenterInterface* presenter;
};

#endif