#BeetCode V2

This is Project 2 from CDS-390 - Software Architecture.

This was a team project with [Brandon Bauer](https://github.com/btb002).

#Description

A code-grading tool for a Software Architecture class. Students can upload and
grade assignments, instructors can create assignments and view submissions,
and an administrator can create and remove other users. This platform currently
only grades python programs.

Admin is a default user created if it does not already exist in the system.
The default admin information is as follows:
Username: admin
Password: password

When making output files for grading programs be mindful of ending newline
characters or carriage returns

ChangeLog:
-- Improved architecture to improve ability to upgrade the program in the 
future (including build tree!)
-- New authentication with local server written in python and flask
 (Thanks Dr. Yarnall!)
-- New database to faciliate growth!
-- New grader to improve grading quality and reduce formating errors!

------------------------------IMPORTANT-----------------------------------------

This now requires Boost to be installed and the authentication server to be 
running (located under plugins/authentication_server). Filesystem from C++ 17 is
used, therefore C++ 17 or greater is required.

To get the authentication server running perform the following:
    --Open a terminal and create a virtual environment:
        python -m venv venv

    --Activate the virtual environment, either by clicking on the dialog in
    VSCode or manually in the terminal by typing:
        . ./venv/bin/activate

    --Update install tools:
        pip install --upgrade pip setuptools wheel

    --Install dependencies:
        pip install -r requirements.txt

    --Run the server:
        python auth_service.py
