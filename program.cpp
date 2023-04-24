#include <memory>

#include "Cpp11_AutoDecltype.hpp"

int main()
{
    std::unique_ptr<Cpp11_AutoDecltype> cpp = std::make_unique<Cpp11_AutoDecltype>();
    cpp->auto_TemplateTypeDeductionReferences();
    cpp->auto_TemplateTypeDeductionUniversalReferences();
    cpp->auto_TemplateTypeDeductionByValueParameter();
    //cpp->auto_TemplateArgumentDeduction();
    //cpp->auto_SimpleTypeDeduction();
    //cpp->auto_ConstTypeDeduction();
    return 0;
}