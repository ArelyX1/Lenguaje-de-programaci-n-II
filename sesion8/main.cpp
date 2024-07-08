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
#include <thread>
#include <limits>

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
int escojerGrado();
int escojerTipoUsr();
void agregarUsuario();
void agregarLibro();
void hacerPrestamo();

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
enum class TipoAcceso {
    SS = 1, AD, BD, CD
};
class Libro{
    public:
        char autor[21], isbn[14];
        string titulo, genero;
        TipoAcceso tipoAcceso;
        bool disponible = true;
        int anio;
        //todo agregar el atributo de tipo de acceso(grado), SS(exclusivo de investigadores), 
        //todo AD(para investigadores y profesores), BD(para investigadores, profesores y estudiantes)
        //todo y  CD(para investigadores, profesores, estudiantes y generales)
        Libro(char _autor[21], char _isbn[14], string titulo, string genero, int anio, TipoAcceso _tipoAcceso){
            strncpy(this->isbn, _isbn, sizeof(this->isbn));
            this -> isbn[sizeof(this->isbn) - 1] = '\0';
            strncpy(this->autor, _autor, sizeof(this->autor));
            this -> autor[sizeof(this->autor) - 1] = '\0';
            this -> titulo = titulo;
            this -> genero = genero;
            this -> anio = anio;
            this -> tipoAcceso = _tipoAcceso;
            setData();
        }
        void setData(){
            try{
                ofstream file("biblioteca.csv", ios::app | ios::out);
                if(!file.is_open()) {
                    throw ofstream::failure("No se puede abrir el archivo usuarios.csv");
                }
                file << isbn << ";" << titulo << ";" << autor << ";" << genero << ";" << anio << ";" << getTipoAcceso() << ";";
                (disponible)? file << "disponible" << endl : file << "no disponible" << endl;
                file.close();
            }
            catch(exception &e){
                cout << "No se puede abrir el archivo" << endl;
            }
        }
        string getTipoAcceso() const {
            switch (tipoAcceso) {
                case TipoAcceso::SS:
                    return "SS";
                case TipoAcceso::AD:
                    return "AD";
                case TipoAcceso::BD:
                    return "BD";
                case TipoAcceso::CD:
                    return "CD";
                default:
                    return "Desconocido";
            }
        }

        friend ostream& operator<<(ostream& os, const Libro& lbro){
            os << "ISBN: " << lbro.isbn << endl
            << "Titulo: " << lbro.titulo << endl
            << "Autor: " << lbro.autor << endl
            << "Genero: " << lbro.genero << endl
            << "Anio: " << lbro.anio << endl
            << "Grado: " << lbro.getTipoAcceso() << endl;
            return os;
        }
};

