cmake_minimum_required (VERSION 3.2)

project(helloworld VERSION 0.0.42$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

SET (CMAKE_CXX_FLAGS_INIT                "-Wall -std=c++14")

add_executable(helloworld_cli main.cpp)

set_target_properties (helloworld_cli  PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
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
