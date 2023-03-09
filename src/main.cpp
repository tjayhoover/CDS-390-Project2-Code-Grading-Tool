#include <iostream>
#include "grader.hpp"

using namespace std;

int main(int, char**) {
    std::cout << "Hello, beetcode world!\n";

    pythonGrader g = pythonGrader();

    // Test a correct
    bool correct = g.grade_code("x = input()\nprint(x)", "Hello", "Shitbird\n\n\n\n");
    if(correct) {
        cout << "It worked!" << endl;
    }
    else cout << "It didn't work" << endl;
}