#include "Cpp20_FeatureTestMacros.hpp"

#ifdef __has_include
# if __has_include(<version>)
#   include <version>
# endif
#endif

#if __cpp_constexpr >= 201304                // Check for a specific version of a feature
#  define CONSTEXPR constexpr
#else
#  define CONSTEXPR inline
#endif

CONSTEXPR int bar(unsigned i)
{
#if __cpp_binary_literals                    // Check for the presence of a feature
    unsigned mask1 = 0b11000000;
    unsigned mask2 = 0b00000111;
#else
    unsigned mask1 = 0xC0;
    unsigned mask2 = 0x07;
#endif
    if ( i & mask1 )
        return 1;
    if ( i & mask2 )
        return 2;
    return 0;
}

static constexpr struct change_these_options_to_select_what_will_be_printed
{
    constexpr static int longest_macro_name { 44 };
    constexpr static bool titles               = 1;
    constexpr static bool counters             = 1;
    constexpr static bool attributes           = 1;
    constexpr static bool standard_values      = 1;
    constexpr static bool compiler_specific    = 1;
    constexpr static bool core_features        = 1;
    constexpr static bool lib_features         = 1;
    constexpr static bool supported_features   = 1;
    constexpr static bool unsupported_features = 1;
    constexpr static bool sort_by_date         = 0;
    constexpr static bool separate_year_month  = 1;
    constexpr static bool separated_revisions  = 1;
    constexpr static bool latest_revisions     = 1;
    constexpr static bool cxx98                = 0;
    constexpr static bool cxx11                = 1;
    constexpr static bool cxx14                = 1;
    constexpr static bool cxx17                = 1;
    constexpr static bool cxx20                = 1;
    constexpr static bool cxx23                = 1;
    constexpr static bool cxx26                = 0;
} print;
 
void Cpp20_FeatureTestMacros::simpleExample()
{
    int ret = bar(1);
}