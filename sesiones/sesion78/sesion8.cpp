#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <chrono>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class Libro;
template <typename T1, typename T2>
class Mapa;
class Usuario;
template <typename T1, typename T2>
class Mapa {
    public:
        map<T1, T2> mapa;
        void insertar(T1 clave, T2 valor);
        void mostrar();
};
class Libro{
    public:
        char autor[20], isbn[13];
        string titulo, genero;
        bool disponible;
        int anio;
};

class Usuario{
    public:
        char nombre[20], id[10];
        int edad;
        string tipo_usr;
        Libro *libro;
};

void buscar_elemento(const map<string, int>& myMap, const string& key);
string get_fecha();
chrono::system_clock::time_point valida_fecha(int anio, int mes, int dia);
string format_date(const chrono::system_clock::time_point& date);
bool comparar_fechas(chrono::system_clock::time_point fecha);


int main(){
    cout << "Fecha: " << get_fecha() << endl;
    try {
        chrono::system_clock::time_point validDate = valida_fecha(2024, 6, 29);
        cout << "Fecha válida: " << format_date(validDate) << endl;

    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }
    cout << comparar_fechas(valida_fecha(2024, 5, 29));
}


void buscar_elemento(const map<string, int>& myMap, const string& key) {
    map<string, int>::const_iterator it = myMap.find(key);
    if (it != myMap.end()) {
        cout << "Llave encontrada: " << it->first << " -> " << it->second << endl;
    } else {
        cout << "Llave no encontrada" << endl;
    }
}

string get_fecha() {
    time_t currentTime;
    struct tm* localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y", localTime);
    return string(buffer);
}

chrono::system_clock::time_point valida_fecha(int anio, int mes, int dia){
    tm tiempoinfo = {};
    tiempoinfo.tm_year = anio - 1900;
    tiempoinfo.tm_mon = mes - 1;
    tiempoinfo.tm_mday = dia;

    time_t tiempo = mktime(&tiempoinfo);
    if (tiempo == -1) throw invalid_argument("Fecha inválida");
    return chrono::system_clock::from_time_t(tiempo);
}

string format_date(const chrono::system_clock::time_point& date) {
    time_t time = chrono::system_clock::to_time_t(date);
    tm* timeinfo = localtime(&time);
    stringstream ss;
    ss << put_time(timeinfo, "%d/%m/%Y");
    return ss.str();
}

bool comparar_fechas(chrono::system_clock::time_point fecha){
    string fecha_actual = get_fecha(), fecha_plazo = format_date(fecha);
    if (fecha_actual <= fecha_plazo) {
        return false;
    } else {
        return true;
    }
}
