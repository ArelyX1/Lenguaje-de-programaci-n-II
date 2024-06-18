#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Estudiante {
private:
    string nombre;
    int edad;
    vector<float> notas;
    float promedio;

public:
    Estudiante(string nom, int ed, vector<float> n) {
        nombre = nom;
        edad = ed;
        notas = n;
        calcularPromedio();
    }

    void calcularPromedio() {
        float suma = 0;
        for (float nota : notas) {
            suma += nota;
        }
        promedio = suma / notas.size();
    }

    float getPromedio() {
        return promedio;
    }

    string getNombre() {
        return nombre;
    }

    int getEdad() {
        return edad;
    }

    vector<float> getNotas() {
        return notas;
    }
};

bool compararPromedio(Estudiante& e1, Estudiante& e2) {
    return e1.getPromedio() < e2.getPromedio();
}

int main() {
    vector<Estudiante> estudiantes;

    estudiantes.push_back(Estudiante("Juan", 20, {85, 90, 80, 92}));
    estudiantes.push_back(Estudiante("María", 19, {75, 82, 88, 90}));
    estudiantes.push_back(Estudiante("Pedro", 21, {92, 88, 85, 90}));
    estudiantes.push_back(Estudiante("Ana", 18, {80, 75, 85, 82}));

    cout << "Estudiantes ordenados por promedio:" << endl;
    sort(estudiantes.begin(), estudiantes.end(), compararPromedio);

    for (Estudiante e : estudiantes) {
        cout << e.getNombre() << " - Promedio: " << fixed << setprecision(2) << e.getPromedio() << endl;
    }

    float notaMinima = 85;
    cout << "\nEstudiantes con promedio mayor a " << notaMinima << ":" << endl;

    for (Estudiante e : estudiantes) {
        if (e.getPromedio() > notaMinima) {
            cout << e.getNombre() << " - Promedio: " << fixed << setprecision(2) << e.getPromedio() << endl;
        }
    }
}