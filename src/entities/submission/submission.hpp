// Adam Rilatt & Brandon Bauer
// 3 February 2023
// BeetCode -- Submission Header

/*
A Submission represents a Student's attempt at completing an Assignment. Each
Submission contains the Student's name, a timestamp, the text of the program
they submitted, and the number of test cases that program passed.
*/

#ifndef SUBMISSION_H
#define SUBMISSION_H

#include <string>
#include <chrono>
#include <vector>

class Submission {
    public:

    Submission() = delete;
    
    // Minimal constructor for a viable Submission object.
    Submission(const std::string& name, const std::string& program);
    
    // Constructor containing all parameters for use by Databases.
    Submission(const std::vector<std::string>& params);
    
    ~Submission() = default;
    
    std::vector<std::string> save();
    
    void set_grade(int grade);
    
    std::string get_name();
    std::string get_program();
    int         get_grade();
    time_t      get_submission_time();
   
    private:
    
    std::string student_name;
    std::string program;
    
    // NOTE: This value, in combination with max_grade from an Assignment,
    // enables the displaying of either a radio (15/20) or a percent(75%).
    int grade;

    time_t submission_time;
    
};



#endif