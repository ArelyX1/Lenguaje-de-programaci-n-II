#include <iostream>
using namespace std;

void ingresarMatriz(int matriz[4][4]) {
    cout << "Ingrese los valores de la matriz:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << "Ingrese el valor de la posición [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
}

void sumarMatrices(int matrizA[4][4], int matrizB[4][4], int matrizC[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
}

void mostrarMatriz(int matriz[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int opcion;
    int matrizA[4][4], matrizB[4][4], matrizC[4][4];

    do {
        cout << "Seleccione una opción:" << endl;
        cout << "1. Ingresar las matrices" << endl;
        cout << "2. Sumar las matrices" << endl;
        cout << "3. Mostrar la matriz resultante" << endl;
        cout << "4. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                ingresarMatriz(matrizA);
                ingresarMatriz(matrizB);
                break;
            case 2:
                sumarMatrices(matrizA, matrizB, matrizC);
                break;
            case 3:
                mostrarMatriz(matrizC);
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
        }
    } while (opcion != 4);

    return 0;
}