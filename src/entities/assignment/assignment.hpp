// Adam Rilatt & Brandon Bauer
// 6 February 2023
// BeetCode -- Assignment Header

#ifndef ASSIGNMENT_HPP
#define ASSIGNMENT_HPP

#include "boost/date_time/posix_time/posix_time.hpp"
// https://www.boost.org/doc/libs/1_81_0/doc/html/date_time/posix_time.html#date_time.posix_time.ptime_class

#include "../submission/submission.hpp"

class Assignment {
    public:

    Assignment() = default;
    
    // Minimum viable set of parameters for a valid Assignment object.
    Assignment(const std::string& name, boost::posix_time::ptime deadline);
    
    // All parameters available; used for loading Assignments from Databases.
    Assignment(const std::vector<std::string>& params);
    
    ~Assignment() = default;
    
    std::vector<std::string> save();

    void add_submission(const std::string& sub_name);

    // Helper function to grade work once its submitted, used in submit_work
    //int grade_work();

    // Given a pair of strings representing the filepath to an input and
    // expected output file, add this pair to this Assignment's pool of test
    // cases.
    void add_test_case(std::pair<std::string, std::string> test_case);

    void set_name(const std::string& name);
    void set_description(const std::string& description);
    void set_deadline(boost::posix_time::ptime deadline);
    
    std::string get_name();
    std::string get_description();
    int get_max_grade();
    boost::posix_time::ptime get_deadline();
    
    // Returns our list of filepaths to submissions.
    std::vector<std::string> get_submissions();

    int get_num_submissions();

    std::vector<std::pair<std::string, std::string>> get_test_cases();

    private:

    std::string name;
    std::string description;
    boost::posix_time::ptime deadline;
    int max_grade = 0;
    
    // Contains a list of submission IDs.
    std::vector<std::string> submissions;

    // Each pair in this vector contains two strings. The first string
    // represents an input file for this Assignment, while the second string
    // represents an output file to diff the program output against for the
    // given input.
    std::vector<std::pair<std::string, std::string>> test_cases;

};

#endif
