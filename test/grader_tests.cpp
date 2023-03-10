#include <gtest/gtest.h>

#include "grader.hpp"

// Demonstrate some basic assertions.
TEST(GraderTest, CorrectGrade) {

    pythonGrader g;
    bool t = g.grade_code("x = input()\nprint(x)", "Hello", "Hello");
    bool ts = g.grade_code("print(\"Hello\")", "", "Hello");
    bool f = g.grade_code("print(\"wrong\")", "", "Right"); 

    EXPECT_EQ(ts, true);
    EXPECT_EQ(t, true);
    EXPECT_EQ(f, false); 
}