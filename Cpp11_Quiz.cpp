#include "Cpp11_Quiz.hpp"

#include <iostream>
#include <type_traits>

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

void Cpp11_Quiz::quiz_337()
{
    auto a = "some text";
    std::cout << std::is_same_v<decltype("some text"), decltype(a)>;
}
