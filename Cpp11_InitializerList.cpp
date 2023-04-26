#include "Cpp11_InitializerList.hpp"
#include <vector>
#include <initializer_list>
#include <memory>

class InitListCls{
        std::vector<int> m_vector;
    public:
        InitListCls(const std::initializer_list<int>& values)
        {
            for(auto value:values)
            {
                m_vector.push_back(value);
            }
        }
};

void Cpp11_InitializerList::initializerList_SimpleExamples()
{
    // C++ 03 - non-convenient way how to initialize vector
    int arr[] = {1, 2, 3};
    std::vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);

    // C++ 11 - all containers in STL are extended by the initializr list constructor see the exmaple of the std::vector
    std::vector vec2 = { 1,
                         2,
                         3,
    };

    // use the custom initializer list constructor
    InitListCls cls1 = {1,2,3};
    InitListCls cls2{1,2,3};
    std::initializer_list<int> data = {1,2,3}; // would need to be over taken by the typed initializer list as the as brasket list cannot be deduced
    std::unique_ptr<InitListCls> cls = std::make_unique<InitListCls>(data);
}