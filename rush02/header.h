#ifndef HEADER_H
# define HEADER_H

//# define __BUFF 8

#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

struct Data {
    int n;
    char val[20];
};

void rush(int argc, char** argv);
void str_to_vars(char *data_str,char *str);
int read_file(char *str,char *src);
int translator(struct Data *data, int data_size,char *str);
int ft_atoi(char *str);
char* ft_strcpy(char* destino, const char* origen);
void	numeros(char *str, int *vector);
int stringlen(char *str);
char* ft_strcat(char* destino, const char* fuente);
void print_number(long long int number,struct Data* lang_data,int data_size);


#endif
