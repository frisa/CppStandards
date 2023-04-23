cmake_minimum_required(VERSION 3.22)
project(cppStandards 
    VERSION 1.0 
    DESCRIPTION "The application for C++ standards presentation"
)
add_executable(myProgram WIN32 "program.cpp")
set_property(TARGET myProgram PROPERTY CXX_STANDARD 17)
target_sources(myProgram
    PRIVATE
        "Cpp11_AutoDecltype.cpp"
    PUBLIC
        "Cpp11_AutoDecltype.hpp")