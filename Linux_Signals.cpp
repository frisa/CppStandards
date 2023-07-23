#include "Linux_Signals.hpp"
#include <iostream>
#include <signal.h>
#include <unistd.h>

namespace{
    void sig_int(int num)
    {
        write(STDOUT_FILENO, "SIGINT\n", 7);
    }
    void sig_term(int num)
    {
        write(STDOUT_FILENO, "SIGTERM\n", 8);
    }
}

void Linux_Signals::simpleExample()
{
    std::cout << "starting the application\n";
    signal(SIGINT, sig_int);

    struct sigaction sa;
    sa.sa_handler = sig_term;
    sigaction(SIGTERM, &sa, NULL);
    while (1)
    {
        printf("running\n");
        usleep(500000);
    }
}