#include "CppXX_ComprehensivQuiz.hpp"
#include <iostream>

// Question 1. what will be the output
class Base
{
public:
    Base()
    {
        std::cout << "Base()\n";
    }
    ~Base()
    {
        std::cout << "~Base()\n";
    }
};

class Derived : public Base{
    public:
    Derived(){
        std::cout<< "Derived()\n";
    }
    ~Derived(){
        std::cout<<"~Derived()\n";
    }
};

void ComprehensiveQuiz::Question_01()
{
    Derived d;
    return;
}