class Usuario{
    public:
        char nombre[21], id[11];
        int edad;
        Mapa<Libro*, string> libros_prestamos;
        vector <Libro*> libros;
        Usuario(char _nombre[21], char _id[11], int edad){
            strncpy(this-> nombre, _nombre, sizeof(this->nombre)); 
            this->nombre[sizeof(this->nombre) - 1] = '\0';
            strncpy(this->id, _id, sizeof(this->id)); 
            this->id[sizeof(this->id) - 1] = '\0';
            this->edad = edad;
            setData();
        }
        //todo Deberia de modificar el tipode acceso del libro para hacer el prestamo, el metodo debe de estar como virtual puro
        virtual void setLibro(Libro *libro, string fecha_limite) = 0;
        void verificar_prestamo(){
            if(!libros_prestamos.contar())cout << "No tienes libros prestados" << endl;
            for (int i = 0; i < libros_prestamos.contar(); i++) {
                try {
                    cout << *libros_prestamos.getFirst(libros[i]);
                    (comparar_fechas(libros_prestamos.getSecond(libros[i])))? cout << "***El libro paso del plazo***" << endl : cout << "El libro no paso del plazo" << endl;
                } catch (const out_of_range& e) {
                    cout << "Error: " << e.what() << endl;
                }
            }
        }
        //todo El parametro debe ser el isbn o retornar el second del mapa
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
                ofstream file("usuarios.csv", ios::app | ios::out);
                if(!file.is_open()) {
                    throw ofstream::failure("No se puede abrir el archivo usuarios.csv");
                }
                file << id << ";" << nombre << ";" << edad << ";" << libros.size() << endl;
                file.close();
            }
            catch(exception &e){
                cout << "No se puede abrir el archivo" << endl;
            }
        }
        friend ostream& operator<<(ostream& os, const Usuario& u){
            
            os << "Nombre: " << u.nombre << ", Id: " << u.id << ", Edad: " << u.edad << "\t";
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

class General: public Usuario{
    public:
        General(char _nombre[21], char _id[11], int edad) : Usuario(_nombre, _id, edad){}
        void setLibro(Libro *libro, string fecha_limite) override{
            if(!libro -> disponible){
                cout << "El libro no está disponible" << endl;
                return;
            }
            if(libro -> tipoAcceso == TipoAcceso::CD){
                libro -> disponible = false;
                this -> libros_prestamos.insertar(libro, fecha_limite);
                this -> libros.push_back(libro);
                return;
            }else cout << "No tienes acceso a este libro" << endl;
        }
};

class Estudiante: public Usuario{
    public:
        Estudiante(char _nombre[21], char _id[11], int edad) : Usuario(_nombre, _id, edad){}
        void setLibro(Libro *libro, string fecha_limite) override{
            if(!libro -> disponible){
                cout << "El libro no está disponible" << endl;
                return;
            }
            if(libro -> tipoAcceso == TipoAcceso::BD || libro -> tipoAcceso == TipoAcceso::CD){
                libro -> disponible = false;
                this -> libros_prestamos.insertar(libro, fecha_limite);
                this -> libros.push_back(libro);
                return;
            }else cout << "No tienes acceso a este libro" << endl;
        }
};

class Profesor: public Usuario{
    public:
        Profesor(char _nombre[21], char _id[11], int edad) : Usuario(_nombre, _id, edad){}
        void setLibro(Libro *libro, string fecha_limite) override{
            if(!libro -> disponible){
                cout << "El libro no está disponible" << endl;
                return;
            }
            if(libro -> tipoAcceso == TipoAcceso::AD || libro -> tipoAcceso == TipoAcceso::BD || libro -> tipoAcceso == TipoAcceso::CD){
                libro -> disponible = false;
                this -> libros_prestamos.insertar(libro, fecha_limite);
                this -> libros.push_back(libro);
                return;
            }else cout << "No tienes acceso a este libro" << endl;
        }
};

class Investigador: public Usuario{
    public:
        Investigador(char _nombre[21], char _id[11], int edad) : Usuario(_nombre, _id, edad){}
        void setLibro(Libro *libro, string fecha_limite) override{
            if(!libro -> disponible){
                cout << "El libro no está disponible" << endl;
                return;
            }
            libro -> disponible = false;
            this -> libros_prestamos.insertar(libro, fecha_limite);
            this -> libros.push_back(libro);
        }
};

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

    cout<< " /$$$$$$$ /$$/$$      /$|/$$           /$$                                      /$$               /$$         /$$      /$$                           " << endl
        << "| $$__  $|__| $$     | $|__/          | $$                                     | $$              |__/        | $$$    /$$$                           " << endl
        << "| $$  \\ $$/$| $$$$$$$| $$/$$ /$$$$$$ /$$$$$$   /$$$$$$  /$$$$$$$ /$$$$$$       | $$      /$$   /$$/$$ /$$$$$$| $$$$  /$$$$ /$$$$$$ /$$$$$$$  /$$$$$$ " << endl
        << "| $$$$$$$| $| $$__  $| $| $$/$$__  $|_  $$_/  /$$__  $$/$$_____/|____  $$      | $$     | $$  | $| $$/$$_____| $$ $$/$$ $$/$$__  $| $$__  $$/$$__  $$" << endl
        << "| $$__  $| $| $$  \\ $| $| $| $$  \\ $$ | $$   | $$$$$$$| $$       /$$$$$$$      | $$     | $$  | $| $|  $$$$$$| $$  $$$| $| $$  \\ $| $$  \\ $| $$  \\ $$" << endl
        << "| $$  \\ $| $| $$  | $| $| $| $$  | $$ | $$ /$| $$_____| $$      /$$__  $$      | $$     | $$  | $| $$\\____  $| $$\\  $ | $| $$  | $| $$  | $| $$  | $$" << endl
        << "| $$$$$$$| $| $$$$$$$| $| $|  $$$$$$/ |  $$$$|  $$$$$$|  $$$$$$|  $$$$$$$      | $$$$$$$|  $$$$$$| $$/$$$$$$$| $$ \\/  | $|  $$$$$$| $$  | $|  $$$$$$/" << endl
        << "|_______/|__|_______/|__|__/\\______/   \\___/  \\_______/\\_______/\\_______/      |________/\\______/|__|_______/|__/     |__/\\______/|__/  |__/\\______/ " << endl
        << endl;
    //* verificador de repeticiones
    
    {
        ifstream file("biblioteca.csv", ios::in);
        if (!file.is_open()) {
            ofstream newfile("biblioteca.csv",ios::out);
            if (!newfile.is_open())
                throw ofstream::failure("No se puede abrir el archivo biblioteca.csv");
            file.close();
        }
        string linea, isbn;
        while (getline(file, linea)) {
            stringstream token(linea);
            getline(token, isbn, ';');
            stl_set_libros.insert(isbn);
        }
        file.close();
    }
    {
        ifstream file("usuarios.csv", ios::in);
        if (!file.is_open()) {
            ofstream newfile("usuarios.csv",ios::out);
            if (!newfile.is_open())
                throw ofstream::failure("No se puede abrir el archivo usuarios.csv");
            newfile.close();
        }
        string linea, codigo;
        while (getline(file, linea)) {
            stringstream token(linea);
            getline(token, codigo, ';');
            stl_set_usuarios.insert(codigo);
        }
        file.close();
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
    //todo agregar el archivo al contenedor
    /*
    {
        ifstream file("biblioteca.csv", ios::in);
        if (!file.is_open()) {
            throw ifstream::failure("No se puede abrir el archivo biblioteca.csv");
        }
        string linea, isbn, titulo, autor, genero, anio, disponible, grado;
        while (getline(file, linea)) {
            stringstream token(linea);
            getline(token, isbn, ';');
            getline(token, titulo, ';');
            getline(token, autor, ';');
            getline(token, genero, ';');
            getline(token, anio, ';');
            getline(token, grado, ';');
            getline(token, disponible, ';');
            TipoAcceso tipoAcceso;
            if (grado == "SS")
                tipoAcceso = TipoAcceso::SS;
            else if (grado == "AD")
                tipoAcceso = TipoAcceso::AD;
            else if (grado == "BD")
                tipoAcceso = TipoAcceso::BD;
            else if (grado == "CD")
                tipoAcceso = TipoAcceso::CD;
            else
                throw invalid_argument("Opcion invalida");
            char autor_arr[20];
            char isbn_arr[13];
            strncpy(autor_arr, autor.c_str(), sizeof(autor));
            autor[sizeof(autor_arr) - 1] = '\0';
            strncpy(isbn_arr, isbn.c_str(), sizeof(isbn));
            isbn[sizeof(isbn_arr) - 1] = '\0';
            contenedorLibros.insertar(isbn, new Libro(autor_arr, isbn_arr, titulo, genero, stoi(anio), tipoAcceso));
        }
        file.close();
    }
    {
        ifstream file("usuarios.csv", ios::in);
        if (!file.is_open()) {
            throw ifstream::failure("No se puede abrir el archivo usuarios.csv");
        }
        string linea, codigo, nombre, edad, libros;
        while (getline(file, linea)) {
            stringstream token(linea);
            getline(token, codigo, ';');
            getline(token, nombre, ';');
            getline(token, edad, ';');
            getline(token, libros, ';');
            char nombre_arr[21];
            char codigo_arr[11];
            strncpy(nombre_arr, nombre.c_str(), sizeof(nombre));
            nombre[sizeof(nombre_arr) - 1] = '\0';
            strncpy(codigo_arr, codigo.c_str(), sizeof(codigo));
            codigo[sizeof(codigo_arr) - 1] = '\0';
            contenedorUsuarios.insertar(codigo, new Usuario(nombre_arr, codigo_arr, stoi(edad)));
        }
        file.close();
    }
    */
    /*
    Libro *lbro5 = new Libro("ElJujas", "123456789", "El li1231bro", "Fic123ción", 2022, TipoAcceso::SS);
    contenedorLibros.insertar("123456789", lbro5);
    cout << *lbro5 << endl;

    Usuario *usr = new General("Juja", "0123456789", 18);
    contenedorUsuarios.insertar("0123456789", usr);
    usr -> setLibro(lbro5, "01/01/2024");

    cout << *contenedorUsuarios.getSecond("0123456789");
    usr -> verificar_prestamo();




    //? verificador de repeticiones
    char isbn2[14];
    cin.getline(isbn2, sizeof(isbn2));
    if (stl_set_libros.find(isbn2) != stl_set_libros.end()) {
        cout << "Libro encontrado:" << endl;
        cout << "ISBN: " << isbn2 << endl;
    }
    */
    menu();
    

    cout << endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "Tiempo de ejecución: " << duration << " ms" << endl;
}


void menu(){
    cout << "Menu principal" << endl
    << "Opciones de Libro -------[1]" << endl
    << "Opciones de Usuario -----[2]" << endl
    << "Salir -------------------[3]\n\t? ";
    unsigned short int opcion = getTYPENAME<unsigned short int>();
    switch (opcion) {
        case 1:
            menu_libro();
            menu();
            break;
        case 2:
            menu_usuario();
            menu();
            break;
        case 3:
            cout << "Saliendo del programa..." << endl;
            break;
    }
}

void menu_libro(){
    cout << "OPCIONES DE LIBRO" << endl
        << "Mostrar Biblioteca -------[1]" << endl
        << "Buscar Libro -------------[2]" << endl
        << "Agregar Libro ------------[3]" << endl
        << "Salir --------------------[4]" << endl;
    unsigned short int opcion = getTYPENAME<unsigned short int>();
    switch (opcion) {
        case 1: 
            mostrar_biblioteca();
            break;
        case 2:
            char isbn_buscar[14];
            cout << "Ingrese el ISBN del libro a buscar:" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(isbn_buscar, sizeof(isbn_buscar));
            buscar_libro(isbn_buscar);
            break;
        case 3:
            agregarLibro();
            break;
    }
}

void agregarLibro(){
    char autor[21], isbn[14];
    string titulo, genero;
    int anio;
    TipoAcceso tipoAcceso;
    cout << "Ingrese los datos del libro:" << endl;
    cout << "ISBN:" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(isbn, sizeof(isbn));
    if (stl_set_libros.find(isbn) != stl_set_libros.end())
        throw invalid_argument("El libro ya existe en la biblioteca");
    cout << "Autor:" << endl;
    cin.getline(autor, sizeof(autor));
    cout << "Titulo:" << endl;
    getline(cin, titulo);
    cout << "Genero:" << endl;
    getline(cin, genero);
    cout << "Anio:" << endl;
    cin >> anio;
    cout << "Tipo de que grado de acceso es?" << endl;
    switch (escojerGrado()) {
        case 1:
            tipoAcceso = TipoAcceso::SS;
            break;
        case 2:
            tipoAcceso = TipoAcceso::AD;
            break;
        case 3:
            tipoAcceso = TipoAcceso::BD;
            break;
        case 4:
            tipoAcceso = TipoAcceso::CD;
            break;
        default:
            throw invalid_argument("Opcion invalida");
    }
    contenedorLibros.insertar(isbn, new Libro(autor, isbn, titulo, genero, anio, tipoAcceso));
}

int escojerGrado(){
    cout<< "1 - SS (exclusivo de investigadores)" << endl
        << "2 - AD (para investigadores y profesores)" << endl
        << "3 - BD (para investigadores, profesores y estudiantes)" << endl
        << "4 - CD (para investigadores, profesores, estudiantes y generales)" << endl;
    int opcion;
    cin >> opcion;
    return opcion;
}

void menu_usuario(){
    cout << "OPCIONES DE USUARIO" << endl
        << "Mostrar Usuario ---------[1]" << endl
        << "Buscar Usuario ----------[2]" << endl
        << "Agregar Usuario ---------[3]" << endl
        << "Hacer Prestamo ----------[4]" << endl
        << "Devolver Libro ----------[5]" << endl
        << "verificar prestamo ------[6]" << endl
        << "Salir -------------------[7]" << endl;
    unsigned short int opcion = getTYPENAME<unsigned short int>();
    switch (opcion) {
        case 1:
            mostrar_usuarios();
            break;
        case 2:
            char id_buscar[11];
            cout << "Ingrese el codigo del usuario:" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(id_buscar, sizeof(id_buscar));
            buscar_usuario(id_buscar);
            break;
        case 3:
            agregarUsuario();
            break;
        case 4:
            hacerPrestamo();
            break;
        case 5:
            char id[11], isbn[14];
            cout << "Ingrese el codigo del usuario:" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(id, sizeof(id));
            cout << "Ingrese el codigo del libro:" << endl;
            cin.getline(isbn, sizeof(isbn));
            contenedorUsuarios.getSecond(id) -> devolverLibro(contenedorLibros.getSecond(isbn));
            break;
        case 6:
            char _id[11];
            cout << "Ingrese el codigo del usuario:" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(_id, sizeof(_id));
            contenedorUsuarios.getSecond(_id) -> verificar_prestamo();
            break;
        case 7:
            cout << "Saliendo del programa..." << endl;
            break;
    }
}

void hacerPrestamo(){
    char set_id[11], set_isbn[14];
    cout << "Ingrese el codigo del usuario:" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(set_id, sizeof(set_id));
    cout << "Ingrese el codigo del libro:" << endl;
    cin.getline(set_isbn, sizeof(set_isbn));
    int dias, mes, anio;
    cout << "Ingrese la fecha limite del prestamo: primero dia, segundo mes y año:" << endl;
    cin >> dias >> mes >> anio;
    string fecha_lim = format_date(valida_fecha(dias, mes, anio));
    contenedorUsuarios.getSecond(set_id) -> setLibro(contenedorLibros.getSecond(set_isbn), fecha_lim);
}

void agregarUsuario(){
    char id[11], nombre[21];
    int edad;
    cout << "Ingrese los datos del usuario:" << endl;
    cout << "Codigo:" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(id, sizeof(id));
    if (stl_set_usuarios.find(id) != stl_set_usuarios.end())
        throw invalid_argument("El usuario ya existe");
    cout << "Nombre:" << endl;
    cin.getline(nombre, sizeof(nombre));
    cout << "Edad:" << endl;
    cin >> edad;
    cout << "Que tipo de usuario es?:" << endl;
    switch (escojerTipoUsr()) {
        case 1:
            contenedorUsuarios.insertar(id, new Investigador(nombre, id, edad));
            break;
        case 2:
            contenedorUsuarios.insertar(id, new Profesor(nombre, id, edad));
            break;
        case 3:
            contenedorUsuarios.insertar(id, new Estudiante(nombre, id, edad));
            break;
        case 4:
            contenedorUsuarios.insertar(id, new General(nombre, id, edad));
            break;
        default:
            throw invalid_argument("Opcion invalida");
    }
}

int escojerTipoUsr(){
    cout<< "1 - Investigador" << endl
        << "2 - Profesor" << endl
        << "3 - Estudiante" << endl
        << "4 - General" << endl;
    int opcion;
    cin >> opcion;
    return opcion;
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
        string linea, codigo, nombre, edad, tipo_usr, libros, grado;
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
        string linea, isbn, titulo, autor, genero, anio, disponible, grado;
        while (getline(file, linea)) {
            stringstream token(linea);
            getline(token, isbn, ';');
            getline(token, titulo, ';');
            getline(token, autor, ';');
            getline(token, genero, ';');
            getline(token, anio, ';');
            getline(token, grado, ';');
            getline(token, disponible, ';');

            cout << "ISBN: "   << isbn     << endl
            << "Titulo: "      << titulo   << endl
            << "Autor: "       << autor    << endl
            << "Genero: "      << genero   << endl
            << "Anio: "        << anio     << endl
            << "Grado: "       << grado    << endl
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
        string linea, codigo, nombre, edad, libros;
        while (getline(file, linea)) {
            stringstream token(linea);
            getline(token, codigo, ';');
            getline(token, nombre, ';');
            getline(token, edad, ';');
            getline(token, libros, ';');
            if (codigo == id) {
                cout << "Usuario encontrado:" << endl;
                cout << "Codigo: " << codigo << endl
                << "Nombre: " << nombre << endl
                << "Edad: " << edad << endl
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
        string linea, isbn, titulo, autor, genero, anio, disponible, grado;
        while (getline(file, linea)) {
            stringstream token(linea);
            getline(token, isbn, ';');
            getline(token, titulo, ';');
            getline(token, autor, ';');
            getline(token, genero, ';');
            getline(token, anio, ';');
            getline(token, grado, ';');
            getline(token, disponible, ';');
            if (isbn == id) {
                cout << "Libro encontrado:" << endl;
                cout << "ISBN: " << isbn << endl
                << "Titulo: " << titulo << endl
                << "Autor: " << autor << endl
                << "Genero: " << genero << endl
                << "Anio: " << anio << endl
                << "Grado: " << grado << endl
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
