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
#include "use_case_groups/create_delete_user/interactors/change_password/change_password.hpp"

#include "use_case_groups/create_delete_user/presenters/create_user/create_user_presenter.hpp"
#include "use_case_groups/create_delete_user/presenters/delete_user/delete_user_presenter.hpp"
#include "use_case_groups/create_delete_user/presenters/change_password/change_password_presenter.hpp"

#include "use_case_groups/create_delete_user/views/create_user/create_user_view.hpp"
#include "use_case_groups/create_delete_user/views/delete_user/delete_user_view.hpp"
#include "use_case_groups/create_delete_user/views/change_password/change_password_view.hpp"

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

// Include the relevant bits for the student view assignments use case
#include "use_case_groups/view_assignments/controllers/view_assignments_controller.hpp"
#include "use_case_groups/view_assignments/interactors/student/student_view_assignments.hpp"
#include "use_case_groups/view_assignments/presenters/student/student_assignments_presenter.hpp"
#include "use_case_groups/view_assignments/views/student/student_assignments_view.hpp"

using namespace std;

int main(int, char**) {

    // Create the database, grader, authenticator, and user interface
    unique_ptr<Grader> g = make_unique<Grader>();
    
    unique_ptr<Authenticator> auth = make_unique<Authenticator>();

    unique_ptr<DB_adapter> db;

    // Try creating the database. If there is an error, catch it and print
    // the error to the console.
    try {
        db = make_unique<DB_adapter>();
    } catch(const exception& ex) {
        cerr << "Database creation failed. Error message:" << endl;
        cerr << ex.what() << endl;
        cerr << "\nIf you do not care about your data, deleting the " <<
                    "_database directory under build/src should fix the issue." << endl;
        return 1;
    }

    // If it doesn't exist, add the default admin to the database
    if(!db->exists("admin")) {
        User admin(PermissionLevel::Admin, "admin");
        admin.set_password("password");
        db->add_user(admin);
    }

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
    unique_ptr<ChangePasswordPresenter> cp_presenter = make_unique<ChangePasswordPresenter>();
    cu_presenter->setView<CreateUserView>();
    du_presenter->setView<DeleteUserView>();
    cp_presenter->setView<ChangePasswordView>();
    CreateUserInteractor cu_interactor = CreateUserInteractor(db.get(), auth.get(), cu_presenter.get());
    DeleteUserInteractor du_interactor = DeleteUserInteractor(db.get(), auth.get(), du_presenter.get());
    ChangePasswordInteractor cp_interactor = ChangePasswordInteractor(db.get(), auth.get(), cp_presenter.get());
    UserController user_controller = UserController(cu_interactor, du_interactor, cp_interactor);


    // Add and delete assignment use cases
    unique_ptr<CreateAssignmentPresenter> ca_presenter = make_unique<CreateAssignmentPresenter>();
    unique_ptr<DeleteAssignmentPresenter> da_presenter = make_unique<DeleteAssignmentPresenter>();
    ca_presenter->setView<CreateAssignmentView>();
    da_presenter->setView<DeleteAssignmentView>();
    CreateAssignmentInteractor ca_interactor = CreateAssignmentInteractor(db.get(), auth.get(), ca_presenter.get());
    DeleteAssignmentInteractor da_interactor = DeleteAssignmentInteractor(db.get(), auth.get(), da_presenter.get());
    AssignmentController assignment_controller = AssignmentController(ca_interactor, da_interactor);

    // View assignments use cases
    unique_ptr<StudentAssignmentsPresenter> sva_presenter = make_unique<StudentAssignmentsPresenter>();
    sva_presenter->setView<StudentAssignmentsView>();
    StudentViewAssignmentsInteractor sva_interactor = StudentViewAssignmentsInteractor(db.get(), sva_presenter.get());
    ViewAssignmentsController view_assignments_controller = ViewAssignmentsController(sva_interactor);

    // Create the UI and hand it the use case controllers
    ConsoleUserInterface ui(log_in_out_controller, sub_controller, report_controller, user_controller, assignment_controller, view_assignments_controller);

    // Start the event loop
    ui.run();
}