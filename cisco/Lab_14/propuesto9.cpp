#include <iostream>
#include <string>
using namespace std;

struct Persona {
    string nombre;
    string apellido;
    int edad;
    int dni;
};

void ingresarDatos(Persona personas[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el nombre de la persona " << i + 1 << ": ";
        cin >> personas[i].nombre;
        cout << "Ingrese el apellido de la persona " << i + 1 << ": ";
        cin >> personas[i].apellido;
        cout << "Ingrese la edad de la persona " << i + 1 << ": ";
        cin >> personas[i].edad;
        cout << "Ingrese el DNI de la persona " << i + 1 << ": ";
        cin >> personas[i].dni;
    }
}

void mostrarDatos(Persona personas[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nombre: " << personas[i].nombre << endl;
        cout << "Apellido: " << personas[i].apellido << endl;
        cout << "Edad: " << personas[i].edad << endl;
        cout << "DNI: " << personas[i].dni << endl;
        cout << "-----------------" << endl;
    }
}

int encontrarPersona(Persona personas[], int n, int dni) {
    for (int i = 0; i < n; i++) {
        if (personas[i].dni == dni) {
            return i;
        }
    }
    return -1;
}

void eliminarPersona(Persona personas[], int& n, int dni) {
    int pos = encontrarPersona(personas, n, dni);
    if (pos != -1) {
        for (int i = pos; i < n - 1; i++) {
            personas[i] = personas[i + 1];
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
    Persona personas[100];

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
                ingresarDatos(personas, n);
                n++;
                break;
            case 2:
                mostrarDatos(personas, n);
                break;
            case 3:
                int dni;
                cout << "Ingrese el DNI de la persona que desea encontrar: ";
                cin >> dni;
                int pos = encontrarPersona(personas, n, dni);
                if (pos != -1) {
                    cout << "La persona ha sido encontrada en la posición " << pos << "." << endl;
                } else {
                    cout << "La persona no ha sido encontrada." << endl;
                }
                break;
            case 4:
                cout << "Ingrese el DNI de la persona que desea eliminar: ";
                cin >> dni;
                eliminarPersona(personas, n, dni);
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