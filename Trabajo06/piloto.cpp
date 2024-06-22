#include "dependencias/ifInt.h"
#include "dependencias/ifFloat.h"
#include "dependencias/getStr.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <ctime>
#include <exception>
#include <cstdlib>
#include <random>

using namespace std;

void addProduct();
void generalProductList();
int listLibros();
int listElectronicos();
int listRopas();
void menu();
void foundId();
int getFrequency(string);
void change();
void deleteClient();
void vender();
void web();
void aumentar();

class IProducto;
class Libro;
class Electronico;
class Ropa;

vector<IProducto*> general_products;
vector<Ropa*> ropas;
vector<Libro*> libros;
vector<Electronico*> electronicos;

class IProducto{
    protected:
        string id, nombre;
        int cantidad = 0;
        float precio;
        virtual void setData(){cout <<"Se guardo el producto"<<endl;}
        friend istream& operator>>(istream& in, IProducto& producto);
    public:
        string getNombre(){return nombre;}
        int getCantidad(){return cantidad;}
        void restarCantidad(int _cantidad){cantidad -= _cantidad;}
        void addCantidad(int _cantidad){cantidad += _cantidad;}
};
istream& operator>>(istream& in, IProducto& producto){
    cout << "Ingrese el nombre: ";
    in.ignore();
    getline(in, producto.nombre);
    cout << "Ingrese el precio: ";
    producto.precio = getInputFloat();
    cout << "Ingrese la cantidad: ";
    producto.cantidad = getInputInt();
    return in;
}

class Libro: public IProducto{
    public:
        char autor[100];
        Libro(string nombre, float precio, string _autor): IProducto(){
            this->nombre = nombre;
            this->precio = precio;
            strncpy(autor, _autor.c_str(), sizeof(autor));
            this -> autor[sizeof(autor) - 1] = '\0';
        }
        Libro(): IProducto(){
            int _id = listLibros();
            this -> id = "111" + string(10 - to_string(_id).size(), '0') + to_string(_id);
        }
        void setData() override {
            try{
                ofstream file("libros.csv", ios::app);
                if(!file.is_open()) {
                    throw ofstream::failure("No se puede abrir el archivo libros.csv");
                }
                file << id << ";" << nombre << ";" << precio << ";" << autor << ";" << cantidad << endl;
                file.close();
                IProducto::setData();
            }catch(exception &e){
                cout << "No se puede abrir el archivo" << endl;
            }
        }
        friend istream& operator>>(istream& in, Libro& libro);
};
istream& operator>>(istream& in, Libro& libro){
    in >> static_cast<IProducto&>(libro);
    cout << "Ingrese el autor: ";
    string _autor = getSTR(100);
    strncpy(libro.autor, _autor.c_str(), sizeof(libro.autor));
    libro.autor[sizeof(libro.autor) - 1] = '\0';
    return in;
}

class Electronico: public IProducto{
    public:
        char modelo[100];
        
        Electronico(string nombre, float precio, string _modelo): IProducto(){
            this->nombre = nombre;
            this->precio = precio;
            strncpy(modelo, _modelo.c_str(), sizeof(modelo));
            this -> modelo[sizeof(modelo) - 1] = '\0';
        }
        Electronico(): IProducto(){
            int _id = listElectronicos();
            this -> id = "222" + string(10 - to_string(_id).size(), '0') + to_string(_id);
        }
        void setData() override {
            try{
                ofstream file("electronicos.csv", ios::app);
                if(!file.is_open()) {
                    throw ofstream::failure("No se puede abrir el archivo electronicos.csv");
                }
                file << id << ";" << nombre << ";" << precio << ";" << modelo << ";" << cantidad << endl;
                file.close();
                IProducto::setData();
            }catch(exception &e){
                cout << "No se puede abrir el archivo" << endl;
            }
        }
        friend istream& operator>>(istream& in, Electronico& electronico);
};
istream& operator>>(istream& in, Electronico& electronico){
    in >> static_cast<IProducto&>(electronico);
    cout << "Ingrese el modelo: ";
    string _modelo = getSTR(100);
    strncpy(electronico.modelo, _modelo.c_str(), sizeof(electronico.modelo));
    electronico.modelo[sizeof(electronico.modelo) - 1] = '\0';
    return in;
}

