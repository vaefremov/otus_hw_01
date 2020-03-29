#include "general_api.h"
#include "config.h"

int OTUS_HW::version_patch()
{
    return PROJECT_VERSION_PATCH;
}

std::string OTUS_HW::version_str() 
{
    return std::string("Version: ") + VERSION_NUMBER;
}

std::string OTUS_HW::message()
{
    return "Hello World!";
}
