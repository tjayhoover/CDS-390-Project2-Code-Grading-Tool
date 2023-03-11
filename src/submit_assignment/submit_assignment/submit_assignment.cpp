#include "submit_assignment.hpp"

SubmissionUseCase::SubmissionUseCase(AbstractDatabase* db_ptr, AbstractGrader* grd_ptr) {
    this->grader = grd_ptr;
    this->storage = db_ptr;
}

double SubmissionUseCase::submit_assignment() {

    User tyler(Student, "Tyler");

    storage->add_user(tyler);

    return 0.0;
}