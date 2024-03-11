#include <iostream>
using namespace std;

const int MAX = 6;
void leerMatriz(int matriz[][MAX], int n) {
    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }
}
void mostrarMatriz(int matriz[][MAX], int n) {
    cout << "La matriz es:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}
void productoMatrices(int matriz1[][MAX], int matriz2[][MAX], int matrizResultado[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrizResultado[i][j] = 0;
            for (int k = 0; k < n; k++) {
                matrizResultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

int main() {
    int n;
    cout << "Ingrese el tamaño de las matrices (entre 2 y 6): ";
    cin >> n;
    if (n < 2 || n > 6) {
        cout << "El tamaño de las matrices debe estar entre 2 y 6." << endl;
        return 1;
    }
    int matriz1[MAX][MAX], matriz2[MAX][MAX], matrizResultado[MAX][MAX];
    cout << "Ingrese los elementos de la primera matriz:" << endl;
    leerMatriz(matriz1, n);
    cout << "Ingrese los elementos de la segunda matriz:" << endl;
    leerMatriz(matriz2, n);
    productoMatrices(matriz1, matriz2, matrizResultado, n);
    mostrarMatriz(matrizResultado, n);

    return 0;
}