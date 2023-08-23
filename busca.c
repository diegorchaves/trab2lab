#include <stdio.h>
#include <stdbool.h>
#include "busca.h"

bool buscaHorizontalDireta (char **matriz, char *stringUser, int linhas, int colunas)
{
    bool encontrouLocal = false;

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
                encontrouLocal = true;
                return encontrouLocal;

            }
        }
    }
    return encontrouLocal;
}

bool buscaHorizontalInversa (char **matriz, char *stringUser, int linhas, int colunas)
{
    bool encontrouLocal = false;

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
                printf("substring encontrada na horizontal Inversa no local [%d][%d] ate [%d][%d]\n", i+1, j+1, i+1, j+1-(--k));
                encontrouLocal = true;
                return encontrouLocal;
            }
        }
    }
    return encontrouLocal;
}

bool buscaVerticalDireta (char **matriz, char *stringUser, int linhas, int colunas)
{
    bool encontrouLocal = false;

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
                encontrouLocal = true;
                return encontrouLocal;
            }
        }
    }
    return encontrouLocal;
}

bool buscaVerticalInversa (char **matriz, char *stringUser, int linhas, int colunas)
{
    bool encontrouLocal = false;

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
                encontrouLocal = true;
                return encontrouLocal;
            }
        }
    }
    return encontrouLocal;
}

bool buscaDiagonalPrincipalDireta (char **matriz, char *stringUser, int linhas, int colunas)
{
    bool encontrouLocal = false;

        for (int i = 0; i < linhas; i++)
        {
          for (int j = 0; j < colunas; j++)
            {
              int k = 0;
              while ((i+k) < linhas && (j+k) < colunas && matriz[i+k][j+k] == stringUser[k] && stringUser[k] != '\0')
                {
                    k++;
                }
              if (stringUser[k] == '\0')
                {
                    printf("substring encontrada na diagonal principal direta no local [%d][%d] ate [%d][%d]\n", i+1, j+1, i+1+(k), j+1+(--k));
                    encontrouLocal = true;
                    return encontrouLocal;
                }
            }
        }

    return encontrouLocal;
}

bool buscaDiagonalPrincipalInversa (char **matriz, char *stringUser, int linhas, int colunas)
{
    bool encontrouLocal = false;

        for (int j = 0; j < colunas; j++)
        {
          for (int i = linhas -1; i >= 0 ; i--)
            {
              int k = 0;
              while ((i-k) >= 0 && (j-k) >= 0 && matriz[i-k][j-k] == stringUser[k] && stringUser[k] != '\0')
                {
                    k++;
                }
              if (stringUser[k] == '\0')
                {
                    printf("substring encontrada na diagonal principal inversa no local [%d][%d] ate [%d][%d]\n", i+1, j+1, i+1-(k), j+1-(--k));
                    encontrouLocal = true;
                    return encontrouLocal;
                }
            }
        }

    return encontrouLocal;
}

bool buscaDiagonalSecundariaDireta (char **matriz, char *stringUser, int linhas, int colunas)
{
    bool encontrouLocal = false;

        for (int i = 0; i < linhas; i++)
        {
          for (int j = 0; j < colunas; j++)
            {
              int k = 0;
              while ((i+k) < linhas && (j-k) >= 0 && matriz[i+k][j-k] == stringUser[k] && stringUser[k] != '\0')
                {
                    k++;
                }
              if (stringUser[k] == '\0')
                {
                    printf("substring encontrada na diagonal secundaria direta no local [%d][%d] ate [%d][%d]\n", i+1, j+1, i+1+(k), j+1-(--k));
                    encontrouLocal = true;
                    return encontrouLocal;
                }
            }
        }

    return encontrouLocal;
}

bool buscaDiagonalSecundariaInversa (char **matriz, char *stringUser, int linhas, int colunas)
{
    bool encontrouLocal = false;

        for (int j = 0; j < colunas; j++)
        {
          for (int i = linhas -1; i >= 0 ; i--)
            {
              int k = 0;
              while ((i-k) >= 0 && (j+k) < colunas && matriz[i-k][j+k] == stringUser[k] && stringUser[k] != '\0')
                {
                    k++;
                }
              if (stringUser[k] == '\0')
                {
                    printf("substring encontrada na diagonal secundaria inversa no local [%d][%d] ate [%d][%d]\n", i+1, j+1, i+1-(k), j+1+(--k));
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

    //horizontal direta
    encontrou = buscaHorizontalDireta(matriz, palavra, linhas, colunas);

    //horizontal Inversa
    if (!encontrou)
    {
       encontrou = buscaHorizontalInversa(matriz, palavra, linhas, colunas);
    }
    //vertical direta
    if (!encontrou)
    {
       encontrou = buscaVerticalDireta(matriz, palavra, linhas, colunas);
    }
    //vertical Inversa
    if (!encontrou)
    {
       encontrou = buscaVerticalInversa(matriz, palavra, linhas, colunas);
    }
    // diagonal principal direta
    if (!encontrou)
    {
        encontrou = buscaDiagonalPrincipalDireta(matriz, palavra, linhas, colunas);
    }
    // diagonal principal Inversa
    if (!encontrou)
    {
       encontrou = buscaDiagonalPrincipalInversa(matriz, palavra, linhas, colunas);
    }
    // diagonal secundaria direta
    if (!encontrou)
    {
       encontrou = buscaDiagonalSecundariaDireta(matriz, palavra, linhas, colunas);
    }
    // diagonal secundaria Inversa
     if (!encontrou)
    {
       encontrou = buscaDiagonalSecundariaInversa(matriz, palavra, linhas, colunas);
    }
    
    if (encontrou)
    {
        printf("Achou\n");
    }
    else
    {
        printf("Nao achou\n");
    }
}