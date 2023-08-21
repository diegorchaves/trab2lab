#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>    

void completaStringUser (char *stringUser, int tamanhoMatriz)
{
    for (int i = strlen(stringUser); i < tamanhoMatriz; i++)
    {
        stringUser[i] = '*';
    }
}

void retiraEspacos(char *string, int tamanhoMatriz){
    int tamanho = strlen(string);
    int count = 0;
    
    for (int i = 0; string[i]; i++){
        if (string[i] != ' '){
             string[count++] = string[i]; 
        }    
    }
        
    string[count] = '\0';
}

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

    v = (char*) malloc(linhas*colunas*3*sizeof(char));
    if(v==NULL){
        printf("Memoria insuficiente. \n");
        exit(1);
    }
    return v;
}

void leString(char *string, int tamanhoMatriz){
    printf("Digite uma String:  ");
    scanf(" %[^\t\n]s", string);

    retiraEspacos(string, tamanhoMatriz);
}

void insereStringNaMatriz(char *string, char **matriz, int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            matriz[i][j] = string[i*colunas+j];
        }
    }
}

void imprimeIndexColunas(int colunas){
    for(int indexCol = 0; indexCol <= colunas; indexCol++){
        if(indexCol < 10){
            printf("%d  ", indexCol);
        }else{
            printf("%d ", indexCol);
        }
    }
    printf("\n");
}

void imprimeMatriz (int linhas, int colunas, char** matriz){
    char espaco[2];
    imprimeIndexColunas(colunas);

    for(int i = 0; i < linhas; i++){
        memcpy(espaco,((i < 9) ? "  " : " "), 2); 
        printf("%d%s", i+1, espaco);
        
        for(int j = 0; j < colunas; j++){   
            printf("%c  ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool procuraHorizontalDireta(char **matriz, char *stringUser, int linhas, int colunas){
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
                printf("substring encontrada na horizontal direta no local [%d][%d]\n", i+1, j+1);
                encontrouLocal = true;
                return encontrouLocal;
            }
        }
    }

    return encontrouLocal;
}

bool procuraHorizontalReversa(char **matriz, char *stringUser, int linhas, int colunas){
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
                printf("substring encontrada na horizontal reversa no local [%d][%d]\n", i+1, j+1);
                encontrouLocal = true;
                return encontrouLocal;
            }
        }
    }

    return encontrouLocal;
}

bool procuraVerticalDireta(char **matriz, char *stringUser, int linhas, int colunas){
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
                printf("substring encontrada na vertical direta no local [%d][%d]\n", i+1, j+1);
                encontrouLocal = true;
                return encontrouLocal;
            }
        }
    }

    return encontrouLocal;
}

bool procuraVerticalReversa(char **matriz, char *stringUser, int linhas, int colunas){
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
                printf("substring encontrada na vertical reversa no local [%d][%d]\n", i+1, j+1);
                encontrouLocal = true;
                return encontrouLocal;
            }
        }
    }

    return encontrouLocal;
}

bool procuraDiagonalPrincipalDireta(char **matriz, char *stringUser, int linhas, int colunas){
    bool encontrouLocal = false;

        for (int i = 0; i < linhas; i++)
        {
          for (int j = 0; j < colunas; j++)
            {
              int k = 0;
              while (((i+k) < linhas || (i+k) < colunas) && matriz[i+k][j+k] == stringUser[k] && stringUser[k] != '\0')
                {
                    k++;
                }
              if (stringUser[k] == '\0')
                {
                    printf("substring encontrada na diagonal principal direta no local [%d][%d]\n", i+1, j+1);
                    encontrouLocal = true;
                    return encontrouLocal;
                }
            }
        }


    return encontrouLocal;
}

void procuraPalavra (char **matriz, char *palavra, int linhas, int colunas)
{   
    bool encontrou = false;

    //horizontal direta
    //    encontrou = procuraHorizontalDireta(matriz, palavra, linhas, colunas);

    // //horizontal reversa
    // if(!encontrou){
    //    encontrou = procuraHorizontalReversa(matriz, palavra, linhas, colunas);
    // }
    // //vertical direta
    // if(!encontrou){
    //    encontrou = procuraVerticalDireta(matriz, palavra, linhas, colunas);
    // }
    // //vertical inversa
    // if(!encontrou){
    //    encontrou = procuraVerticalReversa(matriz, palavra, linhas, colunas);
    // }
    if(!encontrou){
       encontrou = procuraDiagonalPrincipalDireta(matriz, palavra, linhas, colunas);
    }
    // if(!encontrou){
    //    encontrou = procuraDiagonalSecundaria(matriz, palavra, linhas, colunas);
    // }
    

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

    leString(stringUser, tamanhoMatriz);
    completaStringUser(stringUser, tamanhoMatriz);

    insereStringNaMatriz(stringUser, matriz, linhas, colunas);
    imprimeMatriz(linhas, colunas, matriz);

    while(true){
         leString(stringProcurada, tamanhoMatriz);
    procuraPalavra(matriz, stringProcurada, linhas, colunas);   
    }
   


}


