#ifndef ARGPARSE_ERROR_HPP
#define ARGPARSE_ERROR_HPP

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
}

#endif // ARGPARSE_ERROR_HPP
