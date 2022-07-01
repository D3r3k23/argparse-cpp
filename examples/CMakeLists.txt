function(argparse_build_example EXAMPLE_NAME)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_NAME}.cpp)

    target_link_libraries(${EXAMPLE_NAME}
      PUBLIC
        argparse
        fmt
    )

    target_compile_definitions(${EXAMPLE_NAME}
      PUBLIC
        ARGV_ENABLE_MAIN
        ARGV_MAIN_NAMESPACE=${EXAMPLE_NAME}
    )
endfunction()

argparse_build_example(Demo)
