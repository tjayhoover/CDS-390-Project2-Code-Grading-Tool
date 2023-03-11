#include <iostream>

// Is this what will happen?
#include "plugin_glue/grader/grader.hpp"
#include "plugin_glue/database/database.hpp"
#include "submit_assignment/submit_assignment/submit_assignment.hpp"

using namespace std;

int main(int, char**) {
    Grader* g = new Grader();
    Database* db = new Database();

    SubmissionUseCase sb(db, g);

    sb.submit_assignment();
    
    cout << "Hello, beetcode world!\n";
}