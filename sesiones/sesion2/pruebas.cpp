#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip> // Para manipulación de formato de entrada

using namespace std;

chrono::system_clock::time_point valida_fecha(int, int, int);

class Persona {
private:
    string nombre;
    chrono::system_clock::time_point fecha_nacimiento;

public:
    Persona(string nombre, int anio, int mes, int dia);
    void imprimirInformacion() const;
};

Persona::Persona(string nombre, int anio, int mes, int dia)
    : nombre(nombre), fecha_nacimiento(valida_fecha(anio, mes, dia)) {}

void Persona::imprimirInformacion() const {
    time_t tiempo = chrono::system_clock::to_time_t(fecha_nacimiento);
    struct tm *timeinfo = localtime(&tiempo);
    cout << "Nombre: " << nombre << endl;
    cout << "Fecha de nacimiento: " << put_time(timeinfo, "%Y-%m-%d") << endl; // Formatear la fecha sin la hora
}

chrono::system_clock::time_point valida_fecha(int anio, int mes, int dia) {
    tm tiempoinfo = {};
    tiempoinfo.tm_year = anio - 1900;
    tiempoinfo.tm_mon = mes - 1;
    tiempoinfo.tm_mday = dia;

    time_t tiempo = mktime(&tiempoinfo);
    if (tiempo == -1) throw invalid_argument("Fecha inválida");
    return chrono::system_clock::from_time_t(tiempo);
}

int main() {
    string nombre;
    int anio, mes, dia;
    cout << "Ingrese el nombre de la persona: ";
    cin >> nombre;
    cout << "Ingrese la fecha de nacimiento (YYYY MM DD): ";
    cin >> anio >> mes >> dia;

    try {
        Persona persona(nombre, anio, mes, dia);
        persona.imprimirInformacion();
    } catch (const invalid_argument& e) {
        cerr << "ERROR " << e.what() << endl;
    }

    return 0;
}
