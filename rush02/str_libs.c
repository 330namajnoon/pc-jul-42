char* ft_strcpy(char* destino, const char* origen) {
    char* inicio_destino;
    
    inicio_destino = destino;
    while (*origen != '\0') {
        *destino = *origen;
        destino++;
        origen++;
    }
    *destino = '\0';
    return inicio_destino;
}

char* ft_strcat(char* destino, const char* fuente)
{
    char* resultado = destino;


    while (*destino) {
        destino++;
    }

    while (*fuente) {
        *destino = *fuente;
        destino++;
        fuente++;
    }

    *destino = '\0';

    return resultado;
}

int stringlen(char *str)
{
    int l;

	l = 0;
	while (str[l] != '\0')
		l++;
	return (l);
}
