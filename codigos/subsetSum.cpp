#include <iostream>
#include <vector>

using namespace std;

bool subsetSum(const vector<int>& numeros, int indiceAtual, int somaRestante) {
    if (somaRestante == 0) {
        return true;
    }

    if (somaRestante < 0 || indiceAtual == numeros.size()) {
        return false;
    }

    int numeroAtual = numeros[indiceAtual];
    bool incluindo = subsetSum(numeros, indiceAtual + 1, somaRestante - numeroAtual);
    bool excluindo = subsetSum(numeros, indiceAtual + 1, somaRestante);
    return incluindo || excluindo;
}

int main() {
    vector<int> numeros = {2, 3, 5, 8};
    int somaDesejada = 7;

    if (subsetSum(numeros, 0, somaDesejada)) {
        cout << "Existe um subconjunto válido!\n";
    } else {
        cout << "Não existe um subconjunto válido!\n";
    }

    return 0;
}
