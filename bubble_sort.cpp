#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> valores;
    int valor_entrada;
    int valor_temporario;

    cout << "Digite os valores (para parar digite qualquer letra ou caractere):  ";

    while(cin >> valor_entrada){
        valores.push_back(valor_entrada);
    }


    for(int i = valores.size() - 1; i > 0; i--){
        bool mudanca = false;

        for(int j = 0; j < i; j++){
            if(valores[j] > valores[j + 1]){
                valor_temporario = valores[j];
                valores[j] = valores[j + 1];
                valores[j + 1] = valor_temporario;
                mudanca = true;
            }
        }

        if(!mudanca){
            break;
        } 

    }

    cout << "--- Valores inseridos ---" << endl;
    for (int i = 0; i < valores.size(); i++) {
        cout << "Valor " << i + 1 << ": " << valores[i] << endl;
    }

    return 0;
}