#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void menu();
void menu_metodos();

class Animales {
protected:
    char nombre[20];
    string edad;

public:
    Animales(string nombre_inicial, string edad_inicial = "Desconocido");
    virtual void hacerSonido();
    void setNombre(char nombre_nuevo[20]) { strncpy(nombre, nombre_nuevo, sizeof(nombre)); }
    char* getNombre() { return nombre; } // Corregido para devolver un puntero a char
    void setEdad(string edad_nuevo) { edad = edad_nuevo; }
    string getEdad() { return edad; }
};

Animales::Animales(string nombre_inicial, string edad_inicial /*= "Desconocido"*/) {
    strncpy(nombre, nombre_inicial.c_str(), sizeof(nombre));
    nombre[sizeof(nombre) - 1] = '\0';
    edad = edad_inicial;
}

void Animales::hacerSonido() {
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
    this -> tipo_pelo = tipo_pelo_inicial;
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

int main() {
    char nombre[20];
    do{
        cout << "Ingrese el nombre del animal: ";
        cin.getline(nombre, 20);
    } while(strlen(nombre) == 0);
    Animales perro(nombre);
    cout << perro.getEdad();
    cout << perro.getNombre() << endl;
    perro.hacerSonido();
    
    Mamiferos gato("Gato", "2", "Corto");
    cout << gato.getNombre() << endl;
    cout << gato.getEdad() << endl;
    cout << gato.getTipoPelo() << endl;
    gato.hacerSonido();

    do{
        int opcion;
        menu();
        cout << "Ingrese una opción: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        
            break;
        
        default:
            break;
        }
    }while();
}

void menu(){
    cout << "1. Crear un animal" << endl;
    cout << "2. Crear un mamífero" << endl;
    cout << "3. Crear un reptil" << endl;
    cout << "4. Crear un ave" << endl;
    cout << "5. Crear un perro" << endl;
    cout << "6. Crear una lagartija" << endl;
    cout << "7. Crear un canario" << endl;
    cout << "8. Salir" << endl;
}

void menu_metodos(){
    cout << "1. Hacer sonido" << endl;
    cout << "2. Cambiar nombre" << endl;
    cout << "3. Cambiar edad" << endl;
    cout << "4. Cambiar tipo de pelo" << endl;
    cout << "5. Cambiar tipo de escamas" << endl;
    cout << "6. Cambiar tipo de plumaje" << endl;
    cout << "7. Cambiar raza" << endl;
    cout << "8. Cambiar color" << endl;
    cout << "9. Salir" << endl;
}