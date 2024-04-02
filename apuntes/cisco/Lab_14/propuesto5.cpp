#include <iostream>
using namespace std;

int main() {
    int n, tam;
    cout << "Ingrese el número del cual desea obtener los múltiplos: ";
    cin >> n;
    while (n < 0) {
        cout << "Error! El número debe ser positivo. Ingrese el número del cual desea obtener los múltiplos: ";
        cin >> n;
    }
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> tam;
    while (tam < 0) {
        cout << "Error! El tamaño debe ser positivo. Ingrese el tamaño del arreglo: ";
        cin >> tam;
    }

    int arr[tam];
    int j = 0;
    int i = 1;
    while (j < tam) {
        if (i % n == 0) {
            arr[j] = i;
            j++;
        }
        i++;
    }

    cout << "Los múltiplos de " << n << " son: ";
    for (int i = 0; i < tam; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}