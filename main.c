#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>    

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

char *alocaString(int linhas, int colunas){
    char *v;

    v = (char*) malloc(linhas*colunas*sizeof(char)+1);
    if(v==NULL){
        printf("Memoria insuficiente. \n");
        exit(1);
    }
    return v;
}

void leString(char *string, int tamanhoMatriz){
    printf("Digite uma String:  ");
    scanf(" %s", string);
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

bool procuraHorizontalDireta(char **matriz, char *palavra, int linhas, int colunas){
    bool encontrouLocal;
    int tamanhoString = strlen (palavra);

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas-tamanhoString+1; j++){
            if(matriz[i][j] == palavra[0]){
                encontrouLocal = true;
                for(int k = 1; k < tamanhoString; k++){
                    if(matriz[i][j+k] != palavra[k]){
                        encontrouLocal = false;
                        break;
                    }
                }
            }
        }
    }
    
    return encontrouLocal;
}

bool procuraHorizontalReversa(char **matriz, char *palavra, int linhas, int colunas){
    bool encontrouLocal;
    int tamanhoString = strlen (palavra);

    for(int i = 0; i < linhas; i++){
        for(int j = colunas-1; j >= colunas-tamanhoString; j--){
            if(matriz[i][j] == palavra[0]){
                encontrouLocal = true;
                for(int k = 1; k < tamanhoString; k++){
                    if(matriz[i][j-k] != palavra[k]){
                        encontrouLocal = false;
                        break;
                    }
                }
            }
        }
    }
    
    return encontrouLocal;
}

bool procuraVerticalDireta(char **matriz, char *palavra, int linhas, int colunas){
    bool encontrouLocal;
    int tamanhoString = strlen (palavra);

    for(int i = 0; i < linhas-tamanhoString+1; i++){
        for(int j = 0; j < colunas; j++){
            if(matriz[i][j] == palavra[0]){
                encontrouLocal = true;
                for(int k = 1; k < tamanhoString; k++){
                    if(matriz[i+k][j] != palavra[k]){
                        encontrouLocal = false;
                        break;
                    }
                }
            }
        }
    }
    
    return encontrouLocal;
}

bool procuraVerticalReversa(char **matriz, char *palavra, int linhas, int colunas){
    bool encontrouLocal;
    int tamanhoString = strlen (palavra);

    for(int i = linhas-1; i >= linhas-tamanhoString; i--){
        for(int j = 0; j < colunas; j++){
            if(matriz[i][j] == palavra[0]){
                encontrouLocal = true;
                for(int k = 1; k < tamanhoString; k++){
                    if(matriz[i-k][j] != palavra[k]){
                        encontrouLocal = false;
                        break;
                    }
                }
            }
        }
    }
    
    return encontrouLocal;
}

void procuraPalavra (char **matriz, char *palavra, int linhas, int colunas)
{   
    bool encontrou = false;

    //horizontal direta
    encontrou = procuraHorizontalDireta(matriz, palavra, linhas, colunas);

    //horizontal reversa
    if(!encontrou){
       encontrou = procuraHorizontalReversa(matriz, palavra, linhas, colunas);
    }
    //vertical direta
    if(!encontrou){
       encontrou = procuraVerticalDireta(matriz, palavra, linhas, colunas);
    }
    //vertical inversa
    if(!encontrou){
       encontrou = procuraVerticalReversa(matriz, palavra, linhas, colunas);
    }
    

    if(encontrou){
        printf("Achou\n");
    }else{
        printf("nao achou\n");
    }
}

int main ()
{
    int linhas, colunas;
    char **matriz;
    char *stringUser;
    char *stringProcurada;
    int tamanhoMatriz; 

    
    leLinhasColunas (&linhas, &colunas);
    matriz = alocaMatriz(linhas, colunas);
    stringUser = alocaString(linhas, colunas);
    stringProcurada = alocaString(linhas, colunas);
    tamanhoMatriz = linhas*colunas;
    
    //numDiagonais(linhas, colunas);
    leString(stringUser, tamanhoMatriz);
    insereStringNaMatriz(stringUser, matriz, linhas, colunas);
    imprimeMatriz(linhas, colunas, matriz);
    leString(stringProcurada, tamanhoMatriz);
    procuraPalavra(matriz, stringProcurada, linhas, colunas);
}


