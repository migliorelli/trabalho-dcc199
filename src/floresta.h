#ifndef FLORESTA_H
#define FLORESTA_H

#include <string>

#define MAX_LINHAS  10
#define MAX_COLUNAS 10

void preenche_linha(char vetor[], char caractere);

bool ler_arquivo(std::string nome_arquivo, char matriz[MAX_LINHAS][MAX_COLUNAS]);

#endif