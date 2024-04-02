#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using namespace std;

// Definimos clase Persona
class Persona {
private:
    string nombre;
    int edad;
    string genero;

public:
    Persona(string n, int e, string g);
    
    string getNombre();
    void setNombre(string n);

    int getEdad();
    void setEdad(int e);

    string getGenero();
    void setGenero(string g);
};

#endif
