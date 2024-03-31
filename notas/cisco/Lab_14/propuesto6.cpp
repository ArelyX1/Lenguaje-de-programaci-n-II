#include <iostream>
using namespace std;

void ingresarMatriz(int matriz[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Ingrese el elemento en la posición [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
}

void mostrarMayor(int matriz[][10], int n) {
    int mayor = matriz[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] > mayor) {
                mayor = matriz[i][j];
            }
        }
    }
    cout << "El elemento mayor es: " << mayor << endl;
}

void mostrarMenor(int matriz[][10], int n) {
    int menor = matriz[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
            }
        }
    }
    cout << "El elemento menor es: " << menor << endl;
}

void mostrarSumaFila(int matriz[][10], int n) {
    int fila;
    cout << "Ingrese el número de la fila de la cual desea calcular la suma (0 a " << n - 1 << "): ";
    cin >> fila;
    int sumaFila = 0;
    for (int j = 0; j < n; j++) {
        sumaFila += matriz[fila][j];
    }
    cout << "La suma de la fila " << fila << " es: " << sumaFila << endl;
}

void mostrarDiagonalPrincipal(int matriz[][10], int n) {
    cout << "Los elementos de la diagonal principal son: ";
    for (int i = 0; i < n; i++) {
        cout << matriz[i][i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Ingrese el tamaño de la matriz: ";
    cin >> n;
    while (n <= 0 || n > 10) {
        cout << "Error! El tamaño debe estar entre 1 y 10. Ingrese el tamaño de la matriz: ";
        cin >> n;
    }

    int matriz[10][10];

    int opcion;
    do {
        cout << "Seleccione una opción:" << endl;
        cout << "1. Ingresar elementos a la matriz" << endl;
        cout << "2. Mostrar el elemento mayor" << endl;
        cout << "3. Mostrar el elemento menor" << endl;
        cout << "4. Calcular y mostrar la suma de una fila" << endl;
        cout << "5. Mostrar los elementos de la diagonal principal" << endl;
        cout << "6. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                ingresarMatriz(matriz, n);
                break;
            case 2:
                mostrarMayor(matriz, n);
                break;
            case 3:
                mostrarMenor(matriz, n);
                break;
            case 4:
                mostrarSumaFila(matriz, n);
                break;
            case 5:
                mostrarDiagonalPrincipal(matriz, n);
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
        }
    } while (opcion != 6);

    return 0;
}