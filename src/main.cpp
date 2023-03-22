#include <iostream>
#include <string>
#include <memory>

// Include the classes which "glue" the external dependencies
#include "adapters/grader/grader.hpp"
#include "adapters/database/db_adapter.hpp"
#include "adapters/authenticator/authenticator.hpp"

// Include the UI
#include "console_interface/console_ui.hpp"

// Include the relevant bits for the submission use case
#include "use_case_groups/submit_assignment/interactors/submit_assignment.hpp"
#include "use_case_groups/submit_assignment/views/submission_view.hpp"
#include "use_case_groups/submit_assignment/request_response_models/submission_models.hpp"
#include "use_case_groups/submit_assignment/controllers/submission_controller.hpp"
#include "use_case_groups/submit_assignment/presenters/submission_presenter.hpp"

// Include the relevant bits for the login/logout use cases
#include "use_case_groups/log_in_out/controllers/log_in_out_controller.hpp"
#include "use_case_groups/log_in_out/interactors/log_in/log_in.hpp"
#include "use_case_groups/log_in_out/interactors/log_out/log_out.hpp"
#include "use_case_groups/log_in_out/presenters/log_in/login_presenter.hpp"
#include "use_case_groups/log_in_out/presenters/log_out/logout_presenter.hpp"
#include "use_case_groups/log_in_out/views/log_in/login_view.hpp"
#include "use_case_groups/log_in_out/views/log_out/logout_view.hpp"

// Include the relevant bits for the create/delete user use cases
#include "use_case_groups/create_delete_user/controllers/user_controller.hpp"
#include "use_case_groups/create_delete_user/interactors/create_user/create_user.hpp"
#include "use_case_groups/create_delete_user/interactors/delete_user/delete_user.hpp"
#include "use_case_groups/create_delete_user/presenters/create_user/create_user_presenter.hpp"
#include "use_case_groups/create_delete_user/presenters/delete_user/delete_user_presenter.hpp"
#include "use_case_groups/create_delete_user/views/create_user/create_user_view.hpp"
#include "use_case_groups/create_delete_user/views/delete_user/delete_user_view.hpp"

// Include the relevant bits for the create/delete assignment use cases
#include "use_case_groups/create_delete_assignment/controllers/assignment_controller.hpp"
#include "use_case_groups/create_delete_assignment/interactors/create_assignment/create_assignment.hpp"
#include "use_case_groups/create_delete_assignment/interactors/delete_assignment/delete_assignment.hpp"
#include "use_case_groups/create_delete_assignment/presenters/create_assignment/create_assignment_presenter.hpp"
#include "use_case_groups/create_delete_assignment/presenters/delete_assignment/delete_assignment_presenter.hpp"
#include "use_case_groups/create_delete_assignment/views/create_assignment/create_assignment_view.hpp"
#include "use_case_groups/create_delete_assignment/views/delete_assignment/delete_assignment_view.hpp"

// Include the relevant bits for the student/instructor grade report use cases
#include "use_case_groups/grade_report/controllers/report_controller.hpp"
#include "use_case_groups/grade_report/interactors/instructor/instructor_report.hpp"
#include "use_case_groups/grade_report/interactors/student/student_report.hpp"
#include "use_case_groups/grade_report/presenters/instructor/instructor_report_presenter.hpp"
#include "use_case_groups/grade_report/presenters/student/student_report_presenter.hpp"
#include "use_case_groups/grade_report/views/instructor/instructor_report_view.hpp"
#include "use_case_groups/grade_report/views/student/student_report_view.hpp"

using namespace std;

int main(int, char**) {

    // Create the database, grader, authenticator, and user interface
    unique_ptr<Grader> g = make_unique<Grader>();
    unique_ptr<DB_adapter> db = make_unique<DB_adapter>();
    unique_ptr<Authenticator> auth = make_unique<Authenticator>();

    // Initialize dependencies of the use cases

    // Submission Use Case
    unique_ptr<SubmissionPresenter> sub_presenter = make_unique<SubmissionPresenter>();
    sub_presenter->setView<SubmissionView>();
    SubmissionInteractor sub_interactor = SubmissionInteractor(db.get(), g.get(), sub_presenter.get());
    SubmissionController sub_controller(sub_interactor);

    // Log in and Log out Use Cases
    unique_ptr<LoginPresenter> login_presenter = make_unique<LoginPresenter>();
    unique_ptr<LogoutPresenter> logout_presenter = make_unique<LogoutPresenter>();
    login_presenter->setView<LoginView>();
    logout_presenter->setView<LogoutView>();
    LoginInteractor login_interactor = LoginInteractor(db.get(), auth.get(), login_presenter.get());
    LogoutInteractor logout_interactor = LogoutInteractor(logout_presenter.get());
    LogInOutController log_in_out_controller = LogInOutController(login_interactor, logout_interactor);
    

    // Grade report use cases
    unique_ptr<StudentReportPresenter> sr_presenter = make_unique<StudentReportPresenter>();
    unique_ptr<InstructorReportPresenter> ir_presenter = make_unique<InstructorReportPresenter>();
    sr_presenter->setView<StudentReportView>();
    ir_presenter->setView<InstructorReportView>();
    StudentReportInteractor sr_interactor = StudentReportInteractor(db.get(), auth.get(), sr_presenter.get());
    InstructorReportInteractor ir_interactor = InstructorReportInteractor(db.get(), auth.get(), ir_presenter.get());
    ReportController report_controller = ReportController(ir_interactor, sr_interactor);


    // Add and delete user use cases
    unique_ptr<CreateUserPresenter> cu_presenter = make_unique<CreateUserPresenter>();
    unique_ptr<DeleteUserPresenter> du_presenter = make_unique<DeleteUserPresenter>();
    cu_presenter->setView<CreateUserView>();
    du_presenter->setView<DeleteUserView>();
    CreateUserInteractor cu_interactor = CreateUserInteractor(db.get(), auth.get(), cu_presenter.get());
    DeleteUserInteractor du_interactor = DeleteUserInteractor(db.get(), auth.get(), du_presenter.get());
    UserController user_controller = UserController(cu_interactor, du_interactor);


    // Add and delete assignment use cases
    unique_ptr<CreateAssignmentPresenter> ca_presenter = make_unique<CreateAssignmentPresenter>();
    unique_ptr<DeleteAssignmentPresenter> da_presenter = make_unique<DeleteAssignmentPresenter>();
    ca_presenter->setView<CreateAssignmentView>();
    da_presenter->setView<DeleteAssignmentView>();
    CreateAssignmentInteractor ca_interactor = CreateAssignmentInteractor(db.get(), auth.get(), ca_presenter.get());
    DeleteAssignmentInteractor da_interactor = DeleteAssignmentInteractor(db.get(), auth.get(), da_presenter.get());
    AssignmentController assignment_controller = AssignmentController(ca_interactor, da_interactor);


    // Create the UI and hand it the use case controllers
    ConsoleUserInterface ui(log_in_out_controller, sub_controller, report_controller, user_controller, assignment_controller);

    // Start the event loop
    ui.run();
}