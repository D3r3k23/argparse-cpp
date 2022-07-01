cmake_minimum_required(VERSION 3.19)

project(argparse)

if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
    set(ARGPARSE_TOP_LEVEL TRUE)
else()
    set(ARGPARSE_TOP_LEVEL FALSE)
endif()

option(ARGPARSE_BUILD_TESTS "Build tests" ${ARGPARSE_TOP_LEVEL})
option(ARGPARSE_BUILD_EXAMPLES "Build examples" ${ARGPARSE_TOP_LEVEL})

add_library(argparse STATIC)
add_subdirectory(src)
add_subdirectory(lib)

set_target_properties(argparse
  PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

if(${ARGPARSE_BUILD_TESTS})
    message("argparse: Building tests")
    add_subdirectory(tests)
endif()

if(${ARGPARSE_BUILD_EXAMPLES})
    message("argparse: Building examples")
    add_subdirectory(examples)
endif()
