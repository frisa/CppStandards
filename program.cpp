#include <memory>

#include "Cpp11_AutoDecltype.hpp"

int main()
{
    std::unique_ptr<Cpp11_AutoDecltype> cpp = std::make_unique<Cpp11_AutoDecltype>();
    cpp->auto_TemplateTypeDeduction_NormalReferences();
    cpp->auto_TemplateTypeDeductionUniversalReferences();
    cpp->auto_TemplateTypeDeductionByValueParameter();
    cpp->decltype_DeductionOfVariable();
    cpp->decltype_DeductionOfExpressionLvalue();
    //cpp->auto_TemplateArgumentDeduction();
    //cpp->auto_SimpleTypeDeduction();
    //cpp->auto_ConstTypeDeduction();
    return 0;
}