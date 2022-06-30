add_subdirectory(Argv)
target_compile_definitions(Argv INTERFACE ARGV_ENABLE_MAIN) # User creates a ::Main(Argv::Argv) fn
