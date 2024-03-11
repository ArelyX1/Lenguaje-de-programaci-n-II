#include <iostream>
#include <string>
using namespace std;

const int MAX_PERSONAS = 3;

void ingresarDatos(string nombres[], string apellidos[], int edades[], int dnis[]) {
    for (int i = 0; i < MAX_PERSONAS; i++) {
        cout << "Ingrese el nombre de la persona " << i + 1 << ": ";
        cin >> nombres[i];
        cout << "Ingrese el apellido de la persona " << i + 1 << ": ";
        cin >> apellidos[i];
        cout << "Ingrese la edad de la persona " << i + 1 << ": ";
        cin >> edades[i];
        cout << "Ingrese el DNI de la persona " << i + 1 << ": ";
        cin >> dnis[i];
    }
}

void mostrarDatos(string nombres[], string apellidos[], int edades[], int dnis[]) {
    for (int i = 0; i < MAX_PERSONAS; i++) {
        cout << "Nombre: " << nombres[i] << endl;
        cout << "Apellido: " << apellidos[i] << endl;
        cout << "Edad: " << edades[i] << endl;
        cout << "DNI: " << dnis[i] << endl;
        cout << "-----------------" << endl;
    }
}

int encontrarPersona(string nombres[], int dnis[], int dni) {
    for (int i = 0; i < MAX_PERSONAS; i++) {
        if (dnis[i] == dni) {
            cout << "La persona ha sido encontrada:" << endl;
            cout << "Nombre: " << nombres[i] << endl;
            cout << "DNI: " << dnis[i] << endl;
            return i;
        }
    }
    cout << "La persona no ha sido encontrada." << endl;
    return -1;
}

void eliminarPersona(string nombres[], string apellidos[], int edades[], int dnis[], int& n, int dni) {
    int pos = encontrarPersona(nombres, dnis, dni);
    if (pos != -1) {
        for (int i = pos; i < n - 1; i++) {
            nombres[i] = nombres[i + 1];
            apellidos[i] = apellidos[i + 1];
            edades[i] = edades[i + 1];
            dnis[i] = dnis[i + 1];
        }
        n--;
        cout << "La persona con DNI " << dni << " ha sido eliminada." << endl;
    } else {
        cout << "No se ha encontrado ninguna persona con DNI " << dni << "." << endl;
    }
}

int main() {
    int opcion;
    int n = 0;
    string nombres[MAX_PERSONAS];
    string apellidos[MAX_PERSONAS];
    int edades[MAX_PERSONAS];
    int dnis[MAX_PERSONAS];

    do {
        cout << "Seleccione una opción:" << endl;
        cout << "1. Ingresar datos" << endl;
        cout << "2. Mostrar datos" << endl;
        cout << "3. Encontrar persona" << endl;
        cout << "4. Eliminar persona" << endl;
        cout << "5. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                if (n < MAX_PERSONAS) {
                    ingresarDatos(nombres, apellidos, edades, dnis);
                    n++;
                } else {
                    cout << "No se pueden ingresar más personas." << endl;
                }
                break;
            case 2:
                mostrarDatos(nombres, apellidos, edades, dnis);
                break;
            case 3:
                int dni;
                cout << "Ingrese el DNI de la persona que desea encontrar: ";
                cin >> dni;
                encontrarPersona(nombres, dnis, dni);
                break;
            case 4:
                cout << "Ingrese el DNI de la persona que desea eliminar: ";
                cin >> dni;
                eliminarPersona(nombres, apellidos, edades, dnis, n, dni);
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
        }
    } while (opcion != 5);

    return 0;
}