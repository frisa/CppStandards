#include "Cpp11_Quiz.hpp"

size_t get_size_1(int * arr){
    return sizeof(arr);
}

size_t get_size_2(int arr[]){
    return sizeof(arr);
}

size_t get_size_3(int (&arr)[10])
{
    return sizeof(arr);
}

void Cpp11_Quiz::quiz_140()
{
    int arr[10];
    std::cout << sizeof(arr) << std::endl;
    std::cout << get_size_1(arr) << std::endl;
    std::cout << get_size_2(arr) << std::endl;
    std::cout << get_size_3(arr) << std::endl;

    // the correct answer for th question in the quiz is 001
}