#include "validaciones/validaNum.h"
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

void buscarLibro();
void crearArchivo();
void registrarUsuario();
void prestarLibro();
void devolverLibro();
void generarInformes();
void agregarLibro();

class Libro {
public:
    string titulo, autor, isbn, genero;
    int anio;
    bool disponibilidad;
    Libro(string _titulo, string _autor, string _isbn, string _genero, int _anio, bool _disponibilidad) : 
        titulo(_titulo), autor(_autor), isbn(_isbn), genero(_genero), anio(_anio), disponibilidad(_disponibilidad) {}
};

class Usuario {
public:
    string nombre, ID, tipo_usr;
    vector<Libro*> libros_pedidos;
    Usuario(string _nombre, string _ID, string _tipo_usr) :
        nombre(_nombre), ID(_ID), tipo_usr(_tipo_usr) {}
};

vector<Libro*> libros;
vector<Usuario*> usuarios;

int main() {
    int opcion;
    do {
        cout << "1. Buscar libro" << endl;
        cout << "2. Registrar usuario" << endl;
        cout << "3. Prestar libro" << endl;
        cout << "4. Devolver libro" << endl;
        cout << "5. Generar informes" << endl;
        cout << "6. Agregar libro" << endl;
        cout << "7. Salir" << endl;
        opcion = getValidaNum<int>();

        switch (opcion) {
            case 1: buscarLibro(); break;
            case 2: registrarUsuario(); break;
            case 3: prestarLibro(); break;
            case 4: devolverLibro(); break;
            case 5: generarInformes(); break;
            case 6: agregarLibro(); break;
            case 7: cout << "Saliendo del sistema..." << endl; break;
            default: cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while (opcion != 7);

    return 0;
}

void buscarLibro() {
    string criterio;
    cout << "Ingrese el criterio de búsqueda (título, autor, ISBN o género): ";
    cin >> criterio;

    cout << "Resultados de la búsqueda:" << endl;
    for (Libro* libro : libros) {
        if (libro->titulo.find(criterio) != string::npos ||
            libro->autor.find(criterio) != string::npos ||
            libro->isbn.find(criterio) != string::npos ||
            libro->genero.find(criterio) != string::npos) {
            cout << "Título: " << libro->titulo << ", Autor: " << libro->autor << ", ISBN: " << libro->isbn << ", Género: " << libro->genero << ", Año: " << libro->anio << ", Disponibilidad: " << (libro->disponibilidad ? "Sí" : "No") << endl;
        }
    }
}

void registrarUsuario() {
    string nombre, ID, tipo_usr;
    cout << "Ingrese el nombre del usuario: ";
    cin >> nombre;
    cout << "Ingrese el ID del usuario: ";
    cin >> ID;
    cout << "Ingrese el tipo de usuario (estudiante, profesor o investigador): ";
    cin >> tipo_usr;

    Usuario* nuevoUsuario = new Usuario(nombre, ID, tipo_usr);
    usuarios.push_back(nuevoUsuario);
    cout << "Usuario registrado exitosamente." << endl;
}

void prestarLibro() {
    string isbn;
    string ID;
    cout << "Ingrese el ISBN del libro a prestar: ";
    isbn = getValidaNum<string>();
    cout << "Ingrese el ID del usuario que solicita el préstamo: ";
    ID = getValidaNum<string>();

    Libro* libroAPrestar = nullptr;
    Usuario* usuarioSolicitante = nullptr;

    for (Libro* libro : libros) {
        if (libro->isbn == isbn && libro->disponibilidad) {
            libroAPrestar = libro;
            break;
        }
    }

    for (Usuario* usuario : usuarios) {
        if (usuario->ID == ID) {
            usuarioSolicitante = usuario;
            break;
        }
    }

    if (libroAPrestar && usuarioSolicitante) {
        libroAPrestar->disponibilidad = false;
        usuarioSolicitante->libros_pedidos.push_back(libroAPrestar);
        cout << "Préstamo realizado exitosamente." << endl;
    } else {
        cout << "No se pudo realizar el préstamo. Verifique que el libro esté disponible y que el usuario exista." << endl;
    }
}

void devolverLibro() {
    string isbn;
    string ID;
    cout << "Ingrese el ISBN del libro a devolver: ";
    isbn = getValidaNum<string>();
    cout << "Ingrese el ID del usuario que devuelve el libro: ";
    ID = getValidaNum<string>();

    Libro* libroADevolver = nullptr;
    Usuario* usuarioDevolviendo = nullptr;

    for (Libro* libro : libros) {
        if (libro->isbn == isbn && !libro->disponibilidad) {
            libroADevolver = libro;
            break;
        }
    }

    for (Usuario* usuario : usuarios) {
        if (usuario->ID == ID) {
            usuarioDevolviendo = usuario;
            break;
        }
    }

    if (libroADevolver && usuarioDevolviendo) {
        libroADevolver->disponibilidad = true;
        auto it = find(usuarioDevolviendo->libros_pedidos.begin(), usuarioDevolviendo->libros_pedidos.end(), libroADevolver);
        if (it != usuarioDevolviendo->libros_pedidos.end()) {
            usuarioDevolviendo->libros_pedidos.erase(it);
        }
        cout << "Devolución realizada exitosamente." << endl;
    } else {
        cout << "No se pudo realizar la devolución. Verifique que el libro esté prestado y que el usuario exista." << endl;
    }
}

void generarInformes() {
    // Generar informe de libros más populares
    map<string, int> librosPrestados;
    for (Usuario* usuario : usuarios) {
        for (Libro* libro : usuario->libros_pedidos) {
            librosPrestados[libro->isbn]++;
        }
    }

    cout << "Informe de libros más populares:" << endl;
    vector<pair<int, string>> librosOrdenados;
    for (auto& par : librosPrestados) {
        librosOrdenados.emplace_back(-par.second, par.first);
    }
    sort(librosOrdenados.begin(), librosOrdenados.end());
    for (auto& par : librosOrdenados) {
        for (Libro* libro : libros) {
            if (libro->isbn == par.second) {
                cout << "Título: " << libro->titulo << ", Autor: " << libro->autor << ", ISBN: " << libro->isbn << ", Préstamos: " << -par.first << endl;
                break;
            }
        }
    }

    // Generar informe de usuarios más activos
    map<string, int> usuariosActivos;
    for (Usuario* usuario : usuarios) {
        usuariosActivos[usuario->ID] = usuario->libros_pedidos.size();
    }

    cout << "Informe de usuarios más activos:" << endl;
    vector<pair<int, string>> usuariosOrdenados;
    for (auto& par : usuariosActivos) {
        usuariosOrdenados.emplace_back(-par.second, par.first);
    }
    sort(usuariosOrdenados.begin(), usuariosOrdenados.end());
    for (auto& par : usuariosOrdenados) {
        for (Usuario* usuario : usuarios) {
            if (usuario->ID == par.second) {
                cout << "Nombre: " << usuario->nombre << ", ID: " << usuario->ID << ", Tipo: " << usuario->tipo_usr << ", Préstamos: " << -par.first << endl;
                break;
            }
        }
    }

    // Generar informe en formato CSV
    ofstream csvFile("informe.csv");
    if (csvFile.is_open()) {
        csvFile << "Título,Autor,ISBN,Préstamos" << endl;
        for (auto& par : librosOrdenados) {
            for (Libro* libro : libros) {
                if (libro->isbn == par.second) {
                    csvFile << libro->titulo << "," << libro->autor << "," << libro->isbn << "," << -par.first << endl;
                    break;
                }
            }
        }
        csvFile << endl << "Nombre,ID,Tipo,Préstamos" << endl;
        for (auto& par : usuariosOrdenados) {
            for (Usuario* usuario : usuarios) {
                if (usuario->ID == par.second) {
                    csvFile << usuario->nombre << "," << usuario->ID << "," << usuario->tipo_usr << "," << -par.first << endl;
                    break;
                }
            }
        }
        csvFile.close();
        cout << "Informe generado en el archivo 'informe.csv'." << endl;
    } else {
        cout << "Error al crear el archivo 'informe.csv'." << endl;
    }
}

void agregarLibro() {
    string titulo, autor, isbn, genero;
    int anio;
    cout << "Ingrese el título del libro: ";
    cin >> titulo;
    cout << "Ingrese el autor del libro: ";
    cin >> autor;
    cout << "Ingrese el ISBN del libro: ";
    isbn = getValidaNum<string>();
    cout << "Ingrese el género del libro: ";
    cin >> genero;
    cout << "Ingrese el año de publicación del libro: ";
    anio = getValidaNum<int>();

    Libro* nuevoLibro = new Libro(titulo, autor, isbn, genero, anio, true);
    libros.push_back(nuevoLibro);

    // Guardar el libro en el archivo CSV
    ofstream csvFile("libros.csv", ios::app);
    if (csvFile.is_open()) {
        csvFile << titulo << "," << autor << "," << isbn << "," << genero << "," << anio << "," << "true" << endl;
        csvFile.close();
        cout << "Libro agregado exitosamente." << endl;
    } else {
        cout << "Error al crear el archivo 'libros.csv'." << endl;
    }
}

void crearArchivo() {
    try {
        ofstream archivo("Usuarios.csv");
        if (!archivo.is_open()) {
            throw runtime_error("Error al abrir el archivo");
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
}
