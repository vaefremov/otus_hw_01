#include "general_api.h"
#include <string>
#include <regex>

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

TEST(general_api_tests, test_version_str)
{
    auto str = OTUS_HW::version_str();
    std::regex re("^Version: \\d+\\.\\d+\\.\\d+$");
    std::smatch m;
    bool res = std::regex_match(str, m, re);
    EXPECT_TRUE(res);
}