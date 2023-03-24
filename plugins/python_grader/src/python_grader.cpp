#include "python_grader.hpp"

#include <string>
#include <fstream>
#include <filesystem>
#include <sstream>

using namespace std;
namespace fs = std::filesystem;

bool pythonGrader::grade_code(std::string code, std::string input, std::string desired_output) {
        string curr_dir = fs::current_path();
    string temp_dir = fs::temp_directory_path();
    
    fs::current_path(temp_dir);

    // Initialize required files
    ofstream ofs{"output.txt"};
    ofstream ifs{"input.txt"};
    ofstream sfs{"source_code.py"};

    // Write text to files
    ofstream src("source_code.py");
    src << code;
    src.close();

    ofstream in("input.txt");
    in << input;
    in.close();

    // Use a system command to run the python code
    int s = system("python3 source_code.py < input.txt > output.txt");

    // Read the program output back into a string
    ifstream out("output.txt");
    stringstream buffer;
    buffer << out.rdbuf();
    string actual_output = buffer.str();

    // Remove newline character that was added by the file write operation
    if(actual_output.back() == '\n') actual_output.pop_back();

    fs::current_path(curr_dir);
    return (actual_output == desired_output);
}