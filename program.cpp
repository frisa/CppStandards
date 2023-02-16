#include <iostream>

int main()
{
    auto autoVariable = 20;
    decltype(autoVariable) decTypeVariable = 21;

    std::cout << "First variable " << autoVariable << std::endl;
    std::cout << "Second variable " << decTypeVariable << std::endl;

    printf("C++ Standards application\n");
    return 0;
}