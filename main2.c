#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    //fflush (stdin);
    printf ("Digite a string (sem espacos): ");
    getchar ();
    fgets (stringUser, tamanho + 1, stdin);
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

int main ()
{
    int linhas, colunas;
    char **matriz;
    char *stringUser;
    int tamanhoMatriz;

    leLinhasColunas (&colunas, &linhas);

    tamanhoMatriz = colunas * linhas;

    matriz = alocaMatriz(linhas, colunas);

    stringUser = alocaString (tamanhoMatriz);

    leStringUser (stringUser, tamanhoMatriz);

    insereStringNaMatriz (stringUser, matriz, linhas, colunas);

    imprimeMatriz (matriz, linhas, colunas);
}