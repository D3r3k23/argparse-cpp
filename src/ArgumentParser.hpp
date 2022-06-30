#ifndef ARGPARSE_ARGUMENT_PARSER_HPP
#define ARGPARSE_ARGUMENT_PARSER_HPP

#include "Argument.hpp"
#include "ParsedArgs.hpp"

#include <Argv/Argv.hpp>

#include <string>
#include <string_view>
#include <optional>
#include <vector>
#include <exception>

namespace argparse
{
    class ArgumentError : public std::exception
    {
    public:
        ArgumentError(const char* msg) : m_msg(msg) {}
        const char* what(void) { return m_msg; }

    private:
        const char* m_msg;
    };

    class ParseError : public std::exception
    {
    public:
        ParseError(const char* msg) : m_msg(msg) {}
        const char* what(void) { return m_msg; }

    private:
        const char* m_msg;
    };

    enum HelpOrVersion
    {
        Help,
        Version
    };

    class ArgumentParser
    {
    public:
        ArgumentParser(bool failOnError=true);
        ArgumentParser(std::string prog, bool failOnError=true);
        ArgumentParser(std::string prog, std::string version, bool failOnError=true);

        ParsedArgs parse(Argv::Argv argv);

        void add_description(std::string description);

        void add(Argument arg);
        void add(HelpOrVersion flags);

        void add_help(void);
        void add_version(void);

    private:
        void print_help(void) const;
        void print_version(void) const;

    private:
        bool m_failOnError;

        std::string m_prog;
        std::string m_description;
        std::string m_version;

        std::vector<Argument> m_args;
    };
}

#endif // ARGPARSE_ARGUMENT_PARSER_HPP
