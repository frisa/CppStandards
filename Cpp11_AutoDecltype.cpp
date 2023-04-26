#include "Cpp11_AutoDecltype.hpp"
#include <memory>
#include <type_traits>
#include <vector>
#include <string>
#include <functional>

/*

    auto - specifies that the data type is being automaticaly deduced from the initializer
    ======================================================================================

    - C++ 98 for variables declaration, use the automatic storage duration
                    auto int x = 0;

    - C++ 11 for variables, specifies that the type of the variable that is being declared will be automatically deduced from its initializer
                    int x{0};
                    auto variable = x; // similar like var in C#

    - C++ 14 for functions, specifies that the return type will be deduced from its return statements
                    int x;
                    auto function(){return x;}

    - C++ 17 for non-type template parameters, specifies that the type will be deduced from the argument
                    template<auto n>       
                    auto function() -> std::pair<decltype(n), decltype(n)>
                    {
                        return {n, n};
                    }
                    function<123>();

    syntax:
    <type-constraint> auto                  : type is deduced using the rules for "Template Argument Deduction"
    <type-constraint> decltype(expresion)   : return the type needed for the output of the expleression uchar + uchar = int
    <type-constraint> decltype(auto)        : type is deduced from decltype(expresion) the expression is used as initializer

    reference:
        Scott Meyers - Type Deduction and why you care
        Scott Meyers - Effective Modern C++
*/

// unnamend namespace for internal linkage
namespace
{
    class A
    {
        const int m_constant_variable;
        int m_variable;

    public:
        A(std::initializer_list<int> init_values) : m_constant_variable{0}
        {
            for (auto item : init_values)
            {
                std::cout << "init value: " << item << std::endl;
            }
        }
        A(const A &other) : m_constant_variable{0}
        {
            std::cout << "copy-constructor called" << std::endl;
        }
    };

    void fcnVoid()
    {
    }

    int fcnIntRetInt(double value)
    {
        return static_cast<int>(value + 1);
    }

    template <typename A, typename B>
    void testFunction(A a, B b)
    {
        std::cout << "A is type: " << typeid(a).name() << std::endl;
        std::cout << "B is type: " << typeid(b).name() << std::endl;
    }

    template <typename To, typename From>
    To convert(From value)
    {
        To returnValue;
        returnValue = static_cast<To>(value);
        std::cout << "From type is: " << typeid(value).name() << std::endl;
        std::cout << "To type is: " << typeid(returnValue).name() << std::endl;
        return static_cast<To>(value);
    }

    template <typename T, auto cnt>
    void deduceFromNonTypeTemplateParameter()
    {
        std::cout << "Non-type parameter deduced: " << typeid(cnt).name() << std::endl;
        T arr[cnt];
        for (auto item : arr)
        {
            std::cout << "Item=" << item << std::endl;
        }
    }

    double getDouble()
    {
        return 0.0;
    }

    template <class T>
    void deduceFromInitList(std::initializer_list<T> list)
    {
        for (auto item : list)
        {
            std::cout << "Item: " << item << " of type:" << typeid(item).name() << std::endl;
        }
    }

    template <class T, int N>
    void deduceFromInitListSize(T const (&)[N])
    {
        std::cout << "Size of array: " << N << std::endl;
    }

    template <class T>
    void deducedRefDataType(T variable_string)
    {
        std::cout << "type of variable: " << typeid(variable_string).name() << std::endl;
    }
}

/*
    Template Type Deduction:
    in order to instantiate a function template:
    - every template argument must be known, but not every template argument has to be specified.

    the compiler will deduce the missing template arguments from the function arguments in folowing cases:
    - function call is attended 
    - when an address of a function template is taken
    - and in some other contexts

    This mechanism makes it possible to use template operators, since there is no syntax to specify template arguments for an operator
*/

