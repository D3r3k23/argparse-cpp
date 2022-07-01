# argparse-cpp

[![Tests](https://github.com/D3r3k23/argparse-cpp/actions/workflows/test.yaml/badge.svg)](https://github.com/D3r3k23/argparse-cpp/actions/workflows/test.yaml)

C++ command line argument parser similiar to Python's argparse

## Current plan for API usage

```cpp
#include <argparse/ArgumentParser.hpp>

using namespace argparse;
using namespace Argv;

int Main(Argv argv)
{
    ArgumentParser parser("My program");
    parser.add_version("1.0");
    parser.add_help();

    parser.add(Argument("arg1")
        .type<std::string>()
        // .action(argparse.Store) by default
        .help("First argument")
    );
    parser.add(Argument("--opt1")
        .alias("-o")
        // .type<std::string>() by default
        .action(argparse.StoreTrue)
        .help("Optional argument")
    );
    parser.add(Argument("--opt2")
        .type<int>()
        .base(10) // default value
    );

    return 0;
}
```

* Using [Argv Main](https://github.com/D3r3k23/Argv#argv-main)
