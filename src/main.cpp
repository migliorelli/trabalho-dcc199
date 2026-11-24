#include <iostream>
#include "floresta.h"

using namespace std;

int main() {
    char atual[MAX_LINHAS][MAX_COLUNAS];
    char prox[MAX_LINHAS][MAX_COLUNAS];

    if (!ler_arquivo("floresta.txt", atual)) {
        return 1;
    }
    
    while (true) {
        printar_floresta(atual);
        
        bool mudou = simular_floresta(atual, prox);
        if (!mudou) break;

        system("sleep 1");
        system("clear");
    }

    return 0;
}