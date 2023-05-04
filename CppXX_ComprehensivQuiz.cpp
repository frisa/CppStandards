#include "CppXX_ComprehensivQuiz.hpp"
#include <iostream>

// Question 1. what will be the output
class Base
{
protected:
    int m_x{};

public:
    Base(int x) : m_x{x}
    {
        std::cout << "Base()\n";
    }
    ~Base()
    {
        std::cout << "~Base()\n";
    }
    void print() const
    {
        std::cout << "Base: " << m_x << '\n';
    }
};

class Derived : public Base
{
public:
    Derived(int y) : Base{y}
    {
        std::cout << "Derived()\n";
    }
    ~Derived()
    {
        std::cout << "~Derived()\n";
    }
    void print() const
    {
        std::cout << "Derived: " << this->m_x << '\n'; // this would cause error in case the varible is private
        std::cout << "Address of this: " << this << '\n';
    }
};

class D2 : public Derived
{
public:
    D2(int z) : Derived{z}
    {
        std::cout << "D2()\n";
    }
    ~D2()
    {
        std::cout << "~D2()\n";
    }
};

void ComprehensiveQuiz::Question_01()
{
    D2 d{1};
    d.print();
    return;
}

struct type
{
    int i;
    type() : i(3) {}
    void f(int v) const
    {
        //    i = 1; I could make it mutable to access it form the const method
        const_cast<type *>(this)->i = v;
    }
};

void ComprehensiveQuiz::constCast_simpleExample()
{
    int i = 3;
    const int &rci = i;
    const_cast<int &>(rci) = 4; // this will modify the variable as it removes the cv specifiers

    type t;
    t.f(3);
    std::cout<< t.i << '\n';
    const int j = 3; 
    [[maybe_unused]]
    int * pj = const_cast<int*>(&j);
    *pj = 4; // undefined behaviour

    [[maybe_unused]]
    void (type::* pmf)(int) const = &type::f; // pointer to member function
    //const_cast<void(type::*)(int)>(pmf); // compiler error const cast does not work on the function pointers
    
}
