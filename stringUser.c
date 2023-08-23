#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stringUser.h"

char *alocaString (int tamanhoMatriz)
{
    char *stringAlocada = (char*)malloc(sizeof(char)*3*tamanhoMatriz);

    if (stringAlocada == NULL)
    {
        printf ("Memoria insuficiente.\n");
        exit (1);
    }

    return stringAlocada;
}

void retiraEspacos(char *stringUser, int tamanhoMatriz)
{
    int posicao = 0;

    for (int i = 0; i < tamanhoMatriz * 2; i++) {
        if (stringUser[i] == ' ')
        {
            continue;
        }
        stringUser[posicao] = stringUser[i];
        posicao++;
    }
    stringUser[posicao] = '\0';
}

void leStringUser (char *stringUser, int tamanhoMatriz)
{
    printf ("Digite a string: ");
    scanf(" %[^\t\n]s", stringUser);
    retiraEspacos (stringUser, tamanhoMatriz);
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