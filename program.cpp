#include <memory>

#include "Cpp11_AutoDecltype.hpp"

int main()
{
    std::unique_ptr<Cpp11_AutoDecltype> cpp = std::make_unique<Cpp11_AutoDecltype>();
    cpp->auto_TemplateArgumentDeduction();
    return 0;
}