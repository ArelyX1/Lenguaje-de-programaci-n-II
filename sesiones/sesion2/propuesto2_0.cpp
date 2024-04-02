#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <cstring>
#include <string>
#include <limits>
#include <stdexcept>
#include <cctype>
using namespace std;

chrono::system_clock::time_point valida_fecha(int, int, int);
class Persona{
    protected:
        char nombre[20];
        char apellido[20];
        chrono::system_clock::time_point fecha_nacimiento;
    public:
        Persona(string, string, chrono::system_clock::time_point);
        void setNombre(char nombre_nuevo[20]){strncpy(nombre, nombre_nuevo, sizeof(nombre));}
        char* getNombre(){return nombre;}
        char* getApellido(){return apellido;}
        void getFechaNacimiento() const;
};
Persona::Persona(string __nombre, string __apellido, chrono::system_clock::time_point __fechaNacimiento){
    strncpy(nombre, __nombre.c_str(), sizeof(nombre));
    this -> nombre[sizeof(nombre) - 1] = '\0';
    strncpy(apellido, __apellido.c_str(), sizeof(apellido));
    this -> apellido[sizeof(apellido) - 1] = '\0';
    this -> fecha_nacimiento = __fechaNacimiento;
}

void Persona::getFechaNacimiento() const{
    time_t tiempo = chrono::system_clock::to_time_t(fecha_nacimiento);
    struct tm *timeinfo = localtime(&tiempo);
    cout << "Fecha de nacimiento: " << put_time(timeinfo, "%Y-%m-%d") << endl;
}

int main(){
    char nombre[20], apellido[20];
    int anio, mes, dia;
    cout << "Ingrese los datos" << endl;
    cout << "Ingrese el nombre: ";
    cin.getline(nombre, 20);
    cout << "Ingrese el apellido: ";
    cin.getline(apellido, 20);
    cout << "Ingrese la fecha de nacimiento (YYYY MM DD): ";
    cin >> anio >> mes >> dia;
    Persona* persona1 = new Persona(nombre, apellido, valida_fecha(anio, mes, dia));
    cout << "La persona es: " << endl;
    cout << persona1 -> getApellido() << endl;
    cout << persona1 -> getNombre() << endl;
    persona1 -> getFechaNacimiento();
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