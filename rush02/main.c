#include "header.h"

int main(int argc, char **argv)
{
    if(argc == 1)
        return (1);
    else if (argc == 2 || argc == 3)
        rush(argc,argv);
    return (0);
}