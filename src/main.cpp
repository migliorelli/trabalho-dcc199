#include <iostream>
#include "floresta.h"

using namespace std;

int main() {
    char atual[MAX_LINHAS][MAX_COLUNAS];
    char prox[MAX_LINHAS][MAX_COLUNAS];

    if (!ler_arquivo("floresta.txt", atual)) {
        return 1;
    }

    int turnos = 0;
    while (true) {
        cout << "Jogo da floresta." << endl << endl;
        printar_floresta(atual);
        
        bool mudou = simular_floresta(atual, prox);
        turnos++;

        if (!mudou) break;        

        system("sleep 1");
        system("clear");
    }
    
    apagar_fogo(atual);
    
    system("clear");
    printar_floresta(atual);

    cout << endl << "O jogo acabou em " << turnos << " turnos.";

    return 0;
}