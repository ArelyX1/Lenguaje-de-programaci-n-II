#include "dependencias/valida.h"

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
#include <set>
#include <cstdlib>

using namespace std;

//Definiciones de clases
class Libro;
template <typename T1, typename T2>
class Mapa;
class Usuario;
class General;
class Estudiante;
class Profesor;
class Investigador;

//Prototipos de funciones
string get_fecha();
chrono::system_clock::time_point valida_fecha(int anio, int mes, int dia);
string format_date(const chrono::system_clock::time_point& date);
bool comparar_fechas(string fecha_plazo);
void menu();
void mostrar_usuarios();
void mostrar_biblioteca();
void menu_libro();
void menu_usuario();
void buscar_usuario(string id);
void buscar_libro(string id);

template <typename T1, typename T2>
class Mapa {
    public:
        map<T1, T2> mapa;

        void insertar(T1 clave, T2 valor) {
            mapa[clave] = valor;
        }

        void mostrar() {
            for(const auto& par : mapa) {
                cout << "Clave: " << par.first << ", Valor: ";
                cout << par.second << endl; 
            }
        }

        void borrar(T1 clave) {
            mapa.erase(clave);
        }
        T2 getSecond(const T1 clave) {
            auto it = mapa.find(clave);
            if (it != mapa.end()) {
                return it->second;
            }
            throw out_of_range("Clave no encontrada en el mapa");
        }

        T1 getFirst(const T1 clave) {
            auto it = mapa.find(clave);
            if (it != mapa.end()) {
                return it->first;
            }
            throw out_of_range("Clave no encontrada en el mapa");
        }

        void mostrar(T1 clave) {
            auto it = mapa.find(clave);
            if (it != mapa.end()) {
                cout << "Clave: " << it->first << ", Valor: " << it->second << endl;
            } else {
                cout << "La clave no existe en el mapa." << endl;
            }
        }

        int contar(){
            int cont = 0;
            for(const auto& par : mapa) {
                cont++; 
            }
            return cont;
        }
};
class Libro{
    public:
        char autor[20], isbn[13];
        string titulo, genero;
        bool disponible = true;
        int anio;
        //todo agregar el atributo de tipo de acceso(grado), SS(exclusivo de investigadores), 
        //todo AD(para investigadores y profesores), BD(para investigadores, profesores y estudiantes)
        //todo y  CD(para investigadores, profesores, estudiantes y generales)
        Libro(string autor, string isbn, string titulo, string genero, int anio){
            strcpy(this->autor, autor.c_str());
            strcpy(this->isbn, isbn.c_str());
            this->titulo = titulo;
            this->genero = genero;
            this->anio = anio;
            setData();
        }
        void setData(){
            try{
                ofstream file("biblioteca.csv", ios::app | ios::out);
                if(!file.is_open()) {
                    throw ofstream::failure("No se puede abrir el archivo usuarios.csv");
                }
                file << isbn << ";" << titulo << ";" << autor << ";" << genero << ";" << anio << ";";
                (disponible)? file << "disponible" << endl : file << "no disponible" << endl;
                file.close();
            }
            catch(exception &e){
                cout << "No se puede abrir el archivo" << endl;
            }
        }
        friend ostream& operator<<(ostream& os, const Libro& lbro){
            os << "ISBN: " << lbro.isbn << endl
            << "Titulo: " << lbro.titulo << endl
            << "Autor: " << lbro.autor << endl
            << "Genero: " << lbro.genero << endl
            << "Anio: " << lbro.anio << endl;
            return os;
        }
};

