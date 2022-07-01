#ifndef ARGPARSE_ARGUMENT_HPP
#define ARGPARSE_ARGUMENT_HPP

#include <any>
#include <span>
#include <string>
#include <vector>
#include <utility>
#include <exception>
#include <functional>
#include <initializer_list>

namespace argparse
{
    enum class ArgumentAction
    {
        Store=0,
        StoreConst,
        StoreTrue,
        StoreFalse,
        Append,
        AppendConst,
        Count,
        Invoke
    };

    using enum ArgumentAction;

    using ActionFn = std::function<void(void)>;

    class Argument
    {
    public:
        Argument(std::string name)
          : m_name(std::move(name))
        {
            m_positional = m_name.starts_with("-") || m_name.starts_with("-");
        }

        template <typename ... Str>
        Argument& alias(Str&& ... aliases)
        {
            m_alias = { std::move(aliases)... };
            return *this;
        }

        template <typename T=std::string>
        Argument& type(void)
        {
            return *this;
        }

        Argument& action(ArgumentAction act)
        {
            return *this;
        }

        Argument& action(ArgumentAction act, ActionFn> fn)
        {
            if (act == Invoke)
                m_fn = std::move(fn);

            return *this;
        }

        Argument& choices(std::span<void*>)
        {
            return *this;
        }

        Argument& default()
        {
            return *this;
        }

        Argument& help(std::string msg)
        {
            return *this;
        }

    private:
        bool m_positional;

        std::string m_name;
        std::vector<std::string> m_alias;
        ArgumentAction m_action;
        ActionFn m_fn;
        std::string m_help;
    };
}

#endif // ARGPARSE_ARGUMENT_HPP