class Ropa: public IProducto{
    public:
        char color[100];
        
        Ropa(string nombre, float precio, string _color): IProducto(){
            this->nombre = nombre;
            this->precio = precio;
            strncpy(color, _color.c_str(), sizeof(color));
            this -> color[sizeof(color) - 1] = '\0';
        }
        Ropa(): IProducto(){
            int _id = listRopas();
            this -> id = "333" + string(10 - to_string(_id).size(), '0') + to_string(_id);
        }
        void setData() override {
            try{
                ofstream file("ropas.csv", ios::app);
                if(!file.is_open()) {
                    throw ofstream::failure("No se puede abrir el archivo ropas.csv");
                }
                file << id << ";" << nombre << ";" << precio << ";" << color << ";" << cantidad << endl;
                file.close();
                IProducto::setData();
            }catch(exception &e){
                cout << "No se puede abrir el archivo" << endl;
            }
        }
        friend istream& operator>>(istream& in, Ropa& ropa);
};
istream& operator>>(istream& in, Ropa& ropa){
    in >> static_cast<IProducto&>(ropa);
    cout << "Ingrese el color: ";
    string _color = getSTR(100);
    strncpy(ropa.color, _color.c_str(), sizeof(ropa.color));
    ropa.color[sizeof(ropa.color) - 1] = '\0';
    return in;
}


bool aumentar(vector<IProducto*> &productos, string _nombre, int cantidad){
    for (IProducto* producto : productos){
        if (producto->getNombre() == _nombre) {
            producto->addCantidad(cantidad);
            return true;
        }
    }
    return false;
}

int main(){
    menu();
}

void addProduct(){
    cout << "Que tipo de producto quieres agregar?" << endl;
    cout << "1. Libro" << endl;
    cout << "2. Electronico" << endl;
    cout << "3. Ropa" << endl;
    short tipo = short(getInputInt());
    switch(tipo){
        case 1: {
            Libro* nuevoLibro = new Libro();
            cin >> *nuevoLibro;
            if (!aumentar(reinterpret_cast<vector<IProducto*>&>(libros), nuevoLibro->getNombre(), nuevoLibro->getCantidad())) {
                libros.push_back(nuevoLibro);
                nuevoLibro->setData();
            } else {
                delete nuevoLibro;
            }
            break;
        }
        case 2: {
            Electronico* nuevoElectronico = new Electronico();
            cin >> *nuevoElectronico;
            if (!aumentar(reinterpret_cast<vector<IProducto*>&>(electronicos), nuevoElectronico->getNombre(), nuevoElectronico->getCantidad())) {
                electronicos.push_back(nuevoElectronico);
                nuevoElectronico->setData();
            } else {
                delete nuevoElectronico;
            }
            break;
        }
        case 3: {
            Ropa* nuevaRopa = new Ropa();
            cin >> *nuevaRopa;
            if (!aumentar(reinterpret_cast<vector<IProducto*>&>(ropas), nuevaRopa->getNombre(), nuevaRopa->getCantidad())) {
                ropas.push_back(nuevaRopa);
                nuevaRopa->setData();
            } else {
                delete nuevaRopa;
            }
            break;
        }
    }
}

void generalProductList(){
    cout << "°°°°°°°°°°°°°°°°°°°°" << endl;
    cout << "Listado de productos" << endl;
    cout << "°°°°°°°°°°°°°°°°°°°°" << endl;
    listLibros();
    listElectronicos();
    listRopas();
}

