#include <iostream>
#include <string>
#include <random>

using namespace std;

class Auto {
public:
    Auto(string nombre) : nombre(nombre), distancia_recorrida(0) {}

    void avanzar() {
        random_device rd;
        uniform_int_distribution<int> distribucion(1, 6);
        int distancia_avance = distribucion(rd);  
        distancia_recorrida += distancia_avance;
    }

    int obtenerDistanciaRecorrida() const {
        return distancia_recorrida;
    }

private:
    string nombre;
    int distancia_recorrida;
};

class Carrera {
public:
    Carrera(int distancia_total, int dificultad_oponente) : distancia_total(distancia_total), dificultad_oponente(dificultad_oponente) {}

    string correrCarrera() {
        Auto jugador("Jugador");
        Auto computadora("Computadora");

        while (jugador.obtenerDistanciaRecorrida() < distancia_total && computadora.obtenerDistanciaRecorrida() < distancia_total) {
            jugador.avanzar();
            computadora.avanzar();

            if (computadora.obtenerDistanciaRecorrida() < jugador.obtenerDistanciaRecorrida()) {
                random_device rd;
                uniform_int_distribution<int> distribucion(1, 10);
                int dificultad = distribucion(rd);
                if (dificultad <= dificultad_oponente) {
                    computadora.avanzar();
                }
            }
        }

        if (jugador.obtenerDistanciaRecorrida() >= distancia_total) {
            return "¡El jugador ha ganado la carrera!";
        } else {
            return "¡La computadora ha ganado la carrera!";
        }
    }

private:
    int distancia_total;
    int dificultad_oponente;
};

int main() {
    Carrera carrera(100, 5);  
    string resultado = carrera.correrCarrera();
    cout << resultado << endl;

    return 0;
}
