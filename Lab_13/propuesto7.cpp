#include <iostream>
#include <vector>
using namespace std;

// Función para imprimir los elementos impares del vector
void imprimirImpares(const vector<int>& vec) {
    cout << "Elementos impares del vector: ";
    for (int num : vec) {
        if (num % 2 != 0) {
            cout << num << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Ingrese el tamaño del vector: ";
    cin >> n;

    vector<int> numeros(n);
    cout << "Ingrese los elementos del vector:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }

    // Llamar a la función para imprimir los elementos impares
    imprimirImpares(numeros);

    return 0;
}