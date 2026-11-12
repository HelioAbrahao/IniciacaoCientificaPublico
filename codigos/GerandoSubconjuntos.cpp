#include<iostream>
#include<vector>
using namespace std;

int quantidade; // Variável global
vector<int> valores; 
vector<int> subconjunto_atual; 

void gerar_subconjuntos(int indice){
    if(indice == quantidade){
        cout << "{ ";
        for(int x : subconjunto_atual){
            cout << x << " "; 
        }
        cout << "}" << endl;
        return; 
    }

    gerar_subconjuntos(indice + 1);

    subconjunto_atual.push_back(valores[indice]);
    gerar_subconjuntos(indice + 1); 
    subconjunto_atual.pop_back(); 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    
    cin >> quantidade;
    valores.resize(quantidade); 

    for(int i = 0; i < quantidade; i++){
        cin >> valores[i];
    }
        
    gerar_subconjuntos(0);
    return 0;
}