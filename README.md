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
        // .action(argparse.Store) by default
        .type<std::string>()
        .help("First argument")
    );
    parser.add(Argument("--opt1")
        .alias("-o")
        .action(argparse.StoreTrue)
        // .type<std::bool>() by default
        .help("Optional argument")
    );
    parser.add(Argument("--opt2")
        .type<int>()
        .base(10) // default value
    );
    
    ParsedArgs args = parser.parse(argv);
    
    std::string arg1 = args["arg1"];
    int opt2 = args["opt2"];
    
    if (args["opt1"])
    {
    
    }

    return 0;
}
```

* Using [Argv Main](https://github.com/D3r3k23/Argv#argv-main)