class Usuario{
    public:
        char nombre[20], id[10];
        int edad;
        string tipo_usr;
        Mapa<Libro*, string> libros_prestamos;
        vector <Libro*> libros;
        int cont = 0;
        Usuario(string nombre, string id, int edad, string tipo_usr){
            strcpy(this->nombre, nombre.c_str());
            strcpy(this->id, id.c_str());
            this->edad = edad;
            this -> tipo_usr = tipo_usr;
            setData();
        }
        //todo Deberia de modificar el tipo de acceso del libro para hacer el prestamo, el metodo debe de estar como virtual puro
        void setLibro(Libro *libro, string fecha){
            if(libro->disponible){
                libro->disponible = false;
                this->libros_prestamos.insertar(libro, fecha);
                this->libros.push_back(libro);
            }
            else{
                cout << "El libro no está disponible" << endl;
            }
        }
        void verificar_prestamo(){
            for (int i = 0; i < libros_prestamos.contar(); i++) {
                try {
                    cout << *libros_prestamos.getFirst(libros[i]);
                    (comparar_fechas(libros_prestamos.getSecond(libros[i])))? cout << "***El libro paso del plazo***" << endl : cout << "El libro no paso del plazo" << endl;
                } catch (const out_of_range& e) {
                    cout << "Error: " << e.what() << endl;
                }
            }
        }
        //todo El parametro debe ser el isbn
        void devolverLibro(Libro *libro){
            libro->disponible = true;
            this -> libros_prestamos.borrar(libro);

            for (int i = 0; static_cast<unsigned int>(i) < libros.size(); i++) {
                if (libros[i] == libro) {
                    libros.erase(libros.begin() + i);
                    break;
                }
            }
            cout << "se devolvio el libro" << endl;
        }
        void setData(){
            try{
                ofstream file("usuarios.csv", ios::app);
                if(!file.is_open()) {
                    throw ofstream::failure("No se puede abrir el archivo usuarios.csv");
                }
                file << id << ";" << nombre << ";" << edad << ";" << tipo_usr << ";" << libros.size() << endl;
                file.close();
            }
            catch(exception &e){
                cout << "No se puede abrir el archivo" << endl;
            }
        }
        friend ostream& operator<<(ostream& os, const Usuario& u){
            os << "Nombre: " << u.nombre << ", Id: " << u.id << ", Edad: " << u.edad << ", Tipo de usuario: " << u.tipo_usr << "\t";
            if (!u.libros.empty()){
                os << "Libros prestados:" << endl;
                for (const auto& libro : u.libros) {
                    os << "  Libro: " << libro->titulo << ", Autor: " << libro->autor << ", ISBN: " << libro->isbn << endl;
                }
            } else {
                os << "No tiene libros prestados." << endl;
            }
            return os;
        }
};

//todo agregar las clases general, estudiante, profesor, investigador

//Inicialización de plantillas clase y STL

