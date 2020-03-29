#define BOOST_TEST_MODULE test_api

#include "general_api.h"

#include <boost/test/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_SUITE(test_api)

using namespace std;

BOOST_AUTO_TEST_CASE(test_patch_valid)
{
    int patch = OTUS_HW::version_patch();
    BOOST_CHECK(patch > 0);
}

BOOST_AUTO_TEST_CASE(test_message_valid)
{
    string message = OTUS_HW::message();
    BOOST_CHECK(message == "Hello World!");
}

}