/*
    Template Type Deduction
        C++ 98: it generaly just work and detailed understandind rarely needed
            - two sets of rules
                1) Rules for T& and T* - pass by reference
                    - remove reference
                    - pattern matching
                2) Rules for T  - pass by value
        C++ 11: the type deduction scope expands
            - auto variables, universal refereces, lambda captures and returns, decltype
            - six sets of rules
                1) Rules for T& and T*
                2) Rules for T
                3) Rules for T&& (universal reference)
                4) lambda implicit return (like 2)
                5) decltype
                6) lambda captures (like 1)
        C++ 14: the type deduction scope expands
            - function return types, lambda init captures
                1) lambda auto parameters (like 1,2)
                2) auto return type
                3) decltype(auto)
                4) lambda init capture
*/
    template <typename T>
    void f1(T &param)
    {
        T local{0};                                                     // What is the type T ?
        std::cout << "param: " << typeid(param).name() << std::endl;
        std::cout << "local: " << typeid(local).name() << std::endl;
    };

    template <typename T>
    void f2(const T &param)
    {
        std::cout << "Type is: " << typeid(param).name() << std::endl;
    };

    template <typename T>
    void f3(T *param)
    {
        std::cout << "Type is: " << typeid(param).name() << std::endl;
    };

void Cpp11_AutoDecltype::auto_TemplateTypeDeduction_NormalReferences()
{
    int x = 22;
    const int cx = x;
    const int &crx = x;

    // CASE 1: f1(T& param)
    f1(x);   // -> T = int , param = int&                       , pattern matching: int -> T&
    f1(cx);  // -> T = const int, param = const int&            , pattern matching: const int -> T&
    f1(crx); // -> T = const int, param = const int&            , pattten matching: const int& -> T&

    auto &v1 = x;
    static_assert(std::is_same<decltype(v1), int &>::value); // auto = int

    auto &v2 = cx;
    static_assert(std::is_same<decltype(v2), const int &>::value); // auto = const int

    auto &v3 = crx;
    static_assert(std::is_same<decltype(v3), const int &>::value); // auto = const int

    // CASE 2: f1(const T& param)
    f2(x);   // -> T = int, param = const int&                  , pattern matching: int -> const T&
    f2(cx);  // -> T = int, param = const int&                  , pattern matching: const int -> const T&
    f2(crx); // -> T = int, param = const int&                  , pattern matching: const int& -> const T&

    const auto &v4 = x;
    static_assert(std::is_same<decltype(v4), const int &>::value); // auto = int

    const auto &v5 = cx;
    static_assert(std::is_same<decltype(v5), const int &>::value); // auto = int

    const auto &v6 = crx;
    static_assert(std::is_same<decltype(v6), const int &>::value); // auto = int

    // CASE 3: f3(T* param)
    const int *pcx = &x;
    f3(&x);  // -> T = int, param = int*                , pattern matching: int* -> T*
    f3(pcx); // -> T = const int, param = const int*    , pattern matching: const int* -> T*

    auto *v7 = &x;
    static_assert(std::is_same<decltype(v7), int *>::value); // auto = int

    const auto *v8 = pcx;
    static_assert(std::is_same<decltype(v8), const int *>::value); // auto = int
}

template <typename T>
void f4(T &&param)
{
    std::cout << "Type is: " << typeid(param).name() << std::endl;
}
/*
    universal reference: look like rvalue references, BUT what it represents depends what it is initialized with (lvalue/rvalue reference)
    - only case whan the reference is deduced
    - reference colapsing
    reference collapsing:
            & & -> &
            & && -> & <- lvalue reference for deduction
            && & -> &
            && && -> &&

*/
void Cpp11_AutoDecltype::auto_TemplateTypeDeductionUniversalReferences()
{
    // CASE 4: f(T&& param)
    int x = 22;
    const int cx = x;
    const int &crx = x;
    f4(x);   // x is lvalue, T = int&, param = int&                         , pattern matching: int (lvalue) -> T&&
    f4(cx);  // cx is lvalue, T = const int&, param = const int&            , pattern matching: const int (lvalue) -> T&&
    f4(crx); // rx is lvalue, T = const int&, param = const int&            , pattern matching: const int& (lvalue) -> T&&
    f4(22);  // x is rvalue (no special handling), T = int, param = int&&   , pattern matching: <22> int&& (rvalue) -> T&&

    auto &&v1 = x;
    static_assert(std::is_same<decltype(v1), int &>::value); // declared: int&

    auto &&v2 = cx;
    static_assert(std::is_same<decltype(v2), const int &>::value); // declared: const int&

    auto &&v3 = crx;
    static_assert(std::is_same<decltype(v3), const int &>::value); // declared: const int&

    auto &&v4 = 22;
    static_assert(std::is_same<decltype(v4), int &&>::value); // declared: int&&
}

