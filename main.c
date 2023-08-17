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

int *alocaString(int linhas, int colunas){
    int *v;

    v = (int*) malloc(linhas*colunas*sizeof(int));
    if(v==NULL){
        printf("Memoria insuficiente. \n");
        exit(1);
    }
    return v;
}


int main ()
{
    int linhas, colunas;
    int posicao = 0;
    char *string;
    leLinhasColunas (&linhas, &colunas);
    string = alocaString(linhas, colunas);
    int tamanhoMatriz = linhas*colunas;
    printf ("linhas = %d, colunas = %d\n", linhas, colunas);

    //numDiagonais(linhas, colunas);

    printf("Digite uma String:  ");
    fflush(stdin);
    fgets(string, tamanhoMatriz+1, stdin);
    int len = strlen(string);
    printf("%s\n", string);
    for (int i = 0; i < len; i++) {
        if (string[i] == ' ') continue;
        string[posicao] = string[i];
        posicao++;
    }
    string[posicao] = '\0';
    printf("String sem espacos em branco: %s\n", string);

}


