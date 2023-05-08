#include "PLAYGROUND.hpp"
#include <iostream>

// exmample for the diamond problem

class A
{
protected:
    int _a;
    A(){
        _a = 0;
    }
};

class B : virtual public A
{
    int _b;

public:
    B() : _b{2}
    {
        _a = 1;
    }
};

class C : virtual public A
{
    int _c;

public:
    C() : _c{3}
    {
        _a = 2;
    }
};

class D : public B, public C
{
public:
    void print()
    {
        std::cout << "B::_a" << B::_a << std::endl;
        std::cout << "C::_a:" << C::_a << std::endl;
    }
};

void Playground::run()
{
    std::cout << "This is the playground for testing stuff\n";
    D d;
    d.print();
}