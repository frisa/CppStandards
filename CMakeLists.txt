cmake_minimum_required(VERSION 3.22)
project(cppStandards 
    VERSION 1.0 
    DESCRIPTION "The application for C++ standards presentation"
)
add_executable(myProgram WIN32 "program.cpp")
set_property(TARGET myProgram PROPERTY CXX_STANDARD 17)
set_property(TARGET myProgram PROPERTY CXX_STANDARD_REQUIRED ON)
target_sources(myProgram
    PRIVATE
        "Cpp11_AutoDecltype.cpp"
        "Cpp11_InitializerList.cpp"
        "Cpp11_UniformInitialization.cpp"
        "Cpp11_Lambdas.cpp"
        "Cpp11_VariadicTemplates.cpp"
        "Cpp11_Quiz.cpp"
        "Cpp14_VariableTemplates.cpp"
        "Cpp14_GenericLambdas.cpp"
        "Cpp14_IntegerLiteral.cpp"
        "CppXX_ComprehensivQuiz.cpp"
        "Cpp11_AlignmentReq.cpp"
        "Cpp11_GeneralizedUnions.cpp"
        "PLAYGROUND.cpp"
        "Cpp17_NesteadNamespaces.cpp"
        "Cpp17_VariableDeclarationIfSwitch.cpp"
        "Cpp11_DeclvalDecltype.cpp"
<<<<<<< HEAD
        "Linux_Fork.cpp"
        "Linux_Signals.cpp"
=======
        "Cpp_XX_ClmPlayground.cpp"
        "Cpp17_Optional.cpp"
>>>>>>> main
    PUBLIC
        "Cpp11_AutoDecltype.hpp"
        "Cpp11_InitializerList.hpp"
        "Cpp11_UniformInitialization.hpp"
        "Cpp11_Lambdas.hpp"
        "Cpp11_VariadicTemplates.hpp"
        "Cpp11_Quiz.cpp"
        "Cpp14_VariableTemplates.hpp"
        "Cpp14_GenericLambdas.hpp"
        "Cpp14_IntegerLiteral.hpp"
        "CppXX_ComprehensivQuiz.hpp"
        "Cpp11_AlignmentReq.hpp"
        "Cpp11_GeneralizedUnions.hpp"
        "PLAYGROUND.hpp"
        "Cpp17_NesteadNamespaces.hpp"
        "Cpp17_VariableDeclarationIfSwitch.hpp"
        "Cpp11_DeclvalDecltype.hpp"
<<<<<<< HEAD
        "Linux_Fork.hpp"
        "Linux_Signals.hpp"
=======
        "Cpp_XX_ClmPlayground.hpp"
        "Cpp17_Optional.hpp"
>>>>>>> main
        )