template <typename T>
void f5(T param){};

void Cpp11_AutoDecltype::auto_TemplateTypeDeductionByValueParameter()
{
    // CASE 5: f5(T param)
    int x = 22;
    const int cx = x;
    const int &crx = x;
    f5(x);   // T = int, param = int
    f5(cx);  // T = int, param = int
    f5(crx); // T = int, param = int

    auto v1 = x;
    static_assert(std::is_same<decltype(v1), int>::value); // auto = int

    auto v2 = cx;
    static_assert(std::is_same<decltype(v2), int>::value); // auto = int

    auto v3 = crx;
    static_assert(std::is_same<decltype(v3), int>::value); // auto = int

    // Non-Reference, Non-Pointer auto deduction
    // auto is newer deduced as reference type
    auto v4 = crx;   // type = int
    auto &v5 = crx;  // type = const int&
    auto &&v6 = crx; // type = const int& (rx is lvalue)
}
#if (TRUE)
/*
    auto type deduction is same as template type deduction, EXCEPT with braced initializers
    - template type deduciton fails
    - audo deduces std::initializer_list
*/
template <typename T>
void f6(T param){};

void Cpp11_AutoDecltype::auto_TypeDecutionBracedInitializer()
{
    // f6({1,2,3}); // ERROR! type deduction fail as the braced initializer doed not have type
    // auto x1{1, 2, 3};    // type = std::initializer_list<int> until friday !!! N3922 is not part of the C++14
    auto x1{1};          // direct init w/1 element x = int
    auto x2 = {1, 2, 3}; // type = std::initializer_list<int>
    auto x3 = {1};       // according C++ 14 is initializer_list<int>
}

void Cpp11_AutoDecltype::auto_TemplateArgumentDeduction()
{
    // examples of deduction from the initializer
    testFunction<int, double>(1, 2); // both arguments are known and specified -> no deduction is needed
    testFunction<int>(1, 2.0);       // first argument is specified and second argument is just known
    double argument{0.0};
    testFunction<int>(1, argument); // first argument is specified and second argument is deduced from variable

    int (*Ptr)(double) = convert<int, double>;         // both arguments are known and specified
    int (*sameLikePtr)(double) = convert<int>;         // first argument is specified and second argument is deduces from function poiter parameter
    double (*differetnFromPtr)(int) = convert<double>; // the new function address is assigned as the argument types has changed
    deduceFromInitList({1, 2, 3});                     // the type is deduced from the items data types, but must be the same type
    deduceFromInitListSize({1, 2, 3, 4});              // the type is deduced from the items data types and the size too
    deduceFromNonTypeTemplateParameter<int, 5>();      // the type is deduced from the constexpr in non-type template parameter

    std::cout << "This text will be used for deduction" << std::endl; // template argument deduction makes possible to deduce argument type for operators

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
    x = 123; // then x refers to e[0], y refers to e[1]

    auto &[xr, yr] = a; // xr refers to a[0], yr referes to a[1]
    xr = 123;           // will change a[0]

    // C++ 11 type deduction in function declarator with trailing return type
    auto(*p)()->int;      // declares p as pointer to function returning int
    auto(*q)()->auto = p; // declares q as pointer to function returning T
                          // where T is deduced from the type of p

    // C++ 11 usage for unnamed types in the lambda expressions
    // auto lambda = [](int x){return x+3};

    // C++ 17 Deduction guid
}

void Cpp11_AutoDecltype::auto_SimpleTypeDeduction()
{
    // ill-formed exmaple
    auto auto_variable0 = 1; //, auto_variable_IllFormed = 1.0;

    auto auto_variable1{0};
    static_assert(std::is_same<decltype(auto_variable1), int>::value, "variable does not have expected type");

    int type_variable2{0};
    auto auto_variable2{type_variable2};
    static_assert(std::is_same<decltype(auto_variable2), int>::value, "variable does not have expected type");
}

