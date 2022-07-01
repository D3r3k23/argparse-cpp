#include "ArgumentParser.hpp"

#include "Error.hpp"

#include <utility>
#include <functional>

namespace argparse
{
    ////// Parser setup //////

    ArgumentParser::ArgumentParser(std::string description, bool throwOnError)
      : m_throwOnError(throwOnError),
        m_description(std::move(description))
    { }

    ArgumentParser::ArgumentParser(std::string prog, std::string description, bool throwOnError)
      : m_throwOnError(throwOnError),
        m_prog(std::move(prog)),
        m_description(std::move(description))
    { }

    void ArgumentParser::add_description(std::string description)
    {
        m_description = std::move(description);
    }

    void ArgumentParser::add_version(std::string version)
    {
        m_version = std::move(version);
    }

    void ArgumentParser::add_help(std::optional<std::string> help)
    {
        if (help)
            m_help = std::move(*help);
        else
            ; // Generate help in parse()

        add(Argument("--help")
            .alias("-h")
            // .action(Invoke, std::bind(build_help_string, this))
        );
    }

    void ArgumentParser::add(Argument arg)
    {

        bool error = false;
        if (error)
        {
            if (m_throwOnError)
                throw ArgumentError("");
        }
    }

    void ArgumentParser::print_help(void) const
    {

    }

    void ArgumentParser::print_version(void) const
    {

    }

    ////// Parsing args ////

    ParsedArgs ArgumentParser::parse(Argv::Argv argv)
    {


        bool error = false;
        if (error)
        {
            if (m_throwOnError)
                throw ParseError("");
        }
    }
}
