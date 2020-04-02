#include "general_api.h"
#include <string>

#include <gtest/gtest.h>

TEST(general_api_tests, test_message)
{
    std::string message = OTUS_HW::message();
    EXPECT_EQ("Hello World!", message);
}

TEST(general_api_tests, test_patch_valid)
{
    int patch = OTUS_HW::version_patch();
    EXPECT_TRUE(patch > 0);
}
