#include "Cpp11_VariadicTemplates.hpp"

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

void Cpp11_VariadicTemplate::variadicTemplate_SimpleExmple()
{
    someFunction();                      // call with no argument
    someFunction(1, 2.0);                // call with one integer
    someFunction(1, 2.3, "some string"); // call with some diverse data types
}