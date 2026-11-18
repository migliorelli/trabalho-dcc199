#include <iostream>
#include "floresta.h"

using namespace std;

int main() {
    char matriz[MAX_LINHAS][MAX_COLUNAS];

    if (!ler_arquivo("floresta.txt", matriz)) {
        return 1;
    }

    for (int linha = 0; linha < MAX_LINHAS; linha++) {
        cout << endl;

        for (int coluna = 0; coluna < MAX_COLUNAS; coluna++) {
            cout << matriz[linha][coluna] << " ";
        }
    }

    return 0;
}