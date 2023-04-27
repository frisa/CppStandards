#include "Cpp11_Quiz.hpp"

#include <iostream>
#include <type_traits>
#include <stdexcept>
#include <future>

size_t get_size_1(int *arr)
{
    return sizeof(arr);
}

size_t get_size_2(int arr[])
{
    return sizeof(arr); // is also the pointer is even making the warning
}

size_t get_size_3(int (&arr)[10]) // this is the referece to the array of 10 items
{
    return sizeof(arr);
}

size_t get_size_4(int arr[10])
{
    return sizeof(arr); // is also making the waring about geting the size of the pointer data type
}

template <class T>
void f(T &i) { std::cout << 1; }

template <>
void f(const int &i) { std::cout << 2; }
void Cpp11_Quiz::quiz_001()
{
    int i = 42;
    f(i);
}

void f(int) { std::cout << 1; }
void f(unsigned) { std::cout << 2; }

void Cpp11_Quiz::quiz_003()
{
    // f(-2.1); this call will be ill formed as there are two equal options of the overloaded functions
}

void Cpp11_Quiz::quiz_140()
{
    int arr[10];
    std::cout << sizeof(arr) << std::endl;
    std::cout << get_size_1(arr) << std::endl;
    std::cout << get_size_2(arr) << std::endl;
    std::cout << get_size_3(arr) << std::endl;
    std::cout << get_size_4(arr) << std::endl;

    std::cout << sizeof(arr) / sizeof(int) << std::endl;

    // the correct answer for th question in the quiz is 001
}

class A
{
public:
    A()
    {
        std::cout << "a";
    };
    ~A()
    {
        std::cout << "A";
    };
};
int i{1};
void Cpp11_Quiz::quiz_105()
{
label:
    A a;
    if (i--)
        goto label;
}

void Cpp11_Quiz::quiz_193()
{
    int a[] = <%1%>;
    std::cout << a<:0:>;

    // C++ provides alternative tokens for come punctuators.
    // the two lines above means:

    int a2[] = {1};
    std::cout << a2[0];
}

void Cpp11_Quiz::quiz_206()
{
    int n = sizeof(0)["abcdefghij"];
    std::cout << n;

    /* the explenation is following:
    We can see that (0)["abcdefghij"] is identical to ("abcdefghij")[0] from
    reslt is sizeof('a')
    */
}

int a = 1;
void Cpp11_Quiz::quiz_229()
{
    int c{2};
    int d{3};
    auto f = [d](int b)
    {
        // b = c; this would cause compiler error as it is local variable not explicitly mentioin on the capture list
        b = d; // this is ok as the captured variable has been mentioned on the captured list
        return a + b;
    };
    std::cout << f(4);
}

class C2{
    public:
    C2() = default;
    C2(const C2& other)
    {
        std::cout << 1;
    }
};

void f(std::initializer_list<C2> init_list){}
void Cpp11_Quiz::quiz_235()
{
    C2 c;
    std::initializer_list<C2> i{c};
    f(i);
    f(i);
    // copy of the initializer list does not lead to the copy of the underlying elements but refers to the initialized array
}

void Cpp11_Quiz::quiz_239()
{
    try
    {
        throw std::out_of_range(""); // this will take the first catchec exception which is std::exception in this case
    }
    catch (std::exception &e)
    {
        std::cout << 1;
    }
    catch (std::out_of_range &e)
    { // compiler warning will report the issue with the earlier catched exception handler
        std::cout << 2;
    }

    try
    {
        throw std::out_of_range(""); // this would take the out of range exception as it is closer now
    }
    catch (std::out_of_range &e)
    {
        std::cout << 1;
    }
    catch (std::exception &e)
    {
        std::cout << 2;
    }
}

void Cpp11_Quiz::quiz_249()
{
    int a = '0';
    char const& b = a;
    std::cout << b;
    a++;
    std::cout << b;
}

class C
{
public:
    C()
    {
        std::cout << "constructor C called" << std::endl;
    };
    C(const C &)
    {
        std::cout << "copy constructor C called" << std::endl;
    }; // user-declared , disables the move constructor
};

class D
{
public:
    int m_some_variable{0};
    D()
    {
        // explicitly defined constructor
        std::cout << "constructor D called" << std::endl;
    };
    D(const D &)
    {
        std::cout << "copy constructor D has been called" << std::endl;
    }; // user-declared copy constructor
    D(D &&)
    noexcept
    {
        std::cout << "move constructor D has been called" << std::endl;
    }; // user-declared move constructor
};

void Cpp11_Quiz::quiz_281()
{
    C c;
    C c2(std::move(c)); // copy constructor is called as the implicit move constructor is not created

    D d;
    D d2(std::move(d)); // move constructor is called
    d.m_some_variable = 1;

    std::cout << "ok";
}

class A1
{
};

class B1
{
public:
    int x = 0;
};

class C1: public A1, /* public */ B1 {};
struct D1: private A1, B1{};

void Cpp11_Quiz::quiz_312()
{
    C1 c;
    //c.x = 3; // in the absence of the access specifier the base class is considered as private

    D1 d;
    d.x = 3;
    /* In the absence of an access-specifier for a base class, 
    public is assumed when the derived class is defined with the class-key struct 
    and private is assumed when the class is defined with the class-key class.*/
    //std::cout << c.x << d.x;
}

void Cpp11_Quiz::quiz_337()
{
    auto a = "some text";
    std::cout << std::is_same_v<decltype("some text"), decltype(a)>;
}

void Cpp11_Quiz::quiz_339()
{
    std::promise<int> p;
    std::future<int> f = p.get_future();
    p.set_value(1);
    std::cout << f.get(); // you can only get value once from the future
                          // std::cout << f.get(); this would cause exception
}
