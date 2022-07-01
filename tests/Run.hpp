#ifndef ARGPARSE_TEST_RUN_HPP
#define ARGPARSE_TEST_RUN_HPP

#include "Log.hpp"
#include "Tests.hpp"

#include <concepts>

namespace argparse::Test
{
    template <typename Fn>
    concept TestFn = requires(Fn fn)
    {
        { fn() } -> std::convertible_to<bool>;
    }

    void run_test(TestFn auto test_fn, const char* name)
}

#define RUN_TEST(name) run_test(Tests::name, STRINGIZE(name))

#endif // ARGPARSE_TEST_RUN_HPP
