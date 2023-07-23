#include "header.h"

char *find_number(int number,struct Data *data,int data_size)
{
    int i;

    i = -1;
    while (++i < data_size)
    {
        if(data[i].n == number)
            return (data[i].val);
    }
    return "\0";
}

void str_write(char *str)
{
    int i;

    i = -1;
    while (str[++i] != '\0')
        write(1,&str[i],1);
}

int translator(struct Data *data,int data_size,char *str)
{
    print_number(ft_atoi(str),data,data_size);
    
    return (0);
}