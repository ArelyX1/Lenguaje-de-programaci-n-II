#include "dependencias/valida.h"
#include "dependencias/getStr.h"

#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <chrono>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cstring>

using namespace std;

class Libro;
template <typename T1, typename T2>
class Mapa;
class Usuario;

template <typename T1, typename T2>
class Mapa {
public:
    map<T1, T2> mapa;

    void insertar(T1 clave, T2 valor) {
        mapa[clave] = valor;
    }

    void mostrar() {
        for (const auto& par : mapa) {
            cout << "Clave: " << par.first << ", Valor: " << *par.second << endl;
        }
        for(const auto& [clave, valor] : mapa){
            cout << &valor << endl;
        }
    }

    void borrar(T1 clave) {
        mapa.erase(clave);
    }

    void mostrar(T1 clave) {
        auto it = mapa.find(clave);
        if (it != mapa.end()) {
            cout << "Clave: " << it->first << ", Valor: " << it->second << endl;
        } else {
            cout << "La clave no existe en el mapa." << endl;
        }
    }
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
        vector <Libro*>libro;
        Usuario(string nombre, string id, int edad, string tipo_usr){
            strcpy(this->nombre, nombre.c_str());
            strcpy(this->id, id.c_str());
            this->edad = edad;
            this -> tipo_usr = tipo_usr;
            setData();
        }
        void setLibro(Libro* libro){
            this->libro.push_back(libro);
        }
        void setData(){
            try{
                ofstream file("ususarios.csv", ios::app);
                if(!file.is_open()) {
                    throw ofstream::failure("No se puede abrir el archivo ususarios.csv");
                }
                file << id << ";" << nombre << ";" << edad << ";" << tipo_usr << ";" << libro.size() << endl;
                file.close();
            }
            catch(exception &e){
                cout << "No se puede abrir el archivo" << endl;
            }
        }
        friend ostream& operator<<(ostream& os, Usuario& u){
            os << "Nombre: " << u.nombre << ", Id: " << u.id << ", Edad: " << u.edad << ", Tipo de usuario: " << u.tipo_usr << endl;
            for (int i = 0; i < u.libro.size(); i++) {
                os << "Libro: " << u.libro[i]->titulo << ", Autor: " << u.libro[i]->autor << ", ISBN: " << u.libro[i]->isbn << endl;
            }
            return os;
        }
};

void buscar_elemento(const map<string, int>& myMap, const string& key);
string get_fecha();
chrono::system_clock::time_point valida_fecha(int anio, int mes, int dia);
string format_date(const chrono::system_clock::time_point& date);
bool comparar_fechas(chrono::system_clock::time_point fecha);
void menu();

//Inicialización de plantillas clase
Mapa<string, Libro> contenedorLibros;
Mapa<string, Usuario> contenedorUsuarios;
int main(){
    vector<Mapa<string, int>> ususrios; 
    Mapa<string, int> mapa;
    mapa.insertar("Juan", 18);
    mapa.insertar("Pedro", 25);
    mapa.insertar("Maria", 30);
    mapa.mostrar();
    mapa.mostrar("Juan");
    mapa.borrar("Juan");
    mapa.mostrar();
    Usuario *usr = new Usuario("Juan", "0123456789", 18, "Investigador");
    contenedorUsuarios.insertar("Juan", *usr);
    contenedorUsuarios.mostrar();
    cout << *usr;
}


void menu(){
    cout << "Menu principal" << endl
    << "Opciones de Libro -------[1]" << endl
    << "Opciones de Usuario -----[2]" << endl
    << "Salir -------------------[3]" << endl;
    unsigned short int opcion;
    try{
        opcion = getTYPEMANE<unsigned short int>();
    } catch (const invalid_argument& ia) {
        cerr << ia.what() << endl;
    }
    switch (opcion) {
        case 1:
            cout << "OPCIONES DE LIBRO" << endl
            << "Mostrar Biblioteca -------[1]" << endl
            << "Buscar Libro -------------[2]" << endl
            << "Agregar Libro ------------[3]" << endl
            << "Salir --------------------[4]" << endl;
            unsigned short int opcion2;
            try{
                opcion2 = getTYPEMANE<unsigned short int>();
            } catch (const invalid_argument& ia) {
                cerr << ia.what() << endl;
            }
            break;
        case 2:
            cout << "Opcion 2" << endl;
            break;
        case 3:
            cout << "Opcion 3" << endl;
            break;
    }
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
