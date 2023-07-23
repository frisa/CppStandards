/*

The standard defines a set of preprocessor macros corresponding to C++ language and library features introduced in C++11 or later. 
They are intended as a simple and portable way to detect the presence of said features.

ATTRIBUTES
-----------
__has_cpp_attribute( attribute-token )		
checks the support of an attribute named by attribute-token

attirbute tokens:
    - assume
    - carries_dependency
    - deprecated
    - fallthrought
    - likely
    - mayne_unused
    - no_unique_address
    - nodiscard

LANGUAGES FEATURES
------------------
these macros are predefined in each translation unit
each macro expands to the integral type corresponding to the year and month
    exmaple:
        - __cpp_char8_t
        - __cpp_auto_cast
        - __cpp_constexpr
        - __cpp_lambdas

LIBRARY FEATURES
----------------
__cpp_lib_chrono

*/

class Cpp20_FeatureTestMacros{
    void simpleExample();
};