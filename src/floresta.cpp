#include <iostream>
#include <fstream>

#define MAX_LINHAS  10
#define MAX_COLUNAS 10

using namespace std;

void copiar_floresta(
    char origem[MAX_LINHAS][MAX_COLUNAS], 
    char alvo[MAX_LINHAS][MAX_COLUNAS]
) {
    for (int lin = 0; lin < MAX_LINHAS; lin++) {    
        for (int col = 0; col < MAX_COLUNAS; col++) {
            alvo[lin][col] = origem[lin][col];
        }
    } 
}

bool verif_pos(char floresta[MAX_LINHAS][MAX_COLUNAS], int lin, int col) {
    return lin >= 0 && lin < MAX_LINHAS &&
           col >= 0 && col < MAX_COLUNAS &&
           floresta[lin][col] == 'T';
}

void apagar_fogo(char floresta[MAX_LINHAS][MAX_COLUNAS]) {
    for (int lin = 0; lin < MAX_LINHAS; lin++) {
        for (int col = 0; col < MAX_COLUNAS; col++) {
            if (floresta[lin][col] == 'F') {
                floresta[lin][col] = '.';
            }
        }
    }
}

bool simular_floresta(
    char atual[MAX_LINHAS][MAX_COLUNAS], 
    char prox[MAX_LINHAS][MAX_COLUNAS]
) {
    copiar_floresta(atual, prox);

    bool mudou = false;

    for (int lin = 0; lin < MAX_LINHAS; lin++) {    
        for (int col = 0; col < MAX_COLUNAS; col++) {
            // se não for fogo, ir pro proximo
            if (atual[lin][col] != 'F') continue;

            /*
            (i,  j) = item atual (o do meio)

            (i-1, j-1)  (i-1, j) (i-1, j+1)
            (i  , j-1)  (i,   j) (i  , j+1)
            (i+1, j-1)  (i+1, j) (i+1, j+1)

            os if's verificam cada posicao da tabela acima
            */

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 && j == 0) continue;

                    if (verif_pos(atual, lin + i, col + j)) {
                        prox[lin + i][col + j] = 'F';
                        mudou = true;
                    }
                }
            }

            prox[lin][col] = '.';
        }
    }

    copiar_floresta(prox, atual);
    
    return mudou;
}

void printar_floresta(char floresta[MAX_LINHAS][MAX_COLUNAS]) {
    for (int lin = 0; lin < MAX_LINHAS; lin++) {    
        for (int col = 0; col < MAX_COLUNAS; col++) {
            cout << floresta[lin][col] << " ";
        }
        cout << endl;
    }
}

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

    
    string linha;
    int num_linhas = 0;

    while (getline(arquivo, linha)) {

        if (num_linhas >= MAX_LINHAS) {
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