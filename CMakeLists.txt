add_library(argparse)
add_subdirectory(src)
add_subdirectory(lib)

target_include_directories(argparse
  PUBLIC
    include
  PRIVATE
    src
)
