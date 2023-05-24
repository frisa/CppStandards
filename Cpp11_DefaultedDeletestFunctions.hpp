/*  a non-member functions can appear only in the namespace scope (so no nestead functions cam appear) 
    a member functions can appear in the class body

    - default - explicitly request the generatign the default body of the function
                can be used for special member functions
                 - default constructor
                 - copy constructor
                 - move constructor
                 - destructor (since C++ 20)
                 - prospective destructor (since C++ 20)
                 - comparision operator (since C++ 20)
                 those are only functions which can be defaulted
    - delete  explicitly request to delete / not generate the body 
*/

#include <string>

struct S{
    int data;
    S(int value);
    explicit S(std::string str);
    virtual int getData() const {return data;}
};

struct D: S
{
    int data2;
    D(int v1, int v2=11): S(v1), data2(v2){
        std::cout << "ctor with default argument called\n";
    }
    int getData() const override{
        return data * data2;
    }
    D& operator=(D other) &
    {
        std::swap(other.data, data);
        std::swap(other.data2, data2);
        return *this;
    }
};

class Cpp11_DefaultedDeletedFunctions{
    void simpleExample();
};