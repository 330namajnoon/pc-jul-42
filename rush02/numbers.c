#include "header.h"


char *get_val(int number,struct Data *data,int data_size)
{
    int i;

    i = -1;
    while (++i < data_size)
    {
        if(data[i].n == number)
            return (data[i].val);
    }
    return (0);
}

void append(char* dest,char* src) {
    dest += stringlen(dest);
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

void get_number(char* result, int number,struct Data* lang_data,int data_size) {
    if (number >= 100) {
        append(result,get_val(number / 100,lang_data,data_size));
        append(result," ");
        append(result, get_val(100,lang_data,data_size));
        number %= 100;
        if (number > 0) {
            append(result, " ");
        }
    }
    
    if (number >= 20) {
        append(result,get_val(((number / 10) * 10),lang_data,data_size));
        number %= 10;
        if (number > 0) {
            append(result, " ");
        }
    }
    
    if (number > 0) {
        append(result,get_val(number,lang_data,data_size));
    }
}

void print_number_if(int number,char *result,struct Data *lang_data,int data_size)
{
     if (number >= 1000000000) {
        get_number(result, number / 1000000000, lang_data,data_size);
        append(result," ");
        append(result, get_val(1000000000,lang_data,data_size));
        append(result," ");
        number %= 1000000000;
    }

    if (number >= 1000000) {
        get_number(result, number / 1000000, lang_data,data_size);
        append(result," ");
        append(result,get_val(1000000,lang_data,data_size) );
        append(result," ");
        number %= 1000000;
    }
    if (number >= 1000) {
        get_number(result, number / 1000, lang_data,data_size);
        append(result," ");
        append(result,get_val(1000,lang_data,data_size));
        append(result," ");
        number %= 1000;
    }
}

void print_number(long long int number,struct Data* lang_data,int data_size) {
    int i;
    char *result;

    result = (char*)malloc(200 * sizeof(char));
    if(!result)
    {
        write(1,"Error!",6);
        return;
    }
    print_number_if(number,result,lang_data,data_size);
    if (number == 0) {
        printf("%s\n", lang_data[0].val);
        return;
    }

    get_number(result, number, lang_data,data_size);
    result += 3;
    while (*result != '\0')
    {
        write(1,result,1);
        result++;
    }
    free(result);
}


