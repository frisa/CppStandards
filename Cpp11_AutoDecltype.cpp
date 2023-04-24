#include "Cpp11_AutoDecltype.hpp"
#include <memory>
#include <type_traits>
#include <vector>
#include <string>
#include <functional>

/*

    specifies that the data type is being automaticaly deduced from the initializer

    - C++ 11 for variables, specifies that the type of the variable that is being declared will be automatically deduced from its initializer
    - C++ 14 for functions, specifies that the return type will be deduced from its return statements
    - C++ 17 for non-type template parameters, specifies that the type will be deduced from the argument

    syntax:
    <type-constraint> auto              : type is deduced using the rules for template argument deduction
    <type-constraint> decltype(auto)    : type is deduced from decltype(expresion) the expression is used as initializer
    
*/

// unnamend namespace for internal linkage
namespace{
    class A{
        const int m_constant_variable;
        int m_variable;
    public:
        A(std::initializer_list<int> init_values): m_constant_variable{0} {
            for (auto item: init_values)
            {
                std::cout << "init value: " << item << std::endl;
            }
        }
        A(const A& other): m_constant_variable{0}
        {
            std::cout << "copy-constructor called" << std::endl;
        }
    };

    void fcnVoid(){
    }

    int fcnIntRetInt(double value){
        return static_cast<int>(value +1);
    }
   
    template<typename A, typename B>
    void testFunction(A a, B b)
    {
        std::cout << "A is type: " << typeid(a).name() << std::endl;
        std::cout << "B is type: " << typeid(b).name() << std::endl;
    }

    template<typename To, typename From>
    To convert(From value){
        To returnValue;
        returnValue = static_cast<To>(value);
        std::cout << "From type is: " << typeid(value).name() << std::endl;
        std::cout << "To type is: " << typeid(returnValue).name() << std::endl;
        return static_cast<To>(value);
    }

    template<typename T, auto cnt>
    void deduceFromNonTypeTemplateParameter()
    {
        std::cout << "Non-type parameter deduced: " << typeid(cnt).name() << std::endl;
        T arr[cnt];
        for (auto item:arr)
        {
            std::cout << "Item=" << item << std::endl;
        }
    }

    double getDouble(){
        return 0.0;
    }

    template<class T>
    void deduceFromInitList(std::initializer_list<T> list){
        for (auto item:list)
        {
            std::cout << "Item: " << item << " of type:" << typeid(item).name() << std::endl;
        }
    }

    template<class T, int N>
    void deduceFromInitListSize(T const(&)[N]){
        std::cout << "Size of array: " << N << std::endl;
    }

    template<class T>
    void deducedRefDataType(T variable_string){
        std::cout << "type of variable: " << typeid(variable_string).name() << std::endl;
    }
}

/*
    Template Argument Deduction:
    in order to instantiate a function template:
    - every template argument must be knows, but not every template argument has to be specified. 

    the compiler will deduce the missing template arguments from the function arguments in folowing cases:
    - function call is attended
    - when an address of a function template is taken
    - and in some other contexts

    This mechanism makes it possible to use template operators, since there is no syntax to specify template arguments for an operator
*/

template<typename T>
void f1(T& param)
{
    std::cout << "Type is: " << typeid(param).name() << std::endl; 
};

template<typename T>
void f2(const T& param)
{
    std::cout << "Type is: " << typeid(param).name() << std::endl; 
};

template<typename T>
void f3(T* param)
{
    std::cout << "Type is: " << typeid(param).name() << std::endl; 
};

void Cpp11_AutoDecltype::auto_TemplateTypeDeduction()
{
    // Type reference deduction
    // - remove reference
    // - pattern matching
    int x = 22;
    const int cx = x;
    const int& rx = x;
    // T& param
    f1(x);   // -> T = int , param = int&
    f1(cx);  // -> T = const int, param = const int&
    f1(rx);  // -> T = const int, param = const int&
    //const T& param
    f2(x);   // -> T = int, param = const int&
    f2(cx);  // -> T = int, param = const int&
    f2(rx);  // -> T = int, param = const int&
    //T* param
    const int* pcx = &x;
    f3(&x);   // -> T = int, param = int*
    f3(pcx);  // -> T = const int, param = const int*
    // auto deduction
    auto& v1 = x;           static_assert(std::is_same<decltype(v1), int&>::value);             // auto = int
    auto& v2 = cx;          static_assert(std::is_same<decltype(v2), const int&>::value);       // auto = const int
    auto& v3 = rx;          static_assert(std::is_same<decltype(v3), const int&>::value);       // auto = const int
    const auto& v4 = x;     static_assert(std::is_same<decltype(v4), const int&>::value);       // auto = int
    const auto& v5 = cx;    static_assert(std::is_same<decltype(v5), const int&>::value);       // auto = int
    const auto& v6 = rx;    static_assert(std::is_same<decltype(v6), const int&>::value);       // auto = int
}

