#ifndef ARGPARSE_ARGUMENT_PARSER_HPP
#define ARGPARSE_ARGUMENT_PARSER_HPP

#include "Argument.hpp"
#include "ParsedArgs.hpp"

#include <Argv/Argv.hpp>

#include <string>
#include <string_view>
#include <optional>
#include <vector>

namespace argparse
{
    class ArgumentParser
    {
    public:
        ArgumentParser(std::optional<std::string> description=std::nullopt,
                       std::optional<std::string> prog=std::nullopt);

        ParsedArgs parse(Argv::Argv argv);
    };
}

#endif // ARGPARSE_ARGUMENT_PARSER_HPP