Mapa<string, Libro*> contenedorLibros;
Mapa<string, Usuario*> contenedorUsuarios;
set<string> stl_set_libros;
set<string> stl_set_usuarios;
int main(){
    auto start = chrono::high_resolution_clock::now();
    /*
    Mapa<string, int> mapa;
    mapa.insertar("Juan", 18);
    mapa.insertar("Pedro", 25);
    mapa.insertar("Maria", 30);
    mapa.mostrar();
    mapa.mostrar("Juan");
    mapa.borrar("Juan");
    mapa.mostrar();
    Usuario *usr = new Usuario("Juja", "0123456789", 18, "Investigador");
    Libro *lbro1 = new Libro("ElJujas", "123456789", "El libro", "Ficción", 2022);
    Libro *lbro2 = new Libro("ElJu2131jas", "123456789", "El li1231bro", "Fic123ción", 2022);
    contenedorLibros.insertar("ElJujas", lbro1);
    contenedorLibros.insertar("ElJu2131jas", lbro2);
    contenedorUsuarios.insertar("Juja", usr);
    contenedorUsuarios.mostrar();
    cout << *usr << endl;
    mostrar_usuarios();
    contenedorUsuarios.getSecond("Juja") -> setLibro(lbro1, "01/01/2024");
    cout << *contenedorUsuarios.getSecond("Juja");
    contenedorUsuarios.getSecond("Juja") -> setData();
    contenedorUsuarios.getSecond("Juja") -> verificar_prestamo();
    //Libro *lbro3 = new Libro("ElJujas", "123456789", "El li1231bro", "Fic123ción", 2022);
    stl_set_libros.insert("ElJu2131jas");
    stl_set_libros.insert("ElJujas");
    stl_set_libros.insert("ElJujas");
    //contenedorLibros.insertar("ElJujas", lbro3);

    ofstream file("biblioteca.csv", ios::trunc);
    file.close();


    Usuario *usr2 = new Usuario("Juja", "0123456789", 18, "Investigador");
    Libro *lbro4 = new Libro("ElJujas", "123456789", "El li1231bro", "Fic123ción", 2022);
    Libro *lbro5 = new Libro("ElJu21313333jas", "123456789", "El li1231bro", "Fic123ción", 2022);
    
    contenedorLibros.insertar("123456789", lbro4);
    contenedorUsuarios.insertar("0123456789", usr2);
    int dias, mes, anio;
    cout << "Ingrese la fecha de la prestamo:" << endl;
    cin >> dias >> mes >> anio;
    string fecha = format_date(valida_fecha(dias,mes, anio));
    contenedorUsuarios.getSecond("0123456789") -> setLibro(lbro4, "01/01/2024");
    contenedorUsuarios.getSecond("0123456789") -> setLibro(lbro5, "01/01/2024");
    cout << *contenedorUsuarios.getSecond("0123456789");
    contenedorUsuarios.getSecond("0123456789") -> verificar_prestamo();
    contenedorUsuarios.getSecond("0123456789") -> devolverLibro(lbro4);
    cout << *contenedorUsuarios.getSecond("0123456789");
    //actualizar libros
    for(string libro : stl_set_libros){
        contenedorLibros.getSecond(libro) -> setData();
    }
    mostrar_biblioteca();

    menu();
    */
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "Tiempo de ejecución: " << duration << " milliseconds" << endl;
    cout << "SOLO FALTA LOS MENUS, LAS OPERACIONES ESTAN COMPLETAS" << endl;
}


void menu(){
    cout << "Menu principal" << endl
    << "Opciones de Libro -------[1]" << endl
    << "Opciones de Usuario -----[2]" << endl
    << "Salir -------------------[3]" << endl;
    unsigned short int opcion;
    try{
        opcion = getTYPENAME<unsigned short int>();
    } catch (const invalid_argument& ia) {
        cerr << ia.what() << endl;
        exit(1);
    }
    switch (opcion) {
        case 1:
            menu_libro();
            break;
        case 2:
            
        case 3:
            cout << "Saliendo del programa..." << endl;
            break;
    }
}

void menu_libro(){
    unsigned short int opcion;
    cout << "OPCIONES DE LIBRO" << endl
        << "Mostrar Biblioteca -------[1]" << endl
        << "Buscar Libro -------------[2]" << endl
        << "Agregar Libro ------------[3]" << endl
        << "Salir --------------------[4]" << endl;
    try{
        opcion = getTYPENAME<unsigned short int>();            
    } catch (const invalid_argument& ia) {
        cerr << ia.what() << endl;
        exit(1);
    }
    switch (opcion) {
        case 1: 
            mostrar_biblioteca();
            break;
        case 2:
        default:
            break;
    }
}

