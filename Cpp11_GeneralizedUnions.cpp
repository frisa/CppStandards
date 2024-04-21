#include "Cpp11_GeneralizedUnions.hpp"
#include <iostream>
#include <cstdint>

union Register{
    int word;
    short half;
    std::uint32_t word32;
    std::uint16_t s[2];
    std::uint8_t c;
};

void Cpp11_GeneralizedUnions::genUni_simpleExample()
{
    Register controlReg;
    controlReg.word = 0xff;
    std::cout << controlReg.half << std::endl;
    std::cout << controlReg.s[0] << std::endl;
}