#include<iostream>
#include<vector>
using namespace std; 

int tamanho;
vector<bool> escolhido;
vector<int> permutacao; 

// Quando um vector é criado sem especificar seu tamanho, ele começa com tamanho 0. 

void gerando_permutacoes(){
    if(permutacao.size() == tamanho){
        cout << "(";
        for(int x : permutacao){ // range-based for loop
            cout << x << " "; 
        }
        cout << ")" << endl; 

        return;
    } else {
        for(int i = 0; i < tamanho; i++){
            if(escolhido[i]) continue; // Continue interrompe a iteração atual e passa para a próxima iteração do laço em que está inserido. 
            escolhido[i] = true; 
            permutacao.push_back(i); 
            
            // CADA CHAMADA RECURSIVA POSSUI SUAS PRÓPRIAS VARIÁVEIS LOCAIS.
            
            gerando_permutacoes(); 
            escolhido[i] = false; 
            permutacao.pop_back(); 

            // Provavelmente, quando você estiver revisitando esse código você de primeira não vai entender nada. Quando estiver tentando entender pense no seguinte, após o descongelamente do estado da recursão o escolhido[i] = false e o permutacao.pop_back() só servem pra fazer ela voltar ao seu estado de antes de ir para aquela ramificação da árvore de recursão. Nada mais que isso. Não é difícil, YOU CAN DO IT! 
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tamanho;

    escolhido.resize(tamanho, false);

    gerando_permutacoes();

    return 0; 
}