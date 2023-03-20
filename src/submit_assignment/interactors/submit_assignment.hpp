#ifndef SUBMIT_ASSIGNMENT_HPP
#define SUBMIT_ASSIGNMENT_HPP

#include "../request_response_models/submission_models.hpp"
#include "presenter_interface.hpp"
#include "abstract_grader.hpp"
#include "abstract_database.hpp"
#include <memory>

class SubmissionUseCase {

public:
    SubmissionUseCase(AbstractDatabase* d, AbstractGrader* g, std::unique_ptr<PresenterInterface> p);

    double submit_assignment(incoming_submission sub);

    // template <class P>
    // void setPresenter() {
    //     presenter = T();
    // }

private:
    AbstractGrader* grader;
    AbstractDatabase* storage;
    std::unique_ptr<PresenterInterface> presenter;
};

#endif