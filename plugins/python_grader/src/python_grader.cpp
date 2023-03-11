#include "python_grader.hpp"

#include <string>
#include <fstream>
#include <filesystem>
#include <sstream>

using namespace std;

pythonGrader::pythonGrader() {

    // Initialize working directory
    if(!filesystem::exists("./python_temp")) {
        filesystem::create_directory("./python_temp");
    }

    // Initialize required files
    ofstream ofs{"./python_temp/output.txt"};
    ofstream ifs{"./python_temp/input.txt"};
    ofstream sfs{"./python_temp/source_code.py"};
}

bool pythonGrader::grade_code(std::string code, std::string input, std::string desired_output) {

    // Write text to files
    ofstream src("./python_temp/source_code.py");
    src << code;
    src.close();

    ofstream in("./python_temp/input.txt");
    in << input;
    in.close();

    // Use a system command to run the python code
    system("python3 ./python_temp/source_code.py < ./python_temp/input.txt > ./python_temp/output.txt");

    // Read the program output back into a string
    ifstream out("./python_temp/output.txt");
    stringstream buffer;
    buffer << out.rdbuf();
    string actual_output = buffer.str();

    // Remove newline character that was added by the file write operation
    if(actual_output.back() == '\n') actual_output.pop_back();

    return (actual_output == desired_output);
}