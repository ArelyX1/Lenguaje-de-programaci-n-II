#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 6;

// Función para calcular el valor máximo y mínimo de la matriz
void encontrar_valores(int matriz[][MAX], int n, int& maximo, int& minimo) {
    maximo = matriz[0][0];
    minimo = matriz[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] > maximo) {
                maximo = matriz[i][j];
            }
            if (matriz[i][j] < minimo) {
                minimo = matriz[i][j];
            }
        }
    }
}

int main() {
    int n;
    cout << "Ingrese el tamaño de la matriz (entre 2 y 6): ";
    cin >> n;

    if (n < 2 || n > 6) {
        cout << "El tamaño de la matriz debe estar entre 2 y 6." << endl;
        return 1;
    }

    int matriz[MAX][MAX];

    // Leer los elementos de la matriz
    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    // Calcular el valor máximo y mínimo de la matriz
    int maximo, minimo;
    encontrar_valores(matriz, n, maximo, minimo);

    // Mostrar el resultado
    cout << "El valor máximo de la matriz es: " << maximo << endl;
    cout << "El valor mínimo de la matriz es: " << minimo << endl;

    return 0;
}