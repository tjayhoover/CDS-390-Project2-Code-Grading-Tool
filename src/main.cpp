#include <iostream>
#include <string>
#include <memory>

// Include the classes which "glue" the external dependencies
#include "plugin_glue/grader/grader.hpp"
#include "plugin_glue/database/database.hpp"
#include "plugin_glue/authenticator/authenticator.hpp"

// Include the relevant bits for the submission use case
#include "submit_assignment/interactors/submit_assignment.hpp"
#include "submit_assignment/views/submission_view.hpp"
#include "submit_assignment/request_response_models/submission_models.hpp"
#include "submit_assignment/controllers/submission_controller.hpp"
#include "submit_assignment/presenters/submission_presenter.hpp"

using namespace std;

int main(int, char**) {

    // Create the database, grader, and authenticator
    unique_ptr<Grader> g = make_unique<Grader>();
    unique_ptr<Database> db = make_unique<Database>();
    unique_ptr<Authenticator> auth = make_unique<Authenticator>();

    // Initialize the use cases

    // Login Use Case
    
    //Submission Use case
    unique_ptr<SubmissionPresenter> presenter = make_unique<SubmissionPresenter>();
    presenter->setView<SubmissionView>();
    unique_ptr<SubmissionUseCase> submission_use_case = make_unique<SubmissionUseCase>(db.get(), g.get(), std::move(presenter));
    SubmissionController sub_controller;

    cout << "Welcome to Beetcode." << endl;
    // Start the submission use case
    sub_controller.start_submission(submission_use_case.get());

    cout << "Exiting Program" << endl;
}