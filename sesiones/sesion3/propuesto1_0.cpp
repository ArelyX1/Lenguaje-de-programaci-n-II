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
class IProyecto {
    public:
        virtual void crear(string nomb, string descrip) = 0;
        virtual void eliminar() = 0;
        virtual ~IProyecto(){};
};

class Usuario {
    protected:
        char id[20];
    private:
        string contra;
    public:
        Usuario(string id, string contra);
        void login(const char *id, string contra);
        void logout();
};
Usuario::Usuario(string _id, string _contra){
    strncpy(id, _id.c_str(), sizeof(id) - 1);
    this -> id[sizeof(id) - 1] = '\0';
    this->contra = _contra;
}
void Usuario::login(const char *id, string contra){
    if(strcmp(this->id, id) == 0 && this->contra == contra){
        cout << "Bienvenido " << this->id;
    }else{
        throw invalid_argument ("Usuario o contraseña incorrectos");
    }
}
void Usuario::logout(){
    cout << "Sesion cerrada";
}

class Archivo : public IProyecto{
    public:
        string nombre;
        string extension;
        string contenido;
        Archivo(string, string, string);
        void crear(string nomb, string descrip) override;
        void escribirContenido();
        void eliminar() override;
};

Archivo::Archivo(string _nombre, string _extension, string _contenido){
    this -> nombre = _nombre;
    this -> extension = _extension;
    this -> contenido = _contenido;
}

void Archivo::crear(string nomb, string descrip){
    cout << "Archivo creado: " << nomb << " Descripcion: " << descrip;
}

void Archivo::escribirContenido(){
    cout << "Escriba el contenido del archivo: ";
    getline(cin, this -> contenido);
    cout << "Contenido guardado";
}
void Archivo::eliminar(){
    cout << "Archivo eliminado";
}

class Proyecto : public IProyecto{
    protected:
        char nombre[50];
        string descripcion;
        vector<Archivo> archivos;
        chrono::system_clock::time_point fecha_entrega;
    public:
        Proyecto(string, string, vector<Archivo>* = nullptr, chrono::system_clock::time_point = chrono::system_clock::now());
        void crear(string nomb, string descrip) override;
        void setArchivoProyecto(Archivo archivo);
        void getFechaEntrega();
        void getArchivoProyecto();
        void eliminar() override;
};
Proyecto::Proyecto(string _nombre, string _descripcion, vector<Archivo> *_archivos, chrono::system_clock::time_point _fecha_entrega){
    strncpy(nombre, _nombre.c_str(), sizeof(nombre) - 1);
    this -> nombre[sizeof(nombre) - 1] = '\0';
    this -> descripcion = _descripcion;
    this -> archivos = *_archivos;
    this -> fecha_entrega = _fecha_entrega;
}
void Proyecto::crear(string nomb, string descrip){
    cout << "Proyecto creado: " << nomb << " Descripcion: " << descrip;
}
void Proyecto::setArchivoProyecto(Archivo archivo){
    this -> archivos.push_back(archivo);
    cout << "Archivo agregado";
}
void Proyecto::getFechaEntrega(){
    time_t tiempo = chrono::system_clock::to_time_t(fecha_entrega);
    struct tm *timeinfo = localtime(&tiempo);
    cout << "Fecha de entrega: " << put_time(timeinfo, "%B %dth, %I%p") << endl;
}
void Proyecto::getArchivoProyecto(){
    for(auto &archivo : archivos){
        cout << "Nombre: " << archivo.nombre << " Extension: " << archivo.extension << " Contenido: " << archivo.contenido << endl;
    }
}
void Proyecto::eliminar(){
    cout << "Proyecto eliminado";
}

int main(){
    time_t tiempo = chrono::system_clock::to_time_t(valida_fecha(1, 10, 10));
    struct tm *timeinfo = localtime(&tiempo);
    cout << "Fecha: " << put_time(timeinfo, "%B %dth, %I%p") << endl;

    int option;
    do {
        cout << "\nMenu:\n";
        cout << "1. Crear proyecto\n";
        cout << "2. Eliminar proyecto\n";
        cout << "3. Agregar archivo a proyecto\n";
        cout << "4. Ver fecha de entrega\n";
        cout << "5. Ver archivos de proyecto\n";
        cout << "6. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> option;
        cin.ignore();

        Usuario user("123456", "password");
        try {
            user.login("123456", "password");
            switch (option) {
                case 1:
                    // Call the function to create a project
                    break;
                case 2:
                    // Call the function to delete a project
                    break;
                case 3:
                    // Call the function to add a file to a project
                    break;
                case 4:
                    // Call the function to display the project's due date
                    break;
                case 5:
                    // Call the function to display the files in a project
                    break;
                case 6:
                    cout << "Saliendo del programa...\n";
                    break;
                default:
                    cout << "Opcion invalida. Intente de nuevo.\n";
            }
            user.logout();
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
        }
    } while (option != 6);

    return 0;
}

chrono::system_clock::time_point valida_fecha(int mes, int dia, int hora){
    tm tiempo ={};
    tiempo.tm_year = 2024 - 1900;   
    tiempo.tm_mon = mes - 1;
    tiempo.tm_mday = dia;
    tiempo.tm_hour = hora;
    time_t tiempo_t = mktime(&tiempo);
    if(tiempo_t == -1) throw invalid_argument("Fecha y tiempo inválidos");