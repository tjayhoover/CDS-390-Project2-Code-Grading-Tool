#ifndef SUBMIT_ASSIGNMENT_HPP
#define SUBMIT_ASSIGNMENT_HPP

#include "abstract_grader.hpp"
#include "abstract_database.hpp"


class SubmissionUseCase {

public:
    SubmissionUseCase(AbstractDatabase*, AbstractGrader*);

    double submit_assignment();

private:
    AbstractGrader* grader;
    AbstractDatabase* storage;
};

#endif