#include "general_api.h"
#include <string>
#include <iostream>

#include <gtest/gtest.h>

struct TestFixtureName: public testing::Test {
    void SetUp() override {
        std::cout << "Fixture " << std::endl;
        message = "Qq, buddy";
    }
    std::string message;
};

TEST(general_api_tests, test_message)
{
    std::string message = OTUS_HW::message();
    EXPECT_EQ("Hello World!", message);
}

TEST(general_api_tests, test_patch_valid)
{
    int patch = OTUS_HW::version_patch();
    std::cout << "****** \n";
    EXPECT_TRUE(patch > 0);
}

TEST_F(TestFixtureName, test_with_fixture)
{
    std::cout << message << std::endl;
}