#include "ArgumentParser.hpp"

#include <utility>
#include <functional>

namespace argparse
{
    ArgumentParser::ArgumentParser(bool failOnError=true)
      : m_failOnError(failOnError)
    {

    }

    ArgumentParser::ArgumentParser(std::string prog, bool failOnError=true)
      : m_failOnError(failOnError),
        m_prog(std::move(prog))
    {

    }

    ArgumentParser::ArgumentParser(std::string prog, std::string version, bool failOnError=true)
      : m_failOnError(failOnError),
        m_prog(std::move(prog)),
        m_version(std::move(version))
    {

    }

    ParsedArgs ArgumentParser::parse(Argv::Argv argv)
    {


        bool error = false;
        if (error)
        {
            if (m_failOnError)
                throw ParseError("");
        }
    }

    void add_description(std::string description)
    {
        m_description = std::move(description);
    }

    void ArgumentParser::add(Argument arg)
    {


        bool error = false;
        if (error)
        {
            if (m_failOnError)
                throw ArgumentError("");
        }
    }

    void ArgumentParser::add(HelpOrVersion flags)
    {
        if (flags & Help)
            add_help();
        if (flags & Version)
            add_version();
    }

    void ArgumentParser::add_help(void)
    {
        add(Argument("--help")
            .alias("-h")
            .action(Invoke, std::bind(add_help, this))
        );
    }

    void ArgumentParser::add_version(void)
    {
        add(Argument("--version")
            .alias("-V", "version")
            .action(Invoke, std::bind(add_version, this))
        );
    }

    void ArgumentParser::print_help(void) const
    {

    }

    void ArgumentParser::print_version(void) const
    {

    }
}