void Cpp11_AutoDecltype::auto_TemplateArgumentDeduction()
{
    // examples of deduction from the initializer
    testFunction<int, double>(1, 2);                // both arguments are known and specified -> no deduction is needed
    testFunction<int>(1, 2.0);                      // first argument is specified and second argument is just known
    double argument{0.0};
    testFunction<int>(1, argument);                         // first argument is specified and second argument is deduced from variable

    int (*Ptr)(double) = convert<int, double>;              // both arguments are known and specified
    int (*sameLikePtr)(double) = convert<int>;              // first argument is specified and second argument is deduces from function poiter parameter
    double (*differetnFromPtr)(int) = convert<double>;      // the new function address is assigned as the argument types has changed
    deduceFromInitList({1, 2, 3});                  // the type is deduced from the items data types, but must be the same type
    deduceFromInitListSize({1, 2, 3, 4});           // the type is deduced from the items data types and the size too
    deduceFromNonTypeTemplateParameter<int, 5>();   // the type is deduced from the constexpr in non-type template parameter
 
    std::cout << "This text will be used for deduction" << std::endl;  // template argument deduction makes possible to deduce argument type for operators

    // exmaple of deduction for the class template C++ 17
    std::pair<int, std::string> pairSpecified(1, ""); // pair class constructed
    static_assert(std::is_same<decltype(pairSpecified.first), int>::value);

    std::pair deducePair{1, 2.4f}; // pair class constructed and deduced
    static_assert(std::is_same<decltype(deducePair.second), float>::value);

    std::tuple deducedTuple(1, 2.4, "");                                                                 // tuple class constructed and deduced
    std::cout << "Tuple type of 0 element is:" << typeid(std::get<0>(deducedTuple)).name() << std::endl; // why I cannot use the static_assert
    std::tuple deducedTupleFromFunction([=](int x)
                                        { return static_cast<double>(x); },
                                        [&](std::string text)
                                        { std::cout << text; });

    std::vector v1{1, 2, 3}; // vector class deduction
    std::cout << "Vector type of 0 element is:" << typeid(v1[0]).name() << std::endl;

    std::function fcnObj(&fcnIntRetInt); // function class constructed and deduced
    auto ret = fcnObj(123);
    static_assert(std::is_same<decltype(ret), int>::value);

    std::function fcnObjVoid(&fcnVoid); // the C++ 17 has deduciton guides for this case

    // exmaples of deduction from the function calls
    auto i = convert<int>(getDouble()); // first argument is specified and second argument is deduced from function

    // C++ 17 type deduction in structured binding
    int a[2] = {1, 2};
    auto [x, y] = a; // creates e[2], copies a into e
    static_assert(std::is_same<decltype(x), int>::value);
    x = 123;                // then x refers to e[0], y refers to e[1]

    auto& [xr, yr] = a;     // xr refers to a[0], yr referes to a[1]
    xr =  123;              // will change a[0]

    // C++ 11 type deduction in function declarator with trailing return type
    auto (*p)()->int;       // declares p as pointer to function returning int
    auto (*q)()->auto = p;  // declares q as pointer to function returning T
                            // where T is deduced from the type of p

    // C++ 11 usage for unnamed types in the lambda expressions
    //auto lambda = [](int x){return x+3};

    // C++ 17 Deduction guid

}

void Cpp11_AutoDecltype::auto_SimpleTypeDeduction()
{
    // ill-formed exmaple
    auto auto_variable0 = 1; //, auto_variable_IllFormed = 1.0;

    auto auto_variable1{0};
    static_assert(std::is_same<decltype(auto_variable1), int>::value, "variable does not have expected type");

    int type_variable2{0};
    auto auto_variable2 {type_variable2};
    static_assert(std::is_same<decltype(auto_variable2), int>::value, "variable does not have expected type");
}

void Cpp11_AutoDecltype::auto_ConstTypeDeduction()
{
    const int type_variable2{0};
    auto auto_variable2 {type_variable2};
    static_assert(std::is_same<decltype(auto_variable2), int>::value, "variable does not have expected type");
}
