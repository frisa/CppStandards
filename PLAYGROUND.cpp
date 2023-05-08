#include "PLAYGROUND.hpp"
#include <iostream>

// exmample for the diamond problem
namespace playground
{
    struct A
    {
        int variable;
        A()
        {
            std::cout << "call A" << std::endl;
        }
    };

    struct B : virtual A
    {
        B()
        {
            std::cout << "call B" << std::endl;
        }
    };

    struct C : virtual A
    {
        C()
        {
            std::cout << "call C" << std::endl;
        }
    };

    struct D : B, C
    {
        D()
        {
            std::cout << "call D" << std::endl;
        }
    };
}

void Playground::run()
{
    playground::D d;
    d.variable = 1;
    // A& a = d; this would cause the compiler error
}