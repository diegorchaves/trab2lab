#include <stdbool.h>

bool buscaHorizontalDireta (char **matriz, char *stringProcurada, int linhas, int colunas);

bool buscaHorizontarInversa (char **matriz, char *stringProcurada, int linhas, int colunas);

bool buscaVerticalDireta (char **matriz, char *stringProcurada, int linhas, int colunas);

bool buscaVerticalInversa (char **matriz, char *stringProcurada, int linhas, int colunas);

bool buscaDiagonalPrincipalDireta (char **matriz, char *stringProcurada, int linhas, int colunas);

bool buscaDiagonalPrincipalInversa (char **matriz, char *stringProcurada, int linhas, int colunas);

bool buscaDiagonalSecundariaDireta (char **matriz, char *stringProcurada, int linhas, int colunas);

bool buscaDiagonalSecundariaInversa (char **matriz, char *stringProcurada, int linhas, int colunas);

void buscaPalavra (char **matriz, char *palavra, int linhas, int colunas);