#include "Cpp17_Optional.hpp"
#include <iostream>
#include <optional>
#include <string>
#include <functional>

// optional can be used as the return type of the factory that can fail
std::optional<std::string> create(bool b)
{
    if (b)
    {
        return "Some string";
    }
    else
    {
        return {};
    }
}

auto create2(bool b)
{
    return b ? std::optional<std::string>{ "Some string" } : std::nullopt;
}

auto create3(bool b)
{
    static std::string value = "Godzilla";
    return b ? std::optional<std::reference_wrapper<std::string>>{ value }
             : std::nullopt;
}

void UseOptional::run()
{
    std::cout << "This is not failing string factory: " << create(true).value_or("Default value by fail") << "\n";
    std::cout << "This is failing string factory: " << create(false).value_or("Default value by fail") << "\n";

    auto ret = create2(false);
    if (ret)
    {
        std::cout << "This is failing factory with auto used in condition\n";
    }
    else
    {
        std::cout << "This shall be called\n"; 
    }
}