int listLibros(){
    cout << "==============Libros" << endl;
    try{
        ifstream file("libros.csv", ios::in);
        if(!file.is_open()) {
            throw ifstream::failure("No se puede abrir el archivo libros.csv");
        }
        string linea, id, nombre, precio, autor, cantidad;
        int cont = 1;
        while(getline(file, linea)){
            stringstream token(linea);
            getline(token, id, ';');
            getline(token, nombre, ';');
            getline(token, precio, ';');
            getline(token, autor, ';');
            getline(token, cantidad, ';');
            cout << "libro N°" << cont << " :" << endl;
            cout << "Id: " << id << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Precio: " << precio << endl;
            cout << "Autor: " << autor << endl;
            cout << "Cantidad: " << cantidad << endl;
            cout << endl;
            cont++;
        }
        file.close();
        return cont;
    } catch(exception &e){
        cout << "Fin de ejecución" << endl;
        return 0;
    }
}
int listElectronicos(){
    cout << "==============Electronicos" << endl;
    try{
        ifstream file("electronicos.csv", ios::in);
        if(!file.is_open()) {
            throw ifstream::failure("No se puede abrir el archivo electronicos.csv");
        }
        string linea, id, nombre, precio, modelo, cantidad;
        int cont = 1;
        while(getline(file, linea)){
            stringstream token(linea);
            getline(token, id, ';');
            getline(token, nombre, ';');
            getline(token, precio, ';');
            getline(token, modelo, ';');
            getline(token, cantidad, ';');
            cout << "electronico N°" << cont << " :" << endl;
            cout << "Id: " << id << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Precio: " << precio << endl;
            cout << "Modelo: " << modelo << endl;
            cout << "Cantidad: " << cantidad << endl;
            cout << endl;
            cont++;
        }
        file.close();
        return cont;
    } catch(exception &e){
        cout << "Fin de ejecución" << endl;
        return 0;
    }
}
int listRopas(){
    cout << "==============Ropas" << endl;
    try{
        ifstream file("ropas.csv", ios::in);
        if(!file.is_open()) {
            throw ifstream::failure("No se puede abrir el archivo ropas.csv");
        }
        string linea, id, nombre, precio, color, cantidad;
        int cont = 1;
        while(getline(file, linea)){
            stringstream token(linea);
            getline(token, id, ';');
            getline(token, nombre, ';');
            getline(token, precio, ';');
            getline(token, color, ';');
            getline(token, cantidad, ';');
            cout << "ropa N°" << cont << " :" << endl;
            cout << "Id: " << id << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Precio: " << precio << endl;
            cout << "Color: " << color << endl;
            cout << "Cantidad: " << cantidad << endl;
            cout << endl;
            cont++;
        }
        file.close();
        return cont;
    } catch(exception &e){
        cout << "Fin de ejecución" << endl;
        return 0;
    }
}

void restar(vector<IProducto*> &productos) {
    cout << "Ingrese el nombre del producto: ";
    string nombre = getSTR(100);
    cout << "Ingrese la cantidad a restar: ";
    int cantidad = getInputInt();

    for (auto producto : productos) {
        if (producto->getNombre() == nombre) {
            if (producto->getCantidad() >= cantidad && cantidad > 0) {
                producto->restarCantidad(cantidad);
                cout << "Cantidad restada exitosamente." << endl;
                return;
            } else {
                cout << "No hay suficiente cantidad para restar." << endl;
                return;
            }
        }
    }
    cout << "Producto no encontrado." << endl;
}


