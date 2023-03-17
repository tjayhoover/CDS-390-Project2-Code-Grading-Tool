#include <gtest/gtest.h>
#include <string>

#include "../src/entities/user/user.hpp"

using namespace std;

bool creating_user(){
    string username {"test_user"};
    PermissionLevel permissions {Admin};
    User user1(permissions,username);
    if(user1.get_username()!=username) return false;
    if(user1.get_permission()!=permissions) return false;
    return true;
}


// Demonstrate some basic assertions.
TEST(UserTests, current) {
    EXPECT_EQ(creating_user(), true);

}