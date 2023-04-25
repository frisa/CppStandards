#include <iostream>

class Cpp11_AutoDecltype{
public:

    // auto type deduction
    void auto_RvalueLvalue();
    void auto_TemplateTypeDeduction_NormalReferences();
    void auto_TemplateTypeDeductionUniversalReferences();
    void auto_TemplateTypeDeductionByValueParameter();
    void auto_TypeDecutionBracedInitializer();
    void auto_TemplateArgumentDeduction();
    void auto_SimpleTypeDeduction();
    void auto_ConstTypeDeduction();

    // decltype type deduction
    void decltype_DeductionOfVariable();
    void decltype_DeductionOfExpressionLvalue();
    void decltype_auto_DeductionOfReturnType();

};