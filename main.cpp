#include <iostream>
#include <fstream>

#define MAX_LINHAS  10
#define MAX_COLUNAS 10

using namespace std;

void preenche_linha(char vetor[], char caractere) {
    for (int i = 0; i < MAX_COLUNAS; i++) {
        vetor[i] = caractere;
    }
}

bool ler_arquivo(string nome_arquivo, char matriz[MAX_LINHAS][MAX_COLUNAS]) {
    ifstream arquivo(nome_arquivo);

    if (!arquivo.is_open()) {
        cout << "Não foi possível abrir o arquivo \"" << nome_arquivo << "\"." << endl;
        return false;
    }

    cout<<nome_arquivo;

    int num_linhas, num_colunas;
    arquivo >> num_linhas >> num_colunas;

    if (num_linhas > MAX_LINHAS) {
        cout << "Máximo de linhas excedido. Máximo: " << MAX_LINHAS << "; Arquivo: " << num_linhas << endl;
        return false;
    }

    if (num_linhas > MAX_COLUNAS) {
        cout << "Máximo de colunas excedido. Máximo: " << MAX_COLUNAS << "; Arquivo: " << num_colunas << endl;
        return false;
    }

    string linha;
    int linha_atual = 0;

    while (getline(arquivo, linha)) {
        linha_atual++;
        
        int i;
        for (i = 0; linha[i] != '\0'; i++) {
            matriz[linha_atual][i] = linha[i];
            cout << linha[i];
        }

        if (i < MAX_COLUNAS) {
            for (int j = i + 1; j <= MAX_COLUNAS; j++) {
                matriz[linha_atual][j] = '.';
            }
        }
    }

    if (linha_atual < MAX_LINHAS) {
        for (int i = linha_atual + 1; i <= MAX_LINHAS; i++) {
            preenche_linha(matriz[linha_atual], '.');
        }
    }

    return true;
}

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
