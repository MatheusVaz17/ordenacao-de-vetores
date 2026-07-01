#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;
int main(){
    const int tamanho = 30000;
    vector<double> valores(tamanho);
    double valor_temporario;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1.0, 100000.0);

    for (int i = 0; i < tamanho; i++) {
        valores[i] = dis(gen);
    }

    auto start = high_resolution_clock::now();

    for(int i = (valores.size() - 1); i > 0; i--){
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

    auto stop = high_resolution_clock::now();
    auto durationBubble = duration_cast<milliseconds>(stop - start);
    cout << ">> Tempo do Bubble Sort: " << (durationBubble.count() / 1000.0) << " s" << endl;

    // cout << "--- Valores ordenados ---" << endl;
    // for (int i = 0; i < valores.size(); i++) {
    //     cout << "Valor " << i + 1 << ": " << valores[i] << endl;
    // }

    return 0;
}