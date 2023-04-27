#include <memory>

#include "Cpp11_AutoDecltype.hpp"
#include "Cpp11_InitializerList.hpp"
#include "Cpp11_UniformInitialization.hpp"
#include "Cpp11_VariadicTemplates.hpp"
#include "Cpp11_Lambdas.hpp"
#include "Cpp11_Quiz.hpp"

int main()
{
    /*
    std::unique_ptr<Cpp11_AutoDecltype> cppAutoDecltype = std::make_unique<Cpp11_AutoDecltype>();
    cppAutoDecltype->auto_TemplateTypeDeduction_NormalReferences();
    cppAutoDecltype->auto_TemplateTypeDeductionUniversalReferences();
    cppAutoDecltype->auto_TemplateTypeDeductionByValueParameter();
    cppAutoDecltype->decltype_DeductionOfVariable();
    cppAutoDecltype->decltype_DeductionOfExpressionLvalue();
    cppAutoDecltype->auto_TemplateArgumentDeduction();
    cppAutoDecltype->auto_SimpleTypeDeduction();
    cppAutoDecltype->auto_ConstTypeDeduction();

    std::unique_ptr<Cpp11_InitializerList> cppInitList = std::make_unique<Cpp11_InitializerList>();
    cppInitList->initializerList_SimpleExamples();

    std::unique_ptr<Cpp11_UniformInitialization> cppUniInit = std::make_unique<Cpp11_UniformInitialization>();
    cppUniInit->uniformInit_SimpleExample();

    std::unique_ptr<Cpp11_Lambdas> cppLambdas = std::make_unique<Cpp11_Lambdas>();
    cppLambdas->lambdas_SimpleExample();
    cppLambdas->lambdas_UseInFunction();

    std::unique_ptr<Cpp11_VariadicTemplate> cppVariadicTemplates = std::unique_ptr<Cpp11_VariadicTemplate>();
    cppVariadicTemplates->variadicTemplate_SimpleExmple();
    */

    std::unique_ptr<Cpp11_Quiz> cppQuiz = std::make_unique<Cpp11_Quiz>();
    //cppQuiz->quiz_140();
    //cppQuiz->quiz_105();
    //cppQuiz->quiz_229();
    //cppQuiz->quiz_337();
    //cppQuiz->quiz_001();
    //cppQuiz->quiz_239();
    //cppQuiz->quiz_281();
    //cppQuiz->quiz_339();
    //cppQuiz->quiz_193();
    //cppQuiz->quiz_312();
    //cppQuiz->quiz_206();
    cppQuiz->quiz_235();
    return 0;
}