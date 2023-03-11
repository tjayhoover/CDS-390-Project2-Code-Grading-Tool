// Adam Rilatt & Brandon Bauer
// 6 February 2023
// BeetCode -- Assignment Header

#ifndef ASSIGNMENT_HPP
#define ASSIGNMENT_HPP

// I think this can be reused as long as time_t is replaced with boost etc

#include "submission.h"

class Assignment {
    public:

    Assignment() = delete;
    
    // Minimum viable set of parameters for a valid Assignment object.
    Assignment(const std::string& name, time_t deadline);
    
    // All parameters available; used for loading Assignments from Databases.
    Assignment(const std::vector<std::string>& params);
    
    ~Assignment() = default;
    
    std::vector<std::string> save();

    // Given the name of a user and a filepath to their program submission,
    // create a Submission object, grade the program, and store the Submission.
    std::pair<std::string,Submission> submit_work(const std::string& username, const std::string& program);

    // Helper function to grade work once its submitted, used in submit_work
    int grade_work();

    // Given a pair of strings representing the filepath to an input and
    // expected output file, add this pair to this Assignment's pool of test
    // cases.
    void add_test_case(std::pair<std::string, std::string> test_case);

    void set_name(const std::string& name);
    void set_description(const std::string& description);
    void set_deadline(time_t deadline);
    
    std::string get_name();
    std::string get_description();
    time_t get_deadline();
    int get_max_grade();
    
    // Returns our list of filepaths to submissions.
    std::vector<std::string> get_submissions();

    private:

    std::string name;
    std::string description;

    time_t deadline;
    int max_grade;
    
    // Contains a list of filepaths to submissions.
    std::vector<std::string> submissions;

    // Each pair in this vector contains two strings. The first string
    // represents an input file for this Assignment, while the second string
    // represents an output file to diff the program output against for the
    // given input.
    std::vector<std::pair<std::string, std::string>> test_cases;

};

#endif
