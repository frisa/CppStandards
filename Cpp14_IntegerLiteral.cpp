#include "Cpp14_IntegerLiteral.hpp"
#include <iostream>

void Cpp14_IntegerLiteral::intLit_SimpleExample()
{
    int d = 42;
    int o = 052;
    int x = 0x2a;
    int X = 0X2A;
    int b = 0b101010; // C++14

    unsigned long long l1 = 18446744073709550592ull;       // C++11
    unsigned long long l2 = 18'446'744'073'709'550'592llu; // C++14
    unsigned long long l3 = 1844'6744'0737'0955'0592uLL;   // C++14
    unsigned long long l4 = 184467'440737'0'95505'92LLU;   // C++14

    // auto x = 0xE+2.0;   // error
    auto y = 0xa + 2.0;   // OK
    auto z = 0xE + 2.0;   // OK
    auto q = (0xE) + 2.0; // OK

    std::cout << 123 << '\n'
              << 0123 << '\n'
              << 0x123 << '\n'
              << 0b10 << '\n'
              << 12345678901234567890ull << '\n'
              << 12345678901234567890u << '\n'; // the type is unsigned long long
                                                // even without a long long suffix

    //   std::cout << -9223372036854775808 << '\n'; // error: the value
    // 9223372036854775808 cannot fit in signed long long, which is the
    // biggest type allowed for unsuffixed decimal integer literal
    std::cout << -9223372036854775808u << '\n';    // unary minus applied to unsigned
                                                   // value subtracts it from 2^64, this gives 9223372036854775808
    std::cout << -9223372036854775807 - 1 << '\n'; // correct way to calculate
                                                   // the value -9223372036854775808

#if __cpp_size_t_suffix >= 202011L // C++23
    static_assert(std::is_same_v<decltype(0UZ), std::size_t>);
    static_assert(std::is_same_v<decltype(0Z), std::make_signed_t<std::size_t>>);
#endif
}