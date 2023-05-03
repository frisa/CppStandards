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
        )