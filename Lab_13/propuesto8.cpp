#include <iostream>
#include <vector>
using namespace std;

// Función para verificar si el vector está ordenado de forma creciente
bool estaOrdenado(const vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); i++) {
        if (vec[i] < vec[i - 1]) {
            return false;
        }
    }
    return true;
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

    // Llamar a la función para verificar si el vector está ordenado
    if (estaOrdenado(numeros)) {
        cout << "El vector está ordenado de forma creciente." << endl;
    } else {
        cout << "El vector no está ordenado de forma creciente." << endl;
    }

    return 0;
}