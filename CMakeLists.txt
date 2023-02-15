cmake_minimum_required(VERSION 3.22)

message("Building cmake files")

project(myProgramProject 
    VERSION 1.0 
    DESCRIPTION "The application for C++ standards presentation"
)


add_executable(myProgram WIN32 "program.cpp")

target_compile_features(myProgram 
    PRIVATE 
        cxx_std_11
)