void menu_usuario(){
    unsigned short int opcion;
    cout << "OPCIONES DE USUARIO" << endl
        << "Mostrar Usuario ---------[1]" << endl
        << "Buscar Usuario ----------[2]" << endl
        << "Agregar Usuario ---------[3]" << endl
        << "Hacer Prestamo ----------[4]" << endl
        << "Salir --------------------[5]" << endl;
    try{
        opcion = getTYPENAME<unsigned short int>();            
    }catch (const invalid_argument& ia) {
        cerr << ia.what() << endl;
        exit(1);
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

chrono::system_clock::time_point valida_fecha(int dia, int mes, int anio){
    if (mes < 1 || mes > 12) {
        throw invalid_argument("Mes inválido");
    }
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

bool comparar_fechas(string fecha_plazo){
    string fecha_actual = get_fecha();
    if (fecha_actual <= fecha_plazo) {
        return false;
    } else {
        return true;
    }
}

void mostrar_usuarios(){
    try{
        ifstream file("usuarios.csv", ios::in);
        if (!file.is_open()) {
            throw ifstream::failure("No se puede abrir el archivo usuarios.csv");
        }
        string linea, codigo, nombre, edad, tipo_usr, libros;
        while (getline(file, linea)) {
            stringstream token(linea);
            getline(token, codigo, ';');
            getline(token, nombre, ';');
            getline(token, edad, ';');
            getline(token, tipo_usr, ';');
            getline(token, libros, ';');
            cout << "Codigo: " << codigo << endl
            << "Nombre: " << nombre << endl
            << "Edad: " << edad << endl
            << "Tipo de usuario: " << tipo_usr << endl
            << "Libros prestados: " << libros << endl;
        }
        file.close();
    } catch (const invalid_argument& ia) {
        cerr << ia.what() << endl;
        exit(1);
    }
}

void mostrar_biblioteca(){
    try{
        ifstream file("biblioteca.csv", ios::in);
        if (!file.is_open()) {
            throw ifstream::failure("No se puede abrir el archivo biblioteca.csv");
        }
        string linea, isbn, titulo, autor, genero, anio, disponible;
        while (getline(file, linea)) {
            stringstream token(linea);
            getline(token, isbn, ';');
            getline(token, titulo, ';');
            getline(token, autor, ';');
            getline(token, genero, ';');
            getline(token, anio, ';');
            getline(token, disponible, ';');

            cout << "ISBN: "   << isbn     << endl
            << "Titulo: "      << titulo   << endl
            << "Autor: "       << autor    << endl
            << "Genero: "      << genero   << endl
            << "Anio: "        << anio     << endl
            << disponible               << endl;
        }
        file.close();
    } catch (const invalid_argument& ia) {
        cout << ia.what() << endl;
    }    
}

void buscar_usuario(string id){
    try {
        ifstream file("usuarios.csv", ios::in);
        if (!file.is_open()) {
            throw ifstream::failure("No se puede abrir el archivo usuarios.csv");
        }
        string linea, codigo, nombre, edad, tipo_usr, libros;
        while (getline(file, linea)) {
            stringstream token(linea);
            getline(token, codigo, ';');
            getline(token, nombre, ';');
            getline(token, edad, ';');
            getline(token, tipo_usr, ';');
            getline(token, libros, ';');
            if (codigo == id) {
                cout << "Usuario encontrado:" << endl;
                cout << "Codigo: " << codigo << endl
                << "Nombre: " << nombre << endl
                << "Edad: " << edad << endl
                << "Tipo de usuario: " << tipo_usr << endl
                << "Libros prestados: " << libros << endl;
                break;
            }
        }
        file.close();
    } catch (const invalid_argument& ia) {
        cerr << ia.what() << endl;
        exit(1);
    }
}

void buscar_libro(string id){
    try {
        ifstream file("biblioteca.csv", ios::in);
        if (!file.is_open()) {
            throw ifstream::failure("No se puede abrir el archivo biblioteca.csv");
        }
        string linea, isbn, titulo, autor, genero, anio, disponible;
        while (getline(file, linea)) {
            stringstream token(linea);
            getline(token, isbn, ';');
            getline(token, titulo, ';');
            getline(token, autor, ';');
            getline(token, genero, ';');
            getline(token, anio, ';');
            getline(token, disponible, ';');
            if (isbn == id) {
                cout << "Libro encontrado:" << endl;
                cout << "ISBN: " << isbn << endl
                << "Titulo: " << titulo << endl
                << "Autor: " << autor << endl
                << "Genero: " << genero << endl
                << "Anio: " << anio << endl
                << disponible               << endl;
                break;
            }
        }
        file.close();
    } catch (const invalid_argument& ia) {
        cerr << ia.what() << endl;
        exit(1);
    }
}
