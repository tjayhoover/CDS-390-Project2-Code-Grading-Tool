struct graded_submission {
    std::string student_name;
    std::string assignment_name;
    std::string program;
    double grade;
    boost::gregorian::date submission_date;
    boost::posix_time::ptime submission_time;
}