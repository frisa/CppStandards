/*
    Converts any type T to a reference type, making it possible to use member functions in the operand of the decltype specifier without the need to go through constructors.
    std::declval is commonly used in templates where acceptable template parameters may have no constructor in common, but have the same member function whose return type is needed.

*/

class Cpp11_DeclvalDecltype{
    public:
    void simpleExample();
};