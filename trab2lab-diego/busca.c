#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "busca.h"

bool buscaHorizontalDireta (char **matriz, char *stringProcurada, int linhas, int colunas)
{
    bool encontrouLocal = false;

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            int k = 0;
            while (matriz[i][j + k] == stringProcurada[k] && stringProcurada[k] != '\0')
            {
                k++;
            }
            if (stringProcurada[k] == '\0')
            {
                printf("Palavra \"%s\" encontrada na horizontal direta no local [%d][%d] ate [%d][%d]\n", stringProcurada, i+1, j+1, i+1, j+1+(--k));
                encontrouLocal = true;
                return encontrouLocal;

            }
        }
    }
    return encontrouLocal;
}

bool buscaHorizontalInversa (char **matriz, char *stringProcurada, int linhas, int colunas)
{
    bool encontrouLocal = false;

    for (int i = 0; i < linhas; i++)
    {
        for (int j = colunas - 1; j >= 0; j--)
        {
            int k = 0;
            while (matriz[i][j - k] == stringProcurada[k] && stringProcurada[k] != '\0')
            {
                k++;
            }
            if (stringProcurada[k] == '\0')
            {
                printf("Palavra \"%s\" encontrada na horizontal Inversa no local [%d][%d] ate [%d][%d]\n", stringProcurada, i+1, j+1, i+1, j+1-(--k));
                encontrouLocal = true;
                return encontrouLocal;
            }
        }
    }
    return encontrouLocal;
}

bool buscaVerticalDireta (char **matriz, char *stringProcurada, int linhas, int colunas)
{
    if (strcmp (stringProcurada, "sair") == 0)
    {
        printf ("Obrigado por jogar!\n");
        exit (1);
    }

    bool encontrouLocal = false;

    for (int j = 0; j < colunas; j++)
    {
        for (int i = 0; i < linhas; i++)
        {
            int k = 0;
            while ((i+k) < linhas && matriz[i+k][j] == stringProcurada[k] && stringProcurada[k] != '\0')
            {
                k++;
            }
            if (stringProcurada[k] == '\0')
            {
                printf("Palavra \"%s\" encontrada na vertical direta no local [%d][%d] ate [%d][%d]\n", stringProcurada, i+1, j+1, i+1+(--k), j+1);
                encontrouLocal = true;
                return encontrouLocal;
            }
        }
    }
    return encontrouLocal;
}

bool buscaVerticalInversa (char **matriz, char *stringProcurada, int linhas, int colunas)
{
    bool encontrouLocal = false;

    for (int j = 0; j < colunas; j++)
    {
        for (int i = linhas -1; i >= 0; i--)
        {
            int k = 0;
            while ((i-k) >= 0 && matriz[i-k][j] == stringProcurada[k] && stringProcurada[k] != '\0')
            {
                k++;
            }
            if (stringProcurada[k] == '\0')
            {
                printf("Palavra \"%s\" encontrada na vertical inversa no local [%d][%d] ate [%d][%d]\n", stringProcurada, i+1, j+1, i+1-(--k), j+1);
                encontrouLocal = true;
                return encontrouLocal;
            }
        }
    }
    return encontrouLocal;
}

bool buscaDiagonalPrincipalDireta (char **matriz, char *stringProcurada, int linhas, int colunas)
{
    bool encontrouLocal = false;

        for (int i = 0; i < linhas; i++)
        {
          for (int j = 0; j < colunas; j++)
            {
              int k = 0;
              while ((i+k) < linhas && (j+k) < colunas && matriz[i+k][j+k] == stringProcurada[k] && stringProcurada[k] != '\0')
                {
                    k++;
                }
              if (stringProcurada[k] == '\0')
                {
                    printf("Palavra \"%s\" encontrada na diagonal principal direta no local [%d][%d] ate [%d][%d]\n", stringProcurada, i+1, j+1, i+1+(k), j+1+(--k));
                    encontrouLocal = true;
                    return encontrouLocal;
                }
            }
        }

    return encontrouLocal;
}

bool buscaDiagonalPrincipalInversa (char **matriz, char *stringProcurada, int linhas, int colunas)
{
    bool encontrouLocal = false;

        for (int j = 0; j < colunas; j++)
        {
          for (int i = linhas -1; i >= 0 ; i--)
            {
              int k = 0;
              while ((i-k) >= 0 && (j-k) >= 0 && matriz[i-k][j-k] == stringProcurada[k] && stringProcurada[k] != '\0')
                {
                    k++;
                }
              if (stringProcurada[k] == '\0')
                {
                    printf("Palavra \"%s\" encontrada na diagonal principal inversa no local [%d][%d] ate [%d][%d]\n", stringProcurada, i+1, j+1, i+1-(k), j+1-(--k));
                    encontrouLocal = true;
                    return encontrouLocal;
                }
            }
        }

    return encontrouLocal;
}

bool buscaDiagonalSecundariaDireta (char **matriz, char *stringProcurada, int linhas, int colunas)
{
    bool encontrouLocal = false;

        for (int i = 0; i < linhas; i++)
        {
          for (int j = 0; j < colunas; j++)
            {
              int k = 0;
              while ((i+k) < linhas && (j-k) >= 0 && matriz[i+k][j-k] == stringProcurada[k] && stringProcurada[k] != '\0')
                {
                    k++;
                }
              if (stringProcurada[k] == '\0')
                {
                    printf("Palavra \"%s\" encontrada na diagonal secundaria direta no local [%d][%d] ate [%d][%d]\n", stringProcurada, i+1, j+1, i+1+(k), j+1-(--k));
                    encontrouLocal = true;
                    return encontrouLocal;
                }
            }
        }

    return encontrouLocal;
}

bool buscaDiagonalSecundariaInversa (char **matriz, char *stringProcurada, int linhas, int colunas)
{
    bool encontrouLocal = false;

        for (int j = 0; j < colunas; j++)
        {
          for (int i = linhas -1; i >= 0 ; i--)
            {
              int k = 0;
              while ((i-k) >= 0 && (j+k) < colunas && matriz[i-k][j+k] == stringProcurada[k] && stringProcurada[k] != '\0')
                {
                    k++;
                }
              if (stringProcurada[k] == '\0')
                {
                    printf("Palavra \"%s\" encontrada na diagonal secundaria inversa no local [%d][%d] ate [%d][%d]\n",stringProcurada, i+1, j+1, i+1-(k), j+1+(--k));
                    encontrouLocal = true;
                    return encontrouLocal;
                }
            }
        }

    return encontrouLocal;
}

void buscaPalavra (char **matriz, char *palavra, int linhas, int colunas)
{   
    bool encontrou = false;

    encontrou = buscaHorizontalDireta(matriz, palavra, linhas, colunas);
    encontrou = buscaHorizontalInversa(matriz, palavra, linhas, colunas);    
    encontrou = buscaVerticalDireta(matriz, palavra, linhas, colunas);
    encontrou = buscaVerticalInversa(matriz, palavra, linhas, colunas);
    encontrou = buscaDiagonalPrincipalDireta(matriz, palavra, linhas, colunas);
    encontrou = buscaDiagonalPrincipalInversa(matriz, palavra, linhas, colunas);
    encontrou = buscaDiagonalSecundariaDireta(matriz, palavra, linhas, colunas);
    encontrou = buscaDiagonalSecundariaInversa(matriz, palavra, linhas, colunas);
    
    if(!encontrou){
        printf("A palavra \"%s\" nao foi encontrada.\n", palavra);
    }
}