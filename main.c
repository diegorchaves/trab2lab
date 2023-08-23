
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

    retiraEspacos (stringUser, tamanhoMatriz);

    completaStringUser (stringUser, tamanhoMatriz);

    insereStringNaMatriz (stringUser, matriz, linhas, colunas);

    imprimeMatriz (matriz, linhas, colunas);
    
    while (1)
    {
        leStringUser (stringProcurada, tamanhoMatriz);
        buscaPalavra (matriz, stringProcurada, linhas, colunas);
    }
}