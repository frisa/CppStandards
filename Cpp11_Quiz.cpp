#include "Cpp11_Quiz.hpp"

#include <iostream>
#include <type_traits>
#include <stdexcept>

size_t get_size_1(int * arr){
    return sizeof(arr);
}

size_t get_size_2(int arr[]){
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

template<class T>
void f(T&i){std::cout << 1;}

template<>
void f(const int& i){std::cout << 2;}
void Cpp11_Quiz::quiz_001()
{
    int i = 42;
    f(i);
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

class A{
    public:
    A(){
        std::cout << "a";
    };
    ~A(){
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

int a=1;
void Cpp11_Quiz::quiz_229()
{
    int c{2};
    int d{3};
    auto f = [d](int b){
        //b = c; this would cause compiler error as it is local variable not explicitly mentioin on the capture list
        b = d; // this is ok as the captured variable has been mentioned on the captured list
        return a + b;
    };
    std::cout << f(4);
}

void Cpp11_Quiz::quiz_239()
{
    try{
        throw std::out_of_range(""); // this will take the first catchec exception which is std::exception in this case
    }catch(std::exception& e){
        std::cout<<1;
    }catch(std::out_of_range& e){  // compiler warning will report the issue with the earlier catched exception handler
        std::cout<<2;
    }

    try{
        throw std::out_of_range(""); // this would take the out of range exception as it is closer now
    }catch(std::out_of_range& e){
        std::cout <<1;
    }catch(std::exception& e){
        std::cout <<2;
    }
}

class C{
    public:
        C(){
            std::cout << "constructor C called" << std::endl;
        };
        C(const C&){
            std::cout << "copy constructor C called" << std::endl;
        }; // user-declared , disables the move constructor
};

class D{
    public:
        int m_some_variable{0};
        D(){
            // explicitly defined constructor
            std::cout << "constructor D called" << std::endl;
        };
        D(const D&){
            std::cout<< "copy constructor D has been called" << std::endl;
        };  // user-declared copy constructor
        D(D&&) noexcept{
            std::cout<< "move constructor D has been called" << std::endl;
        }; // user-declared move constructor
};

void Cpp11_Quiz::quiz_281()
{
    C c;
    C c2(std::move(c));  // copy constructor is called as the implicit move constructor is not created

    D d;
    D d2(std::move(d));  // move constructor is called
    d.m_some_variable = 1;

    std::cout<<"ok";
}

void Cpp11_Quiz::quiz_337()
{
    auto a = "some text";
    std::cout << std::is_same_v<decltype("some text"), decltype(a)>;
}
