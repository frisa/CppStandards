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
}  // namespace playground

void SetValue(int& value)
{
    std::cout << "lvalue overloaded function is called\n";
}
void SetValue(int&& value)
{
    std::cout << "rvalue overloaded fucntion is called\n";
}

using namespace playground;

class Entity
{
private:
    std::string m_name;
    int m_score;

public:
    Entity()
        : m_score(0), m_name("somethink")
    {
    }
    Entity(const std::string& value)
        : m_name(value)
    {
    }
};

class Atom
{
public:
    Atom(const std::string& value)
    {
        std::cout << "Atom constructor" << value << std::endl;
    }
};

class Try
{
    int m_var1;
    int m_var2;
    Atom m_atom;

public:
    Try(const std::string& value)
        : m_atom{ value }, m_var1{ 1 }, m_var2{ 2 }
    {
        std::cout << "Try constructor called" << std::endl;
    }
    void* operator new(size_t sz)
    {
        std::cout << "size: " << sz << " size of Try:" << sizeof(Try) << std::endl;
        return (Try*)malloc(sz);
    }
};

void Playground::run()
{
    A* pa = new B();
    Try tr = Try("Hello");
    Try* ptr = new Try("somethink");

    for (unsigned int idx{}; idx<32; idx++)
    {
        int input{1};
        int value = (input << idx);
        std::cout << "value: " << value << std::endl;

        const char reg = 0x10; // 0x0000 0000
        const char regSh = reg << 1;

        const unsigned char c = ~0x00;
        const unsigned char res = 0x11 ^ 0x21;
    }

    int&& rvalue = 10;
    int value = 10;
    int& lvalue = value;

    SetValue(std::move(rvalue));
    SetValue(lvalue);
    SetValue(10);
    pa->fcnOver1();
    pa->fcnOver2();
    pa->A::fcnOver2();
    void (**vtable)() = *(void (***)())pa;

    D* pd = new D();


    delete pd;
    // A& a = d; this would cause the compiler error
}