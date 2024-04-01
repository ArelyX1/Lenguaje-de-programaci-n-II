#include <iostream>

class Base {
public: // Cambiado a public
    int protegido;

public:
    Base() : protegido(0) {}

    void incrementarProtegido() {
        protegido++;
    }
};

class Derivada {
public:
    void mostrarProtegido(int protegido) {
        std::cout << "Valor protegido en Derivada: " << protegido << std::endl;
    }
};

int main() {
    Base b;
    b.incrementarProtegido();

    Derivada d;
    d.mostrarProtegido(b.protegido); // Esto imprimirá "Valor protegido en Derivada: 1"

    // Ahora se puede acceder a protegido directamente desde fuera de la clase Base o Derivada
    std::cout << "Valor de protegido desde main: " << b.protegido << std::endl;
    std::cout << "Valor de protegido desde main (derivada): " << std::endl;

    return 0;
}
