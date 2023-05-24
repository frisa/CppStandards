#include "Cpp11_DefaultedDeletestFunctions.hpp"
#include <iostream>

S::S(int value): data(value) // member initializer list
{
    std::cout << "ctorl called data: " << data << "/n";
}

S::S(std::string str) try: data(std::stoi(str))
{

}
catch(const std::exception&)
{
    std::cout << "ctor2 failed, string vas" << str << "\n";
    throw;
}

void Cpp11_DefaultedDeletedFunctions::simpleExample()
{
    D d1 = 1;
    S s2("2");
 
    try
    {
        S s3("not a number");
    }
    catch(const std::exception&) {}
 
    std::cout << s2.getData() << '\n';
 
    D d2(3, 4);
    d2 = d1;   // OK: assignment to lvalue
//  D(5) = d1; // ERROR: no suitable overload of operator=
}
