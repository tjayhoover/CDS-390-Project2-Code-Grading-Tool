#include <gtest/gtest.h>

#include "grader.hpp"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {

    pythonGrader g;
    bool t = g.grade_code("print(\"Hello\")", "", "Hello");
    bool f = g.grade_code("print(\"wrong\")", "", "Right"); 

    EXPECT_EQ(f, false); 
    EXPECT_EQ(t, true);
}