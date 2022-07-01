#ifndef ARGPARSE_TEST_LOG_HPP
#define ARGPARSE_TEST_LOG_HPP

#include <fmt/core.h>

namespace argparse::Test
{
    template <typename ... Args>
    void log(Args ... args)
    {
        fmt::print(std::forward<Args>(args)...);
    }
}

#endif // ARGPARSE_TEST_LOG_HPP
