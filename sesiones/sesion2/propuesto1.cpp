#include <iostream>
#include <limits>
#include <cstring>
using namespace std;

class Animales{
    protected:
        char nombre[20];

    private:
        string edad;
    public:
        Animales(string, string edad_inicial = "Desconocido");
        virtual void hacerSonido();
        void setNombre(char nombre_nuevo[20]){strncpy(nombre, nombre_nuevo, sizeof(nombre));}
        char* getNombre(){return nombre;}
        void setEdad(string edad_nuevo){this -> edad = edad_nuevo;}
        string getEdad(){return edad;}
};
Animales::Animales(string nombre_inicial, string edad_inicial){
    strncpy(nombre, nombre_inicial.c_str(), sizeof(nombre));
    this -> nombre[sizeof(nombre) - 1] = '\0';
    this -> edad = edad_inicial;
}
void Animales :: hacerSonido(){
    cout << "El animal hizo un sonido raro y genérico";
}

class Mamiferos : public Animales {
    protected:
        string tipo_pelo;
    public:
        Mamiferos(string, string, string);
        void hacerSonido() override{
            cout << "El mamífero hizo un sonido de mamifero raro y genérico";
        }
        void setTipoPelo(string tipo_pelo_nuevo) { tipo_pelo = tipo_pelo_nuevo; }
        string getTipoPelo() { return tipo_pelo; }
};
Mamiferos::Mamiferos(string nombre_inicial, string edad_inicial, string tipo_pelo_inicial) : Animales(nombre_inicial, edad_inicial) {
    tipo_pelo = tipo_pelo_inicial;
}

class Reptiles : public Animales {
    protected:
        string tipo_escamas;
    public:
        Reptiles(string, string, string);
        void hacerSonido() override{
            cout << "El reptil hizo un sonido de reptil raro y genérico";
        }
        void setTipoEscamas(string tipo_escamas_nuevo) { tipo_escamas = tipo_escamas_nuevo; }
        string getTipoEscamas() { return tipo_escamas; }
};
Reptiles::Reptiles(string nombre_inicial, string edad_inicial, string tipo_escamas_inicial) : Animales(nombre_inicial, edad_inicial) {
    this -> tipo_escamas = tipo_escamas_inicial;
}

class Aves : public Animales {
    protected:
        string tipo_plumaje;
    public:
        Aves(string, string, string);
        void hacerSonido() override{
            cout << "El ave hizo un sonido de ave raro y genérico";
        }
        void setTipoPlumaje(string tipo_plumaje_nuevo) { tipo_plumaje = tipo_plumaje_nuevo; }
        string getTipoPlumaje() { return tipo_plumaje; }
};

Aves::Aves(string nombre_inicial, string edad_inicial, string tipo_plumaje_inicial) : Animales(nombre_inicial, edad_inicial) {
    this -> tipo_plumaje = tipo_plumaje_inicial;
}

class Perros : public Mamiferos {
    private:
        string raza;
    public:
        Perros(string, string, string, string);
        void hacerSonido() override{
            cout << "El perro hizo un sonido de perro raro y genérico";
        }
        void setRaza(string raza_nueva) { raza = raza_nueva; }
        string getRaza() { return raza; }
};

Perros::Perros(string nombre_inicial, string edad_inicial, string tipo_pelo_inicial, string raza_inicial) : Mamiferos(nombre_inicial, edad_inicial, tipo_pelo_inicial) {
    this -> raza = raza_inicial;
}

class Lagartijas : public Reptiles {
    private:
        string color;
    public:
        Lagartijas(string, string, string, string);
        void hacerSonido() override{
            cout << "La lagartija hizo un sonido de lagartija raro y genérico";
        }
        void setColor(string color_nuevo) { color = color_nuevo; }
        string getColor() { return color; }
};

Lagartijas::Lagartijas(string nombre_inicial, string edad_inicial, string tipo_escamas_inicial, string color_inicial) : Reptiles(nombre_inicial, edad_inicial, tipo_escamas_inicial) {
    this -> color = color_inicial;
}

class Canarios : public Aves {
    private:
        string color;
    public:
        Canarios(string, string, string, string);
        void hacerSonido() override{
            cout << "El canario hizo un sonido de canario raro y genérico";
        }
        void setColor(string color_nuevo) { color = color_nuevo; }
        string getColor() { return color; }
};

Canarios::Canarios(string nombre_inicial, string edad_inicial, string tipo_plumaje_inicial, string color_inicial) : Aves(nombre_inicial, edad_inicial, tipo_plumaje_inicial) {
    this -> color = color_inicial;
}


int main(){
    char nombre[20];
    int edad;
    cout << "Ingrese la edad del animal: ";
    cin >> edad;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Ingrese el nombre del animal: ";
    cin.getline(nombre, 20);
    Animales perro(nombre, to_string(edad));
    cout << "El animal se llama: " << perro.getNombre() << endl;
    cout << perro.getEdad();
}