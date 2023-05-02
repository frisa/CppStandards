#include "Cpp11_VariadicTemplates.hpp"
#include <string>
#include <sstream>
#include <vector>

/**/

template <typename Func, typename... T>
void call(const Func &function, const T &...param)
{
    function(param...);
}

template <typename... Types>
void someFunction(Types... args)
{
    return;
}

template<typename... Types>
void fcn(Types ...){

}

template<typename T>
void print(const T& value){
    std::cout << value << std::endl;
}

template<typename T>
std::string to_string_impl(const T& value){
    std::stringstream ss;
    ss << value;
    return ss.str();
}

std::vector<std::string> to_string(){
    return {};
}

template<typename P1, typename... Param>
std::vector<std::string> to_string(const P1 &p1, const Param& ...param){
    std::vector<std::string> s;
    s.push_back(to_string_impl(p1));
    // call the its function and add them to the remainder
    const auto remainder = to_string(param...);
    s.insert(s.end(), remainder.begin(), remainder.end());
    return s;
}

void Cpp11_VariadicTemplate::variadicTemplate_SimpleExmple()
{
    someFunction();                      // call with no argument
    someFunction(1, 2.0);                // call with one integer
    someFunction(1, 2.3, "some string"); // call with some diverse data types

    const auto vec = to_string("first", 1, 2.3);
    for (const auto& item: vec){
        std::cout << item << "\n";
    }
}