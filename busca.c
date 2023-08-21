#include <stdio.h>
#include "busca.h"

void minhaStrStr(char **matriz, char *stringUser, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            int k = 0;
            while (matriz[i][j + k] == stringUser[k] && stringUser[k] != '\0')
            {
                k++;
            }
            if (stringUser[k] == '\0')
            {
                printf("substring encontrada na horizontal direta no local [%d][%d] ate [%d][%d]\n", i+1, j+1, i+1, j+1+(--k));
                return;
            }
        }
    }
}

void minhaStrStrReverse(char **matriz, char *stringUser, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = colunas - 1; j >= 0; j--)
        {
            int k = 0;
            while (matriz[i][j - k] == stringUser[k] && stringUser[k] != '\0')
            {
                k++;
            }
            if (stringUser[k] == '\0')
            {
                printf("substring encontrada na horizontal reversa no local [%d][%d] ate [%d][%d]\n", i+1, j+1, i+1, j+1-(--k));
                return;
            }
        }
    }
}

void minhaStrStrVert (char **matriz, char *stringUser, int linhas, int colunas)
{
    for (int j = 0; j < colunas; j++)
    {
        for (int i = 0; i < linhas; i++)
        {
            int k = 0;
            while ((i+k) < linhas && matriz[i+k][j] == stringUser[k] && stringUser[k] != '\0')
            {
                k++;
            }
            if (stringUser[k] == '\0')
            {
                printf("substring encontrada na vertical direta no local [%d][%d] ate [%d][%d]\n", i+1, j+1, i+1+(--k), j+1);
                return;
            }
        }
    }
}

void minhaStrStrVertRev (char **matriz, char *stringUser, int linhas, int colunas)
{
    for (int j = 0; j < colunas; j++)
    {
        for (int i = linhas -1; i >= 0; i--)
        {
            int k = 0;
            while ((i-k) >= 0 && matriz[i-k][j] == stringUser[k] && stringUser[k] != '\0')
            {
                k++;
            }
            if (stringUser[k] == '\0')
            {
                printf("substring encontrada na vertical inversa no local [%d][%d] ate [%d][%d]\n", i+1, j+1, i+1-(--k), j+1);
                return;
            }
        }
    }
}