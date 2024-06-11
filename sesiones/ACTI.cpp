#include "dependencias/ifInt.h"
#include "dependencias/ifFloat.h"
#include "dependencias/getStr.h"
#include "dependencias/sha256.h"

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
void listLibros();
void listElectronicos();
void listRopas();
void menu();
void foundId();
int getFrequency(string);
void change();
void deleteClient();

class IProducto{
    protected:
        string id;
        string nombre;
        float precio;
        virtual void setData(){cout <<"Se guardo el producto"<<endl;}
        friend istream& operator>>(istream& in, IProducto& producto);
};
istream& operator>>(istream& in, IProducto& producto){
    cout << "Ingrese el nombre: ";
    in.ignore();
    getline(in, producto.nombre);
    cout << "Ingrese el precio: ";
    float precio = getInputFloat();
    producto.precio = precio;
    return in;
}

class Libro: public IProducto{
    public:
        char autor[100];
        static int contador;
        Libro(string nombre, float precio, string _autor): IProducto(){
            this->nombre = nombre;
            this->precio = precio;
            strncpy(autor, _autor.c_str(), sizeof(autor));
            this -> autor[sizeof(autor) - 1] = '\0';
        }
        Libro(): IProducto(){
            contador++;
            this -> id = "111" + to_string(contador);
        }
        void setData(){
            try{
                ofstream file("libros.csv", ios::app);
                if(!file.is_open()) {
                    throw ofstream::failure("No se puede abrir el archivo clientes.csv");
                }
                file.exceptions(ofstream::failbit | ofstream::badbit);
                file << id << ";" << nombre << ";" << precio << ";" << autor << endl;
                file.close();
                IProducto::setData();
            }catch(exception e){
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
        static int contador;
        char modelo[100];
        
        Electronico(string nombre, float precio, string _modelo): IProducto(){
            this->nombre = nombre;
            this->precio = precio;
            strncpy(modelo, _modelo.c_str(), sizeof(modelo));
            this -> modelo[sizeof(modelo) - 1] = '\0';
        }
        Electronico(): IProducto(){
            contador++;
            this -> id = "222" + to_string(contador);
        }
        void setData(){
            try{
                ofstream file("electronicos.csv", ios::app);
                if(!file.is_open()) {
                    throw ofstream::failure("No se puede abrir el archivo clientes.csv");
                }
                file.exceptions(ofstream::failbit | ofstream::badbit);
                file << id << ";" << nombre << ";" << precio << ";" << modelo << endl;
                file.close();
                IProducto::setData();
            }catch(exception e){
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
        static int contador;
        
        Ropa(string nombre, float precio, string _color): IProducto(){
            this->nombre = nombre;
            this->precio = precio;
            strncpy(color, _color.c_str(), sizeof(color));
            this -> color[sizeof(color) - 1] = '\0';
        }
        Ropa(): IProducto(){
            contador++;
            this -> id = "333" + to_string(contador);
        }
        void setData(){
            try{
                ofstream file("ropas.csv", ios::app);
                if(!file.is_open()) {
                    throw ofstream::failure("No se puede abrir el archivo clientes.csv");
                }
                file.exceptions(ofstream::failbit | ofstream::badbit);
                file << id << ";" << nombre << ";" << precio << ";" << color << endl;
                file.close();
                IProducto::setData();
            }catch(exception e){
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

int Libro::contador = 0;
int Electronico::contador = 0;
int Ropa::contador = 0;

vector<IProducto*> general_products;
vector<Ropa*> ropas;
vector<Libro*> libros;
vector<Electronico*> electronicos;
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
        case 1:
            libros.push_back(new Libro());
            cin >> *libros.back();
            libros.back() -> setData();
            break;
        case 2:
            electronicos.push_back(new Electronico());
            cin >> *electronicos.back();
            electronicos.back() -> setData();
            break;
        case 3:
            ropas.push_back(new Ropa());
            cin >> *ropas.back();
            ropas.back() -> setData();
            break;
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

void listLibros(){
    cout << "==============Libros" << endl;
    try{
        ifstream file("libros.csv", ios::in);
        if(!file.is_open()) {
            throw ofstream::failure("No se puede abrir el archivo libros.csv");
        }
        file.exceptions(ofstream::failbit | ofstream::badbit);
        string linea, id, nombre, precio, autor;
        int cont = 0;
        while(getline(file, linea)){
            stringstream token(linea);
            getline(token, id, ';');
            getline(token, nombre, ';');
            getline(token, precio, ';');
            getline(token, autor, ';');
            cout << "libro N°" << ++cont << " :" << endl;
            cout << "Id: " << id << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Precio: " << precio << endl;
            cout << "Autor: " << autor << endl;
            cout << endl;
        }
        file.close();
    } catch(exception e){
        cout << "Fin de ejecución" << endl;
    }
}
void listElectronicos(){
    cout << "==============Electronicos" << endl;
    try{
        ifstream file("electronicos.csv", ios::in);
        if(!file.is_open()) {
            throw ofstream::failure("No se puede abrir el archivo electronicos.csv");
        }
        file.exceptions(ofstream::failbit | ofstream::badbit);
        string linea, id, nombre, precio, modelo;
        int cont = 0;
        while(getline(file, linea)){
            stringstream token(linea);
            getline(token, id, ';');
            getline(token, nombre, ';');
            getline(token, precio, ';');
            getline(token, modelo, ';');
            cout << "electronico N°" << ++cont << " :" << endl;
            cout << "Id: " << id << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Precio: " << precio << endl;
            cout << "Modelo: " << modelo << endl;
            cout << endl;
        }
        file.close();
    } catch(exception e){
        cout << "Fin de ejecución" << endl;
    }
}
void listRopas(){
    cout << "==============Ropas" << endl;
    try{
        ifstream file("ropas.csv", ios::in);
        if(!file.is_open()) {
            throw ofstream::failure("No se puede abrir el archivo ropas.csv");
        }
        file.exceptions(ofstream::failbit | ofstream::badbit);
        string linea, id, nombre, precio, color;
        int cont = 0;
        while(getline(file, linea)){
            stringstream token(linea);
            getline(token, id, ';');
            getline(token, nombre, ';');
            getline(token, precio, ';');
            getline(token, color, ';');
            cout << "ropa N°" << ++cont << " :" << endl;
            cout << "Id: " << id << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Precio: " << precio << endl;
            cout << "Color: " << color << endl;
            cout << endl;
        }
        file.close();
    } catch(exception e){
        cout << "Fin de ejecución" << endl;
    }
}

void menu(){
    short opcion;
    do{
        cout << "1. Agregar producto" << endl;
        cout << "2. Listar productos" << endl;
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
                map<char, void(*)(void)> opciones = {
                    {'G', generalProductList},
                    {'L', listLibros},
                    {'E', listElectronicos},
                    {'R', listRopas},
                    {'S', menu}
                };
                cout << "       [G] Lista general" << endl;
                cout << "       [L] Lista libros" << endl;
                cout << "       [E] Lista electronicos" << endl;
                cout << "       [R] Lista ropas" << endl;
                cout << "       [S] Salir" << endl;
                cout << "Ingrese una opción: ";
                cin >> op2;
                (opciones.find(toupper(op2)) != opciones.end()) ? opciones[toupper(op2)]() : [](){cout << "Opción no válida" << endl;}();
                break;
            }
            case 5:
                cout << "Saliendo..." << endl;
                break;
        }
    }while(opcion != 5);
}
