#include "header.h"

void arr_null(char *arr)
{
    int i;

    i = -1;
    while (arr[++i] != '\0')
        arr[i] = '\0';
}

void v_to_v_if(int *ijtlv, char *data_str, char vs[2][20])
{
    if (data_str[ijtlv[0]] != ':')
        vs[0][++ijtlv[1]] = data_str[ijtlv[0]];
    else
    {
        vs[0][++ijtlv[1]] = '\0';
        ijtlv[2] = 1;
        ijtlv[1] = -1;
    }
}

void v_to_v_else(char *data_str,int *ijtlv,char vs[2][20],struct Data *data)
{
    if (data_str[ijtlv[0]] != '\n')
    {
        vs[1][++ijtlv[1]] = data_str[ijtlv[0]];
    }
    else
    {
        ijtlv[2] = 0;
        ijtlv[1] = -1;
        data[++ijtlv[4]].n = ft_atoi(vs[0]);
        ft_strcpy(data[ijtlv[4]].val, vs[1]);
        arr_null(vs[0]);
        arr_null(vs[1]);
        ijtlv[1] = -1;
    }
}

int v_to_v(int *ijtlv, char *data_str, char *str)
{
    char vs[2][20];
    struct Data *data;

    data = (struct Data *)malloc(ijtlv[3] * sizeof(struct Data));
    if (!data)
    {
        return (-1);
    }
    while (data_str[++ijtlv[0]] != '\0')
    {
        if ((data_str[ijtlv[0]] > 32 && data_str[ijtlv[0]] < 127) || data_str[ijtlv[0]] == '\n')
        {
            if (ijtlv[2] == 0)
                v_to_v_if(ijtlv, data_str, vs);
            else
                v_to_v_else(data_str,ijtlv,vs,data);
        }
    }
    translator(data, ijtlv[3], str);
    free(data);
    return (1);
}

void str_to_vars(char *data_str, char *str)
{
    int ijtlv[5];

    ijtlv[3] = 0;
    ijtlv[0] = -1;
    ijtlv[1] = -1;
    ijtlv[2] = 0;
    ijtlv[4] = -1;
    while (data_str[++ijtlv[0]] != '\0')
        if (data_str[ijtlv[0]] == ':')
            ijtlv[3]++;
    ijtlv[0] = -1;
    v_to_v(ijtlv, data_str, str);
}