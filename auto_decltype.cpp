// C++ 11
// 1.
// Placeholder type specifiers
// ---------------------------------------------------------------------------------
// For variables, specifies that the type of the variable that is being declared will be automatically
// deduced from its initializer
// * For functions, specifies that the return type will be deduced from its return statements
// * For non-type template parameters, specifies that the type will be deduced from the argument
// The palceholder auto may be accompanied by modifiers, such as const or &, which will participate in 
// the type deduction. The placeholder decltype(auto) must be the sole constituent of the declared type.

#include <type_traits>
#include <iostream>
#include <string>

// The return type is the return type of the plus operator from T and U
template<class T, class U>
auto add(T t, U u)
{
    return t + u;
}

// perfect forwarding of a function call must use decltype(auto)
// in case the funcion it calls return by reference 
template<class F, class... Args>
decltype(auto) PerfectForward(F fun, Args&&... args)
{
    return fun(std::forward<Args>(args) ...);
}

// Scott Meyers - example for funciton return type deduction
// its use to allow auto declatrations to use the decltype rules on the given expression
template<typename ContainerType, typename IndexType>
decltype(auto) grab(ContainerType&& container, IndexType&& index)
{
    return std::forward<ContainerType>(container)[std::forward<IndexType>(index)];
}

// Simple example
const std::string message = "test";
const std::string& foo()
{
    return message;
}

int main()
{
    auto f1 = foo();
    decltype(auto) f2 = foo();
    static_assert(std::is_same_v<decltype(f2), const std::string& >);
    return 0;
}