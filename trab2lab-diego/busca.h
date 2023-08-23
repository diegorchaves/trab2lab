#include <stdbool.h>

void buscaHorizontalDireta (char **matriz, char *stringProcurada, int linhas, int colunas, bool *encontrou);

void buscaHorizontarInversa (char **matriz, char *stringProcurada, int linhas, int colunas, bool *encontrou);

void buscaVerticalDireta (char **matriz, char *stringProcurada, int linhas, int colunas, bool *encontrou);

void buscaVerticalInversa (char **matriz, char *stringProcurada, int linhas, int colunas, bool *encontrou);

void buscaDiagonalPrincipalDireta (char **matriz, char *stringProcurada, int linhas, int colunas, bool *encontrou);

void buscaDiagonalPrincipalInversa (char **matriz, char *stringProcurada, int linhas, int colunas, bool *encontrou);

void buscaDiagonalSecundariaDireta (char **matriz, char *stringProcurada, int linhas, int colunas, bool *encontrou);

void buscaDiagonalSecundariaInversa (char **matriz, char *stringProcurada, int linhas, int colunas, bool *encontrou);

void buscaPalavra (char **matriz, char *palavra, int linhas, int colunas);