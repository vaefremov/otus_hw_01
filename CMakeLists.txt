cmake_minimum_required (VERSION 3.2)

if("$ENV{TRAVIS_BUILD_NUMBER}" STREQUAL "")
  message("Warning: Could not find TRAVIS_BUILD_NUMBER environment variable")
  set(VERSION_NUMBER "0.0.42")
else()
  set(VERSION_NUMBER "0.0.$ENV{TRAVIS_BUILD_NUMBER}")
endif()

project(helloworld VERSION ${VERSION_NUMBER})

find_package(Boost COMPONENTS unit_test_framework)
find_package(GTest REQUIRED)

configure_file(config.h.in config.h)

add_executable(helloworld_cli main.cpp general_api.cpp)
target_include_directories(helloworld_cli
    PRIVATE "${CMAKE_BINARY_DIR}"
)

if (Boost_FOUND)
    add_executable(test_helloworld tests/test_general_api.cpp general_api.cpp)
    target_include_directories(test_helloworld
        PRIVATE "${CMAKE_BINARY_DIR}" "${CMAKE_HOME_DIRECTORY}"
    )
    target_link_libraries(test_helloworld
        ${Boost_LIBRARIES}
    )
    set_target_properties(test_helloworld PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    )
endif ()

add_executable(test_g_helloworld tests/test_g_general_api.cpp general_api.cpp)
target_include_directories(test_g_helloworld
    PRIVATE 
    "${CMAKE_BINARY_DIR}" "${CMAKE_HOME_DIRECTORY}"
    "${GTEST_INCLUDE_DIR}"
)
target_link_libraries(test_g_helloworld
    ${GTEST_LIBRARIES}
    ${GTEST_MAIN_LIBRARIES}
    pthread
)
set_target_properties(test_g_helloworld PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
)

if (MSVC)
    target_compile_options(helloworld_cli PRIVATE
        /W4
    )
    target_compile_options(test_g_helloworld PRIVATE
        /W4
    )
    if (Boost_FOUND)
        target_compile_options(test_helloworld PRIVATE
            /W4
        )
    endif ()
else ()
    target_compile_options(helloworld_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(test_g_helloworld PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    if (Boost_FOUND)
        target_compile_options(test_helloworld PRIVATE
            -Wall -Wextra -pedantic -Werror
        )
    endif ()
endif()


install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

if (Boost_FOUND)
    add_test(test_api test_helloworld)
endif ()
add_test(test_g_api test_g_helloworld)
