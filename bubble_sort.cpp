#include <iostream>

using namespace std;

int main(){
    double valores[6] = {5.6, 7.2, 1.7, 3.5, 9.1, 0.3};
    double valor_temporario;

    cout << "--- Notas sem ordenação: ---" << endl;
    for(int i = 0; i < 5; i++){
        cout << "Valor " << i + 1 << ": " << valores[i] << endl;
    }

    for(int i = 5; i > 0; i--){
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

    cout << "--- Valores ordenados ---" << endl;
    for (int i = 0; i < 6; i++) {
        cout << "Valor " << i + 1 << ": " << valores[i] << endl;
    }

    return 0;
}