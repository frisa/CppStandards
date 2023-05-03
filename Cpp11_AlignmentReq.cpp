#include "Cpp11_AlignmentReq.hpp"
#include <iostream>

/*
    alignof - queries allignment requirements of type.

    Returns the alignment, in bytes, required for any instance of the type indicated by typeid, which is either complete object type,
    an array type whose element type is complete, or a reference type to one of those types.

    It the type is reference type, the operator returns the alignment of reference type; if the type is array type allignment requirement of the 
    element type is returned.
*/

struct foo{
    int i;
    float f;
    char c;
};

struct alignas(alignof(long double)) foo2{};
struct empty{};
struct alignas(64) empty64{};

void Cpp11_AlignmentReq::alignReq_SimpleExample()
{
    std::cout << "Alignment of"  "\n"
        "- char            : " << alignof(char)    << "\n"
        "- pointer         : " << alignof(int*)    << "\n"
        "- class Foo       : " << alignof(foo)     << "\n"
        "- class Foo2      : " << alignof(foo2)    << "\n"
        "- empty class     : " << alignof(empty)   << "\n"
        "- empty class\n"
        "  with alignas(64): " << alignof(empty64) << "\n";
}