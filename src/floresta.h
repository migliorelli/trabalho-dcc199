#ifndef FLORESTA_H
#define FLORESTA_H

#include <string>

#define MAX_LINHAS  10
#define MAX_COLUNAS 10

void apagar_fogo(char floresta[MAX_LINHAS][MAX_COLUNAS]);

bool simular_floresta(char atual[MAX_LINHAS][MAX_COLUNAS], char prox[MAX_LINHAS][MAX_COLUNAS]);

void printar_floresta(char floresta[MAX_LINHAS][MAX_COLUNAS]);

void preenche_linha(char vetor[], char caractere);

bool ler_arquivo(std::string nome_arquivo, char matriz[MAX_LINHAS][MAX_COLUNAS]);

#endif