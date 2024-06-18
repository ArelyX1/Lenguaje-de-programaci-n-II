#include "validaEntero.h"
#include "validaFloat.h"
#include <iostream>
#include <cmath>
using namespace std;

class Capital {
private:
    float capi;
    friend class FCalculo;
public:
    Capital(float _capi) {
        this->capi = _capi;
    }
};

class Interes {
private:
    float interes;
    friend class FCalculo;
public:
    Interes(float _interes) {
        this->interes = _interes;
    }
};

class Plazo {
private:
    int plazo;
    int dias;
    friend class FCalculo;
public:
    Plazo(int _plazo, int _dias) {
        this->plazo = _plazo;
        this->dias = _dias;
    }
};

class FCalculo {
public:
    void calcularGanancia(const Capital &cap, const Interes &inte, const Plazo &plazo) {
        float total = pow((1 + inte.interes / 100), (plazo.dias / static_cast<float>(plazo.plazo))) - 1;
        cout << "El interez ganado es de: " << cap.capi * total << " soles\n";
    }
};

int main() {
    while (1) {
        cout << "Ingrese la capital prestado: ";
        float capital = getInputFloat();
        Capital cap(capital);
        cout << "\nIngrese el plazo: ";
        int plazo = getInputInt();
        cout << "\nIngrese los días: ";
        int dias = getInputInt();
        Plazo plazos(plazo, dias);
        cout << "\nIngrese la tasa de interés: ";
        float interes = getInputFloat();
        Interes inter(interes);
        FCalculo banco;
        banco.calcularGanancia(cap, inter, plazos);
    }
}