add_subdirectory(Argv)
add_subdirectory(fmt)

target_link_libraries(argparse
  PUBLIC
    Argv
  PRIVATE
    fmt
)
