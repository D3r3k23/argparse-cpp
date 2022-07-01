#include <argparse/argparse.hpp>

#include <Argv/Argv.hpp>
#include <fmt/core.h>

#define DEMO_VERSION "1.0.0b-f"

namespace Demo
{
    using argparse::ArgumentParser;
    using argparse::Argument;

    int Main(Argv::Argv argv)
    {
        ArgumentParser parser("Demo", "argparse demo program");
        parser.add_help();
        parser.add_version(DEMO_VERSION);
        try
        {
            parser.add(Argument("opt2")
                .type<std::string>()
                .action(argparse::StoreTrue)
                .help("An option")
            );
        }
        catch (const argparse::ArgumentError& error)
        {
            fmt::print("argparse::ArgumentError: {}", error.what());
        }
        try
        {
            ParsedArgs args = parser.parse(argv);
        }
        catch (const argparse::ParseError& error)
        {
            fmt::print("argparse::ParseError: {}", error.what());
        }

        if (args["opt1"])

        return 0;
    }
}
