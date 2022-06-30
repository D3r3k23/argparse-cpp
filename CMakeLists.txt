cmake_minimum_required(3.19)

project(argparse)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(ARGPARSE_TOP_LEVEL TRUE)
else()
    set(ARGPARSE_TOP_LEVEL FALSE)
endif()

# option(ARGPARSE_BUILD_TESTS "Build tests" OFF)
# option(ARGPARSE_BUILD_EXAMPLES "Build examples" ARGPARSE_TOP_LEVEL)

add_library(argparse)
add_subdirectory(src)
add_subdirectory(lib)

target_include_directories(argparse
  PUBLIC
    include
  PRIVATE
    src
)

set_target_properties(argparse
  PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

if(${ARGPARSE_BUILD_TESTS})
    add_subdirectory(tests)
endif()

if(${ARGPARSE_BUILD_EXAMPLES})
    add_subdirectory(examples)
endif()
