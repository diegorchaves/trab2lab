#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

void leLinhasColunas (int *linhas, int *colunas)
{
    printf ("Digite a quantidade de linhas: ");
    scanf ("%d", linhas);
    printf ("Digite a quantidade de colunas: ");
    scanf ("%d", colunas);
}

char **alocaMatriz (int linhas, int colunas)
{
    char **matrizAlocada;

    matrizAlocada = (char**)malloc(sizeof(char*)*linhas);
    
    for (int i = 0; i < linhas; i++)
    {
        matrizAlocada[i] = (char*)malloc(sizeof(char)*colunas);
    }

    if (matrizAlocada == NULL)
    {
        printf ("Memoria insuficiente.\n");
        exit (1);
    }

    return matrizAlocada;
}

void desalocaMatriz (int linhas, char **matriz)
{
    for (int i = 0; i < linhas; i++)
    {
        free (matriz[i]);
    }
    free (matriz);
}

void imprimeMatriz (char **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf ("%c ", matriz[i][j]);
        }
        printf ("\n");
    }
}