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

void imprimeIndexColunas (int colunas)
{
    for (int i = 0; i <= colunas; i++)
    {
        if (i < 10)
        {
            printf ("%d  ", i);
        }
        else
        {
            printf ("%d ", i);
        }
    }
    printf ("\n");
}

void imprimeMatriz (char **matriz, int linhas, int colunas)
{
    imprimeIndexColunas (colunas);

    for (int i = 0; i < linhas; i++)
    {
        if (i < 9)
        {
            printf ("%d  ", i+1);
        }
        else
        {
            printf ("%d ", i+1);
        }
        for (int j = 0; j < colunas; j++)
        {
            printf ("%c  ", matriz[i][j]);
        }
        printf ("\n");
    }
}