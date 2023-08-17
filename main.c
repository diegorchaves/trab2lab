#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char *alocaString(int linhas, int colunas){
    char *v;

    v = (char*) malloc(linhas*colunas*sizeof(char));
    if(v==NULL){
        printf("Memoria insuficiente. \n");
        exit(1);
    }
    return v;
}

void leStringUser(char *string, int tamanhoMatriz){
    printf("Digite uma String:  ");
    getchar();
    fgets(string, tamanhoMatriz+1, stdin);
}

void retiraEspacos(char *string, int tamanhoMatriz){
    int posicao = 0;

    for (int i = 0; i < tamanhoMatriz+1; i++) {
        if (string[i] == ' ') continue;
        string[posicao] = string[i];
        posicao++;
    }
    string[posicao] = '\0';
}

void preencheRestoString(char *string, int tamanhoMatriz){
    int num = strlen(string);

    for(int i = num-1; i < tamanhoMatriz+1; i++){
        string[i] = '.';
    }
    
}

void insereStringNaMatriz(char *string, char **matriz, int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            matriz[i][j] = string[i*colunas+j];
        }
    }
}

void imprimeMatriz (int linhas, int colunas, char** matriz){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main ()
{
    int linhas, colunas;
    char **matriz;
    char *string;
    int tamanhoMatriz; 
    
    leLinhasColunas (&linhas, &colunas);
    matriz = alocaMatriz(linhas, colunas);
    string = alocaString(linhas, colunas);
    printf ("linhas = %d, colunas = %d\n", linhas, colunas);
    tamanhoMatriz = linhas*colunas;
    
    //numDiagonais(linhas, colunas);
    leStringUser(string, tamanhoMatriz);
    retiraEspacos(string, tamanhoMatriz);
    preencheRestoString(string, tamanhoMatriz);
    insereStringNaMatriz(string, matriz, linhas, colunas);
    imprimeMatriz(linhas, colunas, matriz);

}

