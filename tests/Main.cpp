#include <argparse/argparse.hpp>

#include <Argv/Argv.hpp>

namespace argparse::Test
{
    int Main(Argv::Argv argv)
    {
        ArgumentParser parser({
            .prog = "Test",
            .description = "argparse test program",
            .help = ""
        }).add(Help | Version);

        parser.add(Argument("opt1")
            .type<std::string>()
            .action(StoreTrue)
            .help("An option")
        );

        ParsedArgs args = parser.parse(argv);

        return 0;
    }
}
