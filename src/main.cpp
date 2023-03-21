#include <iostream>
#include <string>
#include <memory>

// Include the classes which "glue" the external dependencies
#include "plugin_glue/grader/grader.hpp"
#include "plugin_glue/database/database.hpp"
#include "plugin_glue/authenticator/authenticator.hpp"

// Include the UI
#include "console_interface/console_ui.hpp"

// Include the relevant bits for the submission use case
#include "submit_assignment/interactors/submit_assignment.hpp"
#include "submit_assignment/views/submission_view.hpp"
#include "submit_assignment/request_response_models/submission_models.hpp"
#include "submit_assignment/controllers/submission_controller.hpp"
#include "submit_assignment/presenters/submission_presenter.hpp"

// Include the relevant bits for the login/logout use case
#include "log_in_out/controllers/log_in_out_controller.hpp"
#include "log_in_out/interactors/log_in/log_in.hpp"
#include "log_in_out/interactors/log_out/log_out.hpp"
#include "log_in_out/presenters/log_in/login_presenter.hpp"
#include "log_in_out/presenters/log_out/logout_presenter.hpp"
#include "log_in_out/views/log_in/login_view.hpp"
#include "log_in_out/views/log_out/logout_view.hpp"

using namespace std;

int main(int, char**) {

    // Create the database, grader, authenticator, and user interface
    unique_ptr<Grader> g = make_unique<Grader>();
    unique_ptr<Database> db = make_unique<Database>();
    unique_ptr<Authenticator> auth = make_unique<Authenticator>();

    // Initialize dependencies of the use cases

    // Login Use Case
    unique_ptr<LoginPresenter> login_presenter = make_unique<LoginPresenter>();
    unique_ptr<LogoutPresenter> logout_presenter = make_unique<LogoutPresenter>();
    login_presenter->setView<LoginView>();
    logout_presenter->setView<LogoutView>();
    LoginInteractor login_interactor = LoginInteractor(db.get(), auth.get(), login_presenter.get());
    LogoutInteractor logout_interactor = LogoutInteractor(logout_presenter.get());
    LogInOutController log_in_out_controller = LogInOutController(login_interactor, logout_interactor);
    
    // Submission Use Case
    unique_ptr<SubmissionPresenter> sub_presenter = make_unique<SubmissionPresenter>();
    sub_presenter->setView<SubmissionView>();
    SubmissionInteractor sub_interactor = SubmissionInteractor(db.get(), g.get(), sub_presenter.get());
    SubmissionController sub_controller(sub_interactor);

    // Create the UI and hand it the use case controllers
    ConsoleUserInterface ui(log_in_out_controller, sub_controller);

    // Start the event loop
    ui.run();
}