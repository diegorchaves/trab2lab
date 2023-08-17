#include <stdio.h>
#include <stdlib.h>

char **alocaMatriz (int linhas, int colunas)
{
    char **matrizAlocada;
    matrizAlocada = (char**)malloc(sizeof(char*)*linhas);
    for (int i = 0; i < linhas; i++)
    {
        matrizAlocada[i] = (char*)malloc(sizeof(char)*colunas);
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

void leLinhasColunas (int *linhas, int *colunas)
{
    printf ("Digite a quantidade de linhas: ");
    scanf ("%d", linhas);
    printf ("Digite a quantidade de colunas: ");
    scanf ("%d", colunas);
}

void numDiagonais (int linhas, int colunas){
    int diagonais =     linhas+colunas-3;
   printf("diagonais: %d", diagonais);
}

int main ()
{
    int linhas, colunas;

    leLinhasColunas (&linhas, &colunas);

    printf ("linhas = %d, colunas = %d\n", linhas, colunas);

    numDiagonais(linhas, colunas);

}

