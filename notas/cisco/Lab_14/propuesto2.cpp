#include <iostream>
using namespace std;

int main() {
    int r1, c1, r2, c2;

    cout << "Ingrese el número de filas y columnas de la primera matriz: ";
    while (!(cin >> r1 >> c1)) {
        cout << "Error! Ingrese valores enteros." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Ingrese el número de filas y columnas de la segunda matriz: ";
    while (!(cin >> r2 >> c2)) {
        cout << "Error! Ingrese valores enteros." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }

    if (c1 != r2) {
        cout << "Error! El número de columnas de la primera matriz no es igual al número de filas de la segunda matriz." << endl;
    } else {
        int mat1[r1][c1], mat2[r2][c2], result[r1][c2];

        cout << "Ingrese los elementos de la primera matriz:" << endl;
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                while (!(cin >> mat1[i][j])) {
                    cout << "Error! Ingrese un valor entero." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }

        cout << "Ingrese los elementos de la segunda matriz:" << endl;
        for (int i = 0; i < r2; i++) {
            for (int j = 0; j < c2; j++) {
                while (!(cin >> mat2[i][j])) {
                    cout << "Error! Ingrese un valor entero." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }

        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                result[i][j] = 0;
                for (int k = 0; k < c1; k++) {
                    result[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }

        cout << "El producto de las dos matrices es:" << endl;
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}