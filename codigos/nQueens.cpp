#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

void posicionarRainhas(vector<int>& posicoesRainhas, int linhaAtual, int tamanhoTabuleiro){
    if(linhaAtual == tamanhoTabuleiro + 1){
        for(int linha = 1; linha <= tamanhoTabuleiro + 1; linha++){
            cout << posicoesRainhas[linha] << " "; 
        }
        cout << endl; 
        return; 
    }

    for(int colunaAtual = 1; colunaAtual <= tamanhoTabuleiro; colunaAtual++){
        bool posicaoValida = true; 

        for(int linhaAnterior = 1; linhaAnterior < linhaAtual; linhaAnterior++){
            if(posicoesRainhas[linhaAnterior] == colunaAtual || abs(posicoesRainhas[linhaAnterior] - colunaAtual) == linhaAtual - linhaAnterior){
                posicaoValida = false;
                break; 
            }
        }

        if(posicaoValida){
            posicoesRainhas[linhaAtual] = colunaAtual;
            posicionarRainhas(posicoesRainhas, linhaAtual + 1, tamanhoTabuleiro);
        }
    }
}

int main(){
    int tamanhoTabuleiro = 4;
    vector<int> posicoesRainhas(tamanhoTabuleiro + 1, 0);

    posicionarRainhas(posicoesRainhas, 1, tamanhoTabuleiro); 

    return 0; 
}