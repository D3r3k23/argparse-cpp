add_executable(Tests)

target_sources(Tests
  PUBLIC
    Main.cpp
    Tests.cpp
)

target_link_libraries(Tests
  PUBLIC
    argparse
    fmt
)

target_compile_definitions(Tests
  PUBLIC
    ARGV_ENABLE_MAIN
    ARGV_MAIN_NAMESPACE=argparse::Test
)
