#include <memory>

#include "Cpp11_AutoDecltype.hpp"
#include "Cpp11_DefaultedDeletestFunctions.hpp"
#include "Cpp11_DeclvalDecltype.hpp"
#include "Cpp11_InitializerList.hpp"
#include "Cpp11_UniformInitialization.hpp"
#include "Cpp11_VariadicTemplates.hpp"
#include "Cpp11_Lambdas.hpp"
#include "Cpp11_Quiz.hpp"
#include "Cpp14_VariableTemplates.hpp"
#include "Cpp14_IntegerLiteral.hpp"
#include "CppXX_ComprehensivQuiz.hpp"
#include "Cpp11_AlignmentReq.hpp"
#include "Cpp11_GeneralizedUnions.hpp"
#include "Cpp14_GenericLambdas.hpp"
#include "Cpp17_NesteadNamespaces.hpp"
#include "Cpp17_VariableDeclarationIfSwitch.hpp"
#include "Linux_Fork.hpp"
#include "Linux_Signals.hpp"
#include "Cpp17_Optional.hpp"
#include "Cpp_XX_ClmPlayground.hpp"
#include "PLAYGROUND.hpp"

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
    

    std::unique_ptr<Cpp14_VariableTemplates> cppVarTemplates = std::make_unique<Cpp14_VariableTemplates>();
    cppVarTemplates->variableTemplates_SimpleExample();

    std::unique_ptr<Cpp14_GenericLambdas> cppGenericLambdas = std::make_unique<Cpp14_GenericLambdas>();
    cppGenericLambdas->genericLambdas_SimpleExample();

    std::unique_ptr<Cpp14_IntegerLiteral> cppIntLit = std::make_unique<Cpp14_IntegerLiteral>();
    cppIntLit->intLit_SimpleExample();

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
    //cppQuiz->quiz_235();
    cppQuiz->quiz_249();

    std::unique_ptr<Cpp17_NesteadNamespaces> nestName = std::make_unique<Cpp17_NesteadNamespaces>();
    nestName->nestName_SimpleExample();

    std::unique_ptr<Cpp11_AlignmentReq> cppAligReq = std::make_unique<Cpp11_AlignmentReq>();
    cppAligReq->alignReq_SimpleExample();

    std::unique_ptr<Cpp11_GeneralizedUnions> cppGenUni =  std::make_unique<Cpp11_GeneralizedUnions>();
    cppGenUni->genUni_simpleExample(); */

    //std::unique_ptr<Cpp11_DeclvalDecltype> declvalEx = std::make_unique<Cpp11_DeclvalDecltype>();
    //declvalEx->simpleExample();

    //std::shared_ptr<Playground> play = std::make_unique<Playground>();
    //play->run();
    //Linux_Fork::SimpleExample();
    Linux_Signals::simpleExample();
/*
    std::unique_ptr<ClmPlayground> clm = std::make_unique<ClmPlayground>();
    clm->run();

    std::unique_ptr<UseOptional> opt = std::make_unique<UseOptional>();
    opt->run();*/
    return 0;
}