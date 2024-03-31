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

    // Calcular la matriz transpuesta
    int transpuesta[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            transpuesta[j][i] = matriz[i][j];
        }
    }

    // Mostrar la matriz transpuesta
    cout << "La matriz transpuesta es:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << transpuesta[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}