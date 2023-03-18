#include <iostream>
#include <string>

// Is this what will happen?
#include "plugin_glue/grader/grader.hpp"
#include "plugin_glue/database/database.hpp"

#include "submit_assignment/submit_assignment/submit_assignment.hpp"
#include "submit_assignment/request_response_models/submission_models.hpp"

#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

using namespace std;

int main(int, char**) {
    Grader* g = new Grader();
    //Database* db = new Database();

    //boost::posix_time::ptime now = boost::posix_time::second_clock::local_time();

    SubmissionUseCase* sb = new SubmissionUseCase(g);
    incoming_submission sub;
    sub.assignment_name = "Test Assignment";
    sub.program = "print(\"Hello World\")";
    sub.student_name = "Tyler";
    sub.submission_time = boost::posix_time::second_clock::local_time();
    //sb->submit_assignment(sub);

    string response;
    while(true) {
        cout << "Welcome to Beetcode." << endl;
        
        // Log in

        // Depending on user, do other stuff
        break;
    }

    
    cout << "Hello, beetcode world!\n";
}