#include <iostream>
#include "Cpp14_VariableTemplates.hpp"

template<class T>
const T PI = T(3.1423456789);  // variable template

template<class T>
T fcn(){
    return PI<T> * 10;
}

void Cpp14_VariableTemplates::variableTemplates_SimpleExample()
{
    const int cPi = PI<int>;
    std::cout << "Value of PI is: " << cPi << std::endl;
    std::cout << "Funciton call is: " << fcn<int>() << std::endl;
}