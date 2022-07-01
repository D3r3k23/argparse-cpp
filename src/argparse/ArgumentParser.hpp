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
    public: // Setup
        ArgumentParser(std::string description="", bool throwOnError=true); // prog defaults to argv[0]
        ArgumentParser(std::string prog, std::string description, bool throwOnError=true);

        void add_description(std::string description);
        void add_version(std::string version);
        void add_help(std::optional<std::string> help={}); // help defaults to auto-generation
        void add(Argument arg);

    private:
        void print_help(void) const;
        void print_version(void) const;

    public: // Parsing
        ParsedArgs parse(Argv::Argv argv);

    private:

    private:
        bool m_throwOnError;

        std::string m_prog;
        std::string m_description;

        std::optional<std::string> m_version;
        std::optional<std::string> m_help;

    protected:
        std::vector<Argument> m_args;
    };
}

#endif // ARGPARSE_ARGUMENT_PARSER_HPP
