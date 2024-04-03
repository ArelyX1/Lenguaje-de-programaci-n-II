#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
using namespace std;

chrono::system_clock::time_point valida_fecha(int, int, int, int, int, int);

class Tarea {
protected:
    string descripcion;
    chrono::system_clock::time_point fecha_limite;

public:
    Tarea(string desc, chrono::system_clock::time_point fecha) : descripcion(desc), fecha_limite(fecha) {}

    void mostrarInformacion() {
        cout << "Descripción: " << descripcion << endl;
        time_t tiempo = chrono::system_clock::to_time_t(fecha_limite);
        cout << "Fecha límite: " << ctime(&tiempo);
    }
};

int main() {
    int anio, mes, dia, hora, min, seg;
    string desc;

    cout << "Ingrese la descripción de la tarea: ";
    cin.ignore();
    getline(cin, desc);

    cout << "Ingrese la fecha límite (YYYY MM DD HH MM SS): ";
    cin >> anio >> mes >> dia >> hora >> min >> seg;

    try {
        chrono::system_clock::time_point datoTiempo = valida_fecha(anio, mes, dia, hora, min, seg);
        Tarea nuevaTarea(desc, datoTiempo);
        nuevaTarea.mostrarInformacion();
    } catch (const invalid_argument& e) {
        cerr << "ERROR: " << e.what() << endl;
    }
}

chrono::system_clock::time_point valida_fecha(int anio, int mes, int dia, int hora, int min, int seg) {
    tm tiempoinfo = {};
    tiempoinfo.tm_year = anio - 1900;
    tiempoinfo.tm_mon = mes - 1;
    tiempoinfo.tm_mday = dia;
    tiempoinfo.tm_hour = hora;
    tiempoinfo.tm_min = min;
    tiempoinfo.tm_sec = seg;

    time_t tiempo = mktime(&tiempoinfo);
    if (tiempo == -1) throw invalid_argument("Fecha y tiempo inválidas");
    return chrono::system_clock::from_time_t(tiempo);
}
