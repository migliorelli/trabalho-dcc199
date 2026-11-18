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
        cout << "Não foi possível abrir o arquivo \"" 
             << nome_arquivo << "\"." << endl;
        return false;
    }

    
    arquivo.ignore();
    
    string linha;
    int num_linhas = 0;

    while (getline(arquivo, linha)) {

        if (num_linhas > MAX_LINHAS) {
            cout << "Máximo de linhas excedido. Máximo: "
                << MAX_LINHAS << "; Arquivo: "
                << num_linhas << endl;
            return false;
        }

        if ((int)linha.size() > MAX_COLUNAS) {
            cout << "Máximo de colunas excedido. Máximo: "
                << MAX_COLUNAS << "; Arquivo: "
                << linha.size() << endl;
            return false;
        }

        int i;

        for (i = 0; i < (int)linha.size(); i++) {
            matriz[num_linhas][i] = linha[i];
        }

        for (; i < MAX_COLUNAS; i++) {
            matriz[num_linhas][i] = '.';
        }

        num_linhas++;
    }

    for (int i = num_linhas; i < MAX_LINHAS; i++) {
        preenche_linha(matriz[i], '.');
    }

    return true;
}