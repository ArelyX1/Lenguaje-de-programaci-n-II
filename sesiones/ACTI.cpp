#include <iostream>
#include "persona.h"
using namespace std;

int main() {
    Persona persona1("Juan", 30, "Masculino");
    Persona persona2("Maria", 25, "Femenino");

    cout<<"Datos de la Persona 1:"<<endl;
    cout<<"Nombre: "<<persona1.getNombre()<<endl;
    cout<<"Edad: "<<persona1.getEdad()<<" years"<<endl;
    cout<<"Genero: "<<persona1.getGenero()<<endl;

    cout<<"\nDatos de la Persona 2:"<<endl;
    cout<<"Nombre: "<<persona2.getNombre()<<endl;
    cout<<"Edad: "<<persona2.getEdad()<<" years"<<endl;
    cout<<"Género: "<<persona2.getGenero()<<endl;

    return 0;
}





#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using namespace std;

//Definimos clase Persona
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
