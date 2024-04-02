#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Inicializar la semilla para generar números aleatorios
    srand(time(NULL));

    int filas, columnas;
    cout << "Ingrese el número de filas: ";
    cin >> filas;
    cout << "Ingrese el número de columnas: ";
    cin >> columnas;

    int matriz[filas][columnas];

    // Llenar la matriz con números aleatorios
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = rand() % 100; // Genera un número aleatorio entre 0 y 99
        }
    }

    // Mostrar la matriz llena
    cout << "La matriz llena es: " << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}