void menu(){
    short opcion;
    do{
        cout << "1. Agregar producto" << endl;
        cout << "2. Listar productos" << endl;
        cout << "9. Lista en .html" << endl;
        cout << "3. Cambiar datos" << endl;
        cout << "4. Borrar cliente" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opción: ";
        opcion = short(getInputInt());
        switch(opcion){
            case 1:
                addProduct();
                break;
            case 2:{
                char op2;
                cout << "       [G] Lista general" << endl;
                cout << "       [L] Lista libros" << endl;
                cout << "       [E] Lista electronicos" << endl;
                cout << "       [R] Lista ropas" << endl;
                cout << "       [S] Salir" << endl;
                cout << "Ingrese una opción: ";
                cin >> op2;
                switch(toupper(op2)) {
                    case 'G':
                        generalProductList();
                        break;
                    case 'L':
                        listLibros();
                        break;
                    case 'E':
                        listElectronicos();
                        break;
                    case 'R':
                        listRopas();
                        break;
                    case 'S':
                        break;
                    default:
                        cout << "Opción no válida" << endl;
                }
                break;
            }
            case 4: 
                restar(reinterpret_cast<vector<IProducto*>&>(general_products));
            case 5:
                cout << "Saliendo..." << endl;
                break;
            case 9:
                web();
                break;
            default:
                cout << "Opción no válida" << endl;
                break;
        }
    }while(opcion != 5);
}

void web(){
    ofstream web("productos_web.html");
    web << "<html><head><title>LISTADO DE PRODUCTOS</title></head><body>" << endl;
    web << "<h2>Lista:</h2><br>" << endl;
    web << "<table border='1'>" << endl;
    web << "<tr>" << endl;
    web << "<th>Numero de ID</th>" << endl;
    web << "<th>Nombre</th>" << endl;
    web << "<th>Precio</th>" << endl;
    web << "<th>Autor/Modelo/Color</th>" << endl;
    web << "<th>Cantidad</th>" << endl;
    web << "</tr>" << endl;

    ifstream file("libros.csv");
    if (file.is_open()) {
        string linea, id, nombre, precio, autor, cantidad;
        while (getline(file, linea)) {
            stringstream token(linea);
            getline(token, id, ';');
            getline(token, nombre, ';');
            getline(token, precio, ';');
            getline(token, autor, ';');
            getline(token, cantidad, ';');
            web << "<tr>" << endl;
            web << "<td>" << id << "</td>" << endl;
            web << "<td>" << nombre << "</td>" << endl;
            web << "<td>" << precio << "</td>" << endl;
            web << "<td>" << autor << "</td>" << endl;
            web << "<td>" << cantidad << "</td>" << endl;
            web << "</tr>" << endl;
        }
        file.close();
    }

    file.open("electronicos.csv");
    if (file.is_open()) {
        string linea, id, nombre, precio, modelo, cantidad;
        while (getline(file, linea)) {
            stringstream token(linea);
            getline(token, id, ';');
            getline(token, nombre, ';');
            getline(token, precio, ';');
            getline(token, modelo, ';');
            getline(token, cantidad, ';');
            web << "<tr>" << endl;
            web << "<td>" << id << "</td>" << endl;
            web << "<td>" << nombre << "</td>" << endl;
            web << "<td>" << precio << "</td>" << endl;
            web << "<td>" << modelo << "</td>" << endl;
            web << "<td>" << cantidad << "</td>" << endl;
            web << "</tr>" << endl;
        }
        file.close();
    }

    file.open("ropas.csv");
    if (file.is_open()) {
        string linea, id, nombre, precio, color, cantidad;
        while (getline(file, linea)) {
            stringstream token(linea);
            getline(token, id, ';');
            getline(token, nombre, ';');
            getline(token, precio, ';');
            getline(token, color, ';');
            getline(token, cantidad, ';');
            web << "<tr>" << endl;
            web << "<td>" << id << "</td>" << endl;
            web << "<td>" << nombre << "</td>" << endl;
            web << "<td>" << precio << "</td>" << endl;
            web << "<td>" << color << "</td>" << endl;
            web << "<td>" << cantidad << "</td>" << endl;
            web << "</tr>" << endl;
        }
        file.close();
    }

    web << "</table></body></html>" << endl;
    web.close();
}

void aumentar(){
    cout << "Ingrese el nombre del producto: ";
    string nombre = getSTR(100);
    cout << "Ingrese la cantidad a aumentar: ";
    int cantidad = getInputInt();

    if (!aumentar(general_products, nombre, cantidad)) {
        cout << "Producto no encontrado." << endl;
    } else {
        cout << "Cantidad aumentada." << endl;
    }
}
