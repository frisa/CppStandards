#include "Cpp11_UniformInitialization.hpp"
#include <iostream>

struct SomeStructure{
    int m_id;
    std::string m_name; 
};

// C++ 11 - extended the initialization options to the curly brace list also for the internal variables
// Uniform Initialization Search Order
// 1. Initializer_list constructor
// 2. Regular constructor that takes the appropriate parameters
// 3. Aggregate initializer

void Cpp11_UniformInitialization::uniformInit_SimpleExample()
{
    SomeStructure somStr{1, "SomeName"};
    std::cout << "name id: " << somStr.m_name << std::endl;
};