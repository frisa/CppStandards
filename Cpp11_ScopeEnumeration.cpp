#include "Cpp11_ScopeEnumeration.hpp"
#include <iostream>

enum Color{
    red,
    green,
    blue,
};

enum class ScopeColor{
    Red,
    Green,
    Blue,
};

void Cpp11_ScopedEnumeration::scopeEnum_SimpleExample()
{
    // unscoped
    Color r{red};
    switch (r)
    {
        case red:
            std::cout << "red" << std::endl;
        case green:
            std::cout << "green" << std::endl;
        default:
            std::cout << "default" << std::endl;
    }

    //scoped enumeration
    ScopeColor sr{Color::red};
    switch(sr){
        case ScopeColor::Red:
            std::cout<< "red" << std::endl;

        case ScopeColor::Green:
            std::cout << "green" << std::endl;
        default:
            std::cout << "default" << '\n';
    }
}