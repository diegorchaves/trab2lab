#include <stdlib.h>
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

    leStringMatriz (stringUser, tamanhoMatriz);

    retiraEspacos (stringUser, tamanhoMatriz);

    completaStringMatriz (stringUser, tamanhoMatriz);

    insereStringNaMatriz (stringUser, matriz, linhas, colunas);

    imprimeMatriz (matriz, linhas, colunas);
    
    while (1)
    {
        leStringProcurada (stringProcurada, tamanhoMatriz);
        buscaPalavra (matriz, stringProcurada, linhas, colunas);
    }
    
    desalocaMatriz (linhas, matriz);
    free (stringUser);
    free (stringProcurada);
}