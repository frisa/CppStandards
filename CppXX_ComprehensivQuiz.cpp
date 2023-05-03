#include "CppXX_ComprehensivQuiz.hpp"
#include <iostream>

// Question 1. what will be the output
class Base
{
protected:
    int m_x{};

public:
    Base(int x): m_x{x}
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
    void print() const{
        std::cout << "Derived: "<< this->m_x << '\n'; // this would cause error in case the varible is private
        std::cout << "Address of this: " << this << '\n';
    }
};

class D2: public Derived{
    public:
    D2(int z): Derived{z}
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