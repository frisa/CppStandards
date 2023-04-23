#include "Cpp11_AutoDecltype.hpp"
#include <memory>
#include <type_traits>

/*

    specifies that the data type is being automaticaly deduced from the initializer

    - C++ 11 for variables, specifies that the return type will be deduce from its return statements
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
   
    template<typename To, typename From>
    To convert(From f){
        std::cout << "To data type is: " << typeid(f).name() << std::endl;
        return static_cast<To>(f);
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
    in order to instantiate a function template, every template argument must be knows, but not every template argument
    has to be specified. 
    When possible, the compiler will deduce the missing template arguments from the function arguments. 
    This occurs when a function call is attempted, when an address of a function template is taken, and in some other contexts

    This mechanism makes it possible to use template operators, since there is no syntax to specify template arguments for an operator
*/

void Cpp11_AutoDecltype::auto_TemplateArgumentDeduction()
{
    double d{0.0};
    double argument{0.0};

    // examples of the type deductions from input arguments
    int i = convert<int>(d);
    i = convert<int, double>(3);                    // both arguments are known and specified -> no deduction is needed
    i = convert<int>(3);                            // first argument is specified and second argument is just known
    i = convert<int>(argument);                     // first argument is specified and second argument is deduced from variable
    int (*ptr)(double) = convert<int, double>;      // both arguments are known and specified
    int (*ptr1)(double) = convert<int>;             // first argument is specified and second argument is deduces from function poiter parameter
    double (*ptr2)(int) = convert<double>;          // the new function address is assigned as the argument types has changed
    deduceFromInitList({1, 2, 3});                  // the type is deduced from the items data types, but must be the same type
    deduceFromInitListSize({1, 2, 3, 4});           // the type is deduced from the items data types and the size too
    deduceFromNonTypeTemplateParameter<int, 5>();   // the type is deduced from the constexpr in non-type template parameter
 
    std::cout << "This text will be used for deduction" << std::endl;  // template argument deduction makes possible to deduce argument type for operators

    // exmaples of deduction from the function calls
    i = convert<int>(getDouble());                  // first argument is specified and second argument is deduced from function

    // C++ 17 type deduction in structured binding
    int a[2] = {1, 2};
    auto [x, y] = a;        // creates e[2], copies a into e
    x = 123;                // then x refers to e[0], y refers to e[1]
    auto& [xr, yr] = a;     // xr refers to a[0], yr referes to a[1]
    xr =  123;              // will change a[0]

    // C++ 11 type deduction in function declarator with trailing return type
    auto (*p)()->int;       // declares p as pointer to function returning int
    auto (*q)()->auto = p;  // declares q as pointer to function returning T
                            // where T is deduced from the type of p

    // C++ 11 usage for unnamed types in the lambda expressions
    //auto lambda = [](int x){return x+3};
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
