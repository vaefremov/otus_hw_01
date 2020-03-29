cmake_minimum_required (VERSION 3.2)

if("$ENV{TRAVIS_BUILD_NUMBER}" STREQUAL "")
  message("Warning: Could not find TRAVIS_BUILD_NUMBER environment variable")
  set(VERSION_NUMBER "0.0.42")
else()
  set(VERSION_NUMBER "0.0.$ENV{TRAVIS_BUILD_NUMBER}")
endif()

project(helloworld VERSION ${VERSION_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(config.h.in config.h)

SET (CMAKE_CXX_FLAGS_INIT                "-Wall -std=c++14")

add_executable(helloworld_cli main.cpp general_api.cpp)

set_target_properties (helloworld_cli  PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
)
target_include_directories(helloworld_cli
    PRIVATE "${CMAKE_BINARY_DIR}"
)
target_compile_options(helloworld_cli PRIVATE
    -Wall -Wextra -pedantic -Werror
)


install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
