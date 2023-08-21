#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
    printf ("Digite a string (sem espacos): ");
    //getchar ();
    //fgets (stringUser, tamanho + 1, stdin);
    //getchar ();
    scanf ("%s", stringUser);
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
                printf("substring encontrada na horizontal direta no local [%d][%d]\n", i+1, j+1);
                return;
            }
        }
    }
    //printf("substring não encontrada na matriz\n");
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
                printf("substring encontrada na horizontal reversa no local [%d][%d]\n", i+1, j+1);
                return;
            }
        }
    }
    //printf("substring não encontrada na matriz\n");
}

void minhaStrStrVert (char **matriz, char *stringUser, int linhas, int colunas)
{
    for (int j = 0; j < colunas; j++)
    {
        for (int i = 0; i < linhas; i++)
        {
            int k = 0;
            while (matriz[i+k][j] == stringUser[k] && stringUser[k] != '\0' && (i+k) < linhas)
            {
                k++;
            }
            if (stringUser[k] == '\0')
            {
                printf("substring encontrada na vertical direta no local [%d][%d]\n", i+1, j+1);
                return;
            }
        }
    }
    //printf("substring não encontrada na matriz\n");
}

int main ()
{
    int linhas, colunas;
    char **matriz;
    char *stringUser;
    char *stringProcurada;
    int tamanhoMatriz;

    leLinhasColunas (&linhas, &colunas);

    tamanhoMatriz = colunas * linhas;

    matriz = alocaMatriz(linhas, colunas);

    stringUser = alocaString (tamanhoMatriz);

    stringProcurada = alocaString (tamanhoMatriz);

    leStringUser (stringUser, tamanhoMatriz);

    insereStringNaMatriz (stringUser, matriz, linhas, colunas);

    imprimeMatriz (matriz, linhas, colunas);
    
    leStringUser (stringProcurada, tamanhoMatriz);

    puts (stringProcurada);

    //minhaStrStr (matriz, stringProcurada, linhas, colunas);

    //minhaStrStrReverse (matriz, stringProcurada, linhas, colunas);

    minhaStrStrVert (matriz, stringProcurada, linhas, colunas);

}