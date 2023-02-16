#include <iostream>
#include <vector>

class A
{
    int x;

    A();
    A(A& other)
    {
        this->x = other.x;
    }
};

class B: A
{
    B() = default;
};

[[pnoreturn]] static const int functionVoid()
{
    std::cout << "this is the call of the function: " << __func__ << std::endl;
    return 1;
}

int main()
{
    auto autoVariable = 20;
    decltype(autoVariable) decTypeVariable = 21;

    std::cout << "First variable " << autoVariable << std::endl;
    std::cout << "Second variable " << decTypeVariable << std::endl;

    std::vector<int> arrayVariable = {1,4,5,6,7};

    for (auto value: arrayVariable)
    {
        std::cout << "value: " << value << std::endl;
    }

    autoVariable = functionVoid();
    std::cout << "functoin has returned" << autoVariable << std::endl;
    printf("C++ Standards application\n");
    return 0;
}