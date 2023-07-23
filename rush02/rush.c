#include "header.h"

void rush(int argc, char** argv)
{
    int i;

    i = -1;
    while (argv[1][++i] != '\0')
        if(!(argv[1][i] >= '0' && argv[1][i] <= '9'))
        {
            write(1,"Error!\n",7);
            return;
        }
    if(i > 10)
    {
        write(1,"Error!\n",7);
        return;
    }
    if(argc == 2)
    {
        if(read_file(argv[1],"numbers.dict") == -1)
            write(1,"Dict Error!\n",12);
    }
    if(argc == 3)
    {
        if(read_file(argv[1],argv[2]) == -1);
            write(1,"Dict Error!\n",12);
    }
}