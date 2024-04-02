#include <iostream>
#include <string>
using namespace std;

class Libro {
    private:
        string titulo;
        string autor;
        string genero;
    public:
        Libro(string titulo, string autor, string genero) : titulo(titulo), autor(autor), genero(genero) {}

        // Métodos get
        string getTitulo() { return titulo; }
        string getAutor() { return autor; }
        string getGenero() { return genero; }

        // Métodos set
        void setTitulo(string nuevoTitulo) { titulo = nuevoTitulo; }
        void setAutor(string nuevoAutor) { autor = nuevoAutor; }
        void setGenero(string nuevoGenero) { genero = nuevoGenero; }
};

int main() {
    // Crear algunos libros
    Libro libro1("1984", "George Orwell", "Novela distópica");
    Libro libro2("Cien años de soledad", "Gabriel García Márquez", "Realismo mágico");

    // Imprimir información sobre los libros
    cout << "Libro 1: " << libro1.getTitulo() << ", " << libro1.getAutor() << ", " << libro1.getGenero() << endl;
    cout << "Libro 2: " << libro2.getTitulo() << ", " << libro2.getAutor() << ", " << libro2.getGenero() << endl;

    // Cambiar y imprimir la información de un libro
    libro1.setTitulo("Rebelión en la granja");
    libro1.setAutor("George Orwell");
    libro1.setGenero("Novela política");
    cout << "Libro 1 (actualizado): " << libro1.getTitulo() << ", " << libro1.getAutor() << ", " << libro1.getGenero() << endl;
    
}