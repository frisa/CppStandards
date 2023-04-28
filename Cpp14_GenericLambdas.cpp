#include <iostream>
#include <string>

#include "Cpp14_GenericLambdas.hpp"

/*

    Constructs a closure an unnamed function object capable of capturing variables in scope
    
    Syntax:
        [captures](parameters)<specs requires>{body}

        generic lambda:
            [captures]<tparams>{body}
            [captures]<tparams>{body}

*/

// allowing auto keyword in the lambda parameter list

void Cpp14_GenericLambdas::genericLambdas_SimpleExample()
{
    auto add = [](auto x, auto y){
        return x+y;
    };
    int a=1, b=2;
    std::string str1 = "firstText", str2 = "secondText";
    std::cout << "First output: " << add(1,2) << std::endl;
    std::cout << "Second output: " << add(str1, str2) << std::endl;
}