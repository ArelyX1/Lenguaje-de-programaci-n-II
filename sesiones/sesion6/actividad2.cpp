#include <iostream>

using namespace std;
class Circulo; // Declaración anticipada de la clase Circulo

class Circulo {
private:
    double radio;
    double diametro;

public:
    Circulo(double r) : radio(r), diametro(2 * r) {}

    friend double calcularArea(const Circulo& c); // Declaración de la función amiga
};

double calcularArea(const Circulo& c) {
    return 3.14159 * c.radio * c.radio; // Fórmula del área de un círculo: π * r^2
}

int main() {
    Circulo circulo1(5.0);
    Circulo circulo2(3.0);

    cout << "Área del círculo 1: " << calcularArea(circulo1) << endl;
    cout << "Área del círculo 2: " << calcularArea(circulo2) << endl;
}