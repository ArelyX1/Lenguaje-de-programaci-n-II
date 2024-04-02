#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    int notas[n];
    int deficientes = 0, regulares = 0, buenos = 0, excelentes = 0;

    for (int i = 0; i < n; i++) {
        do {
            cout << "Ingrese la nota del estudiante " << i + 1 << " (entre 0 y 20): ";
            cin >> notas[i];
        } while (notas[i] < 0 || notas[i] > 20);

        if (notas[i] >= 0 && notas[i] <= 5) {
            deficientes++;
        } else if (notas[i] >= 6 && notas[i] <= 10) {
            regulares++;
        } else if (notas[i] >= 11 && notas[i] <= 15) {
            buenos++;
        } else {
            excelentes++;
        }
    }

    cout << "Estudiantes deficientes: " << deficientes << endl;
    cout << "Estudiantes regulares: " << regulares << endl;
    cout << "Estudiantes buenos: " << buenos << endl;
    cout << "Estudiantes excelentes: " << excelentes << endl;

    return 0;
}