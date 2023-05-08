#include "Cpp11_UniformInitialization.hpp"
#include <iostream>
#include <initializer_list>
#include <memory>
#include <vector>

struct SomeStructure{
    int m_id;
    std::string m_name;
};

struct SomeOrderExample{
    int m_value;                // 3st choice
    SomeOrderExample(int value){ // 2nd choice
        m_value = value;
    } 
    SomeOrderExample(const std::initializer_list<int>& values){ // 1st choice
        for (auto value:values){
            std::cout << "Item:" << value << std::endl;
        }
    }
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
    std::initializer_list<int> values{1,2,3};
    std::unique_ptr<SomeOrderExample> someOrd = std::make_unique<SomeOrderExample>(values);

    int * pi = nullptr; // just to put it somwhere

    // just to put it somwhere
    std::vector vct{1,2,3};
    for(auto item:vct){
        std::cout << "item:" << item << std::endl;
    }
};