void Cpp11_AutoDecltype::auto_ConstTypeDeduction()
{
    const int type_variable2{0};
    auto auto_variable2{type_variable2};
    static_assert(std::is_same<decltype(auto_variable2), int>::value, "variable does not have expected type");
}
#endif
template<typename T>
auto AddTwo(T x) -> decltype(x+x)
{
    return x + x; // two unsigned chars can produce the int
}
const int& someExpression()
{
    static int x{0};
    return x;
};
auto someExpresstionAutoWrapper(){return someExpression();};
decltype(auto) someExpresstionDecltypeAutoWrapper(){return someExpression();};
auto someExpresstionDecltypeAutoWrapperTrailing() -> decltype(auto)
{
    return someExpression();
};
/*
    decltype returns exactly the declared type of the variable so CVR will keep as deduced type
*/
void Cpp11_AutoDecltype::decltype_DeductionOfVariable()
{
    int x = 10;
    static_assert(std::is_same<decltype(x), int>::value);

    const auto &crx = x;
    static_assert(std::is_same<decltype(crx), const int &>::value);

    decltype(crx) new_crx = x;
    static_assert(std::is_same<decltype(new_crx), const int &>::value);

    decltype(auto) shallBeInt = AddTwo(static_cast<unsigned char>(99999));
    static_assert(std::is_same<decltype(shallBeInt), int>::value);

    auto ret1 = someExpression();
    static_assert(std::is_same<decltype(ret1), int>::value); // this does use the template type deduction

    decltype(auto) ret2 = someExpresstionAutoWrapper();
    static_assert(std::is_same<decltype(ret2), int>::value); // THIS WILL RETURNE WRONG DEDUCED DATA TYPE - perfekt forwarding 

    decltype(auto) ret3 = someExpresstionDecltypeAutoWrapper();
    static_assert(std::is_same<decltype(ret3), const int&>::value); // this will return proper data type deduced from the declaration

    decltype(auto) ret4 = someExpresstionDecltypeAutoWrapperTrailing();
    static_assert(std::is_same<decltype(ret4), const int&>::value); // this will return proper data type deduced from the declaration with trailing
}
/*
    decltype of the expression is more complicated as it can be lvalue or rvalue
    - if it is lvalue -> deduce the type and place lvalue reference on it
    - if it is rvalue -> deduce rvalue reference
*/
void Cpp11_AutoDecltype::decltype_DeductionOfExpressionLvalue()
{
    int arr[10];
    arr[0] = 5;                                                  // it acts as reference because it change the value
    static_assert(std::is_same<decltype(arr[0]), int &>::value); // the type is int but is act as int&, because it is lvalue expression
}

/*
    C++ 14
    deduction of the return type
    - auto return type deduction
        - template type deduction
    - decltype(auto) return type
        - "I want to use the automaticly deduce the return type with decltype rules"
*/

// Example: I want to return just value not reference
// auto gives proper behaviour as it can newer be reference
auto lookupValue()
{
    static std::vector<int> values = {1, 2, 3};
    return values[0];
}

decltype(auto) lookupValueAndChange()
{
    static std::vector<int> values = {1, 2, 3};
    return values[0];
}

void Cpp11_AutoDecltype::decltype_auto_DeductionOfReturnType()
{
    //lookupValue() = 0;
    lookupValueAndChange() = 0; // as it returns reference it is ok
}

void fcn(const std::string &data){};
void fcn(std::string &&data){};
template <typename T>
void wrapFcn(T &&data)
{
    fcn(std::forward<T>(data)); // conditional cast to the r-value
}

void Cpp11_AutoDecltype::auto_RvalueLvalue()
{
    std::string data{"Some data"};
    wrapFcn(data);
    wrapFcn(std::move(data)); // unconditional cast to the r-value
}

decltype(auto) sensitiveOnImplementationNoParentheses()
{
    int ret = 1;
    return ret; // returns int
}

decltype(auto) sensitiveOnImplementationWithParentheses()
{
    int ret = 1;
    // return (ret); // returns int& to the local variable !!
    return 0;
}

/*
    Rules of thumb:
    - Use auto if a reference type would never be correct
    - Use decltype(auto) only if a reference type could be correct
*/
