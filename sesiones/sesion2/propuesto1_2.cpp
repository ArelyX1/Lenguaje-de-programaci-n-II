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

//============================================ CLASE ESTUDIANTE HEREDADO DE PERSONA
class Estudiante : public Persona{
    protected:
        const int codigo;
        char carrera[50];
        int semestre;
    public:
    Estudiante(int, string, int);
    int getCodigo() const{return codigo;}
    void setCarrera(char carrera_nueva[50]){strncpy(carrera, carrera_nueva, sizeof(carrera));}
    char* getCarrera(){return carrera;}
    void setSemestre(int semestre_nuevo){this -> semestre = semestre_nuevo;}
    int getSemestre() const{return semestre;}
    void estudiar();
};
Estudiante::Estudiante(int __codigo, string __carrera, int __semestre) : Persona(nombre, apellido, fecha_nacimiento), codigo(__codigo){
    strncpy(carrera, __carrera.c_str(), sizeof(carrera));
    this -> carrera[sizeof(carrera) - 1] = '\0';
    this -> semestre = __semestre;
}
void Estudiante::estudiar(){
    cout << "El estudiante " << nombre << " " << apellido << " está estudiando" << endl;
}

int main(){
    for (;;){
        char nombre[20], apellido[20], carrera[50], opcion;
        int anio, mes, dia, semestre;
        cout << "Es ustd estudiante?" << endl;
        cout << "                   (S) Si" << endl; 
        cout << "                   (N) No" << endl;
        cin >> opcion;
        opcion = toupper(opcion);
        if (opcion== 'S'){
            cout << "Ingrese los datos" << endl;
            cout << "Ingrese el nombre: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(nombre, 20);
            cout << "Ingrese el apellido: ";
            cin.getline(apellido, 20);
            cout << "Ingrese la fecha de nacimiento (YYYY MM DD): ";
            cin >> anio >> mes >> dia;
            cout << "Ingrese la carrera: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(carrera, 50);
            cout << "Ingrese el semestre: ";
            cin >> semestre;
            Estudiante* estudiante1 = new Estudiante(123456, carrera, semestre);
            cout << "El estudiante es: " << endl;
            cout << estudiante1 -> getApellido();
            cout << estudiante1 -> getNombre();
            cout << "Código: " << estudiante1 -> getCodigo() << endl;
            cout << "Carrera: " << estudiante1 -> getCarrera() << endl;
            cout << "Semestre: " << estudiante1 -> getSemestre() << endl;
            estudiante1 -> getFechaNacimiento();
        }
        else if (opcion == 'N'){
            cout << "Ingrese los datos" << endl;
            cout << "Ingrese el nombre: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(nombre, 20);
            cout << "Ingrese el apellido: ";
            cin.getline(apellido, 20);
            cout << "Ingrese la fecha de nacimiento (YYYY MM DD): ";
            cin >> anio >> mes >> dia;
            Persona* persona1 = new Persona(nombre, apellido, valida_fecha(anio, mes, dia));
            cout << "La persona es: " << endl;
            cout << persona1 -> getApellido();
            cout << persona1 -> getNombre();
            persona1 -> getFechaNacimiento();
        }
        else throw invalid_argument("Opción inválida");
    }
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