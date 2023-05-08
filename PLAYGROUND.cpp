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
        virtual void fcnOver1() = 0;

        virtual void fcnOver2()
        {
            std::cout << "call fcnA2\n";
        }
    };

    struct B : A
    {
        B()
        {
            std::cout << "call B" << std::endl;
        }
        void fcnOver1() override
        {
            std::cout << "call fcnB1\n";
        }
        void fcnOver2() override
        {
            std::cout << "call fcnB2\n";
        }

    };

    struct C : A
    {
        C()
        {
            std::cout << "call C" << std::endl;
        }
        void fcnOver1() override
        {
            std::cout << "call fcnC1\n";
        }
    };

    struct D : B, C
    {
        D()
        {
            std::cout << "call D" << std::endl;
        }
        void fcnOver1() override
        {
            std::cout << "call fcnD1\n";
        }
    };
}

using namespace playground;

void Playground::run()
{
    A* pa =  new B();


    pa->fcnOver1();
    pa->fcnOver2();
    pa->A::fcnOver2();
    void (**vtable)() = * (void (***)())pa;

    D* pd = new D();

    delete pa;
    delete pd;
    // A& a = d; this would cause the compiler error
}