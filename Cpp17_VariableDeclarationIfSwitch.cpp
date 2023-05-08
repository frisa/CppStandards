#include "Cpp17_VariableDeclarationIfSwitch.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void Cpp17_VariableDeclarationIfSwitch::varDecl_SimpleExample()
{
    std::cout << "This is the exeample of the variable declaration\n";
    std::vector<std::string> str{"hello", "nice", "abc"};

    // this would be the old approach in C++ 14
    const auto it = std::find(begin(str), end(str), "abc");
    if (it != end(str)){
        *it = "$$$";
    }

    // this would be the new approach in C++ 17
    // to avoid having too much iterators in case we want to 
    if (const auto it = find(begin(str), end(str), "abc"); it!=end(str)) {
        *it = "$$$";
    }
}