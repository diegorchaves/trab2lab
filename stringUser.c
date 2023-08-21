#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stringUser.h"

char *alocaString (int tamanho)
{
    char *stringAlocada = (char*)malloc(sizeof(char)*(tamanho+1));

    if (stringAlocada == NULL)
    {
        printf ("Memoria insuficiente.\n");
        exit (1);
    }

    return stringAlocada;
}

void leStringUser (char *stringUser, int tamanho)
{
    printf ("Digite a string (sem espacos): ");
    scanf ("%s", stringUser);
}

void completaStringUser (char *stringUser, int tamanhoMatriz)
{
    for (int i = strlen(stringUser); i < tamanhoMatriz; i++)
    {
        stringUser[i] = '*';
    }
}

void insereStringNaMatriz (char *stringUser, char **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            matriz[i][j] = stringUser[i*colunas+j];
        }
    }
}