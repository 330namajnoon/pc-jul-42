#include "header.h"

int read_file(char *str,char *src)
{
    int vars[3];
    char c;
    char line[100];
    char *data;

    vars[0] = open(src,O_RDONLY);
    if(vars[0] == -1)
        return (-1);
    vars[1] = 0;
    while (read(vars[0], &c, 1) > 0)
        if(c != '\0')
            vars[1]++;
    close(vars[0]);
    vars[0] = open(src,O_RDONLY);
    if(vars[0] == -1)
        return (-1);
    data = (char*)malloc((vars[1]) * sizeof(char));
    vars[2] = -1;
    while (read(vars[0], &c, 1) > 0)
        if(c != '\0')
            data[++vars[2]] = c;
    str_to_vars(data,str);
    free(data);
    close(vars[0]);
    return (0);
}