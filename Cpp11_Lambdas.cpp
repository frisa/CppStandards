#include "Cpp11_Lambdas.hpp"
#include <algorithm>
#include <vector>

void Cpp11_Lambdas::lambdas_SimpleExample()
{
    auto thisIsLambdaWithoutParamters = []()
    {
        std::cout << "lambda is executing" << std::endl;
        return 0;
    };
    auto thisIsLambda = [](int a, int b)
    {
        std::cout << "lambda is executing with " << a << "," << b << std::endl;
        return a + b;
    };

    std::cout << "Return from lambda without parameters: " << thisIsLambdaWithoutParamters() << std::endl;
    std::cout << "Return from lambda: " << thisIsLambda(1, 2) << std::endl;
}

// this is exmple how to use lambda as template and inside the std functions
template<typename T>
void count_things(const T& values, int value)
{
    const auto count = std::count(begin(values), end(values), value);
    std::cout << "count is: " << count << std::endl;
}

template <typename T>
void get_count_less_than(const T &values, int value)
{
    const auto count = std::count_if(std::begin(values), std::end(values), [=](int i){
        return i<value;
    });
    std::cout << "count less than " << value << " is " << count << std::endl;

    int capturedCount{0};
    const auto count2 = std::count_if(std::begin(values), std::end(values), [&](int i){
        if (i < value)
        {
            capturedCount++;
        }
        return i < value;
    });
    std::cout << "Count is: " << count2 << " captured count is: " << capturedCount << std::endl;

    // this is just to show the capture by value
    int capturedCount2{0};
    const auto count3 = std::count_if(std::begin(values), std::end(values), [=](int i){
        if (i < value)
        {
            //capturedCount2++; this is read only variable so the compiler would make error
        }
        return i < value;
    });
    std::cout << "Count is: " << count3 << " captured count is (shall be zero): " << capturedCount2 << std::endl;
}

void Cpp11_Lambdas::lambdas_UseInFunction()
{
    std::vector values = {1,2,3,1,1};
    const int value = 2;
    count_things(values, value);
    get_count_less_than(values, value);
}
