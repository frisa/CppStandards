#include "Linux_Fork.hpp"
#include <iostream>
#include <unistd.h>

void Linux_Fork::SimpleExample()
{
    std::cout << "application started\n";
    pid_t procId;
    //procId = fork();
    if ((procId = fork()))
    {
        std::cout << "parent process: " << procId << std::endl;
    }
    else{
        std::cout << "child process(0):" << procId << std::endl;
    }
}