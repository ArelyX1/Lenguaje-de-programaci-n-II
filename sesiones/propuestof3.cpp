#include <iostream>
#include <string>

using namespace std;

class Avion {
private:
    string modelo;
    int capacidad_combustible;
    int combustible_actual;
    bool en_vuelo;

public:
    Avion(string _modelo, int _capacidad_combustible) : modelo(_modelo), capacidad_combustible(_capacidad_combustible), combustible_actual(_capacidad_combustible), en_vuelo(false) {}

    void despegar() {
        if (!en_vuelo) {
            en_vuelo = true;
            cout << "El avión " << modelo << " ha despegado." << endl;
        } else {
            cout << "El avión ya está en vuelo." << endl;
        }
    }

    void aterrizar() {
        if (en_vuelo) {
            en_vuelo = false;
            cout << "El avión " << modelo << " ha aterrizado." << endl;
        } else {
            cout << "El avión ya está en tierra." << endl;
        }
    }

    void verificar_combustible(int distancia_recorrida) {
        int combustible_necesario = distancia_recorrida * 10; 
        if (combustible_actual >= combustible_necesario) {
            cout << "El avión tiene suficiente combustible para completar la misión." << endl;
        } else {
            cout << "El avión no tiene suficiente combustible para completar la misión." << endl;
        }
    }

    void cargar_combustible(int cantidad) {
        combustible_actual += cantidad;
        cout << "Se han cargado " << cantidad << " unidades de combustible. Combustible actual: " << combustible_actual << endl;
    }
};

class Mision {
private:
    string destino;
    int duracion;
    string tripulacion;

public:
    Mision(string _destino, int _duracion, string _tripulacion) : destino(_destino), duracion(_duracion), tripulacion(_tripulacion) {}

    void simular_mision(Avion &avion, int distancia_recorrida) {
        cout << "Simulando misión hacia " << destino << "..." << endl;
        avion.despegar();
        avion.verificar_combustible(distancia_recorrida);
        avion.aterrizar();
    }
};

int main() {
    Avion avion("WAZA", 4000);
    Mision mision("Papulandia", 8, "Piloto, Copiloto, Azafatas");

    
    mision.simular_mision(avion, 500); 

    return 0;
}