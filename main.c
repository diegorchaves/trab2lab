#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "busca.h"
#include "matriz.h"
#include "stringUser.h"

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

    completaStringUser (stringUser, tamanhoMatriz);

    insereStringNaMatriz (stringUser, matriz, linhas, colunas);

    imprimeMatriz (matriz, linhas, colunas);
    
    leStringUser (stringProcurada, tamanhoMatriz);

    puts (stringProcurada);

    minhaStrStr (matriz, stringProcurada, linhas, colunas);

    minhaStrStrReverse (matriz, stringProcurada, linhas, colunas);

    minhaStrStrVert (matriz, stringProcurada, linhas, colunas);

    minhaStrStrVertRev (matriz, stringProcurada, linhas, colunas);
    
    desalocaMatriz (linhas, matriz);
}