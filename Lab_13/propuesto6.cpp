#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Ingrese el tamaño de la matriz (entre 2 y 6): ";
    cin >> n;

    if (n < 2 || n > 6) {
        cout << "El tamaño de la matriz debe estar entre 2 y 6." << endl;
        return 1;
    }

    int matriz[n][n];

    // Leer los elementos de la matriz
    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    // Verificar si la matriz es simétrica
    bool simetrica = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] != matriz[j][i]) {
                simetrica = false;
                break;
            }
        }
        if (!simetrica) {
            break;
        }
    }

    // Mostrar el resultado
    if (simetrica) {
        cout << "La matriz es simétrica." << endl;
    } else {
        cout << "La matriz no es simétrica." << endl;
    }

    return 0;
}