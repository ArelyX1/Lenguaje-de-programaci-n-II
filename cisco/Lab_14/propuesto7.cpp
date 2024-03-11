#include <iostream>
#include <string>
using namespace std;

int main() {
    string signos[] = {"Aries", "Tauro", "Géminis", "Cáncer", "Leo", "Virgo", "Libra", "Escorpio", "Sagitario", "Capricornio", "Acuario", "Piscis"};
    int periodo[][4] = {{3, 21, 4, 19}, {4, 20, 5, 20}, {5, 21, 6, 20}, {6, 21, 7, 22}, {7, 23, 8, 22}, {8, 23, 9, 22}, {9, 23, 10, 22}, {10, 23, 11, 21}, {11, 22, 12, 21}, {12, 22, 1, 19}, {1, 20, 2, 18}, {2, 19, 3, 20}};

    int dia, mes;
    string signo;
    int i, j;

    while (true) {
        cout << "Ingrese el día de nacimiento (0 para salir): ";
        cin >> dia;
        if (dia == 0) {
            break;
        }
        cout << "Ingrese el mes de nacimiento: ";
        cin >> mes;

        while (dia < 1 || dia > 31 || mes < 1 || mes > 12) {
            cout << "Fecha de nacimiento inválida. Ingrese el día de nacimiento (0 para salir): ";
            cin >> dia;
            if (dia == 0) {
                break;
            }
            cout << "Ingrese el mes de nacimiento: ";
            cin >> mes;
        }

        for (i = 0; i < 12; i++) {
            if ((mes == periodo[i][0] && dia >= periodo[i][1]) || (mes == periodo[i][2] && dia <= periodo[i][3])) {
                signo = signos[i];
                break;
            }
        }

        cout << "El signo zodiacal de la persona es: " << signo << endl;
    }

    return 0;
}