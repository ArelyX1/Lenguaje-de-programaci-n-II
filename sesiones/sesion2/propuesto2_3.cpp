#include <iostream>
#include <string>
using namespace std;

class Factura {
    private:
        string numeroFactura;
        string fechaEmision;
        double monto;
    public:
        Factura(string numeroFactura, string fechaEmision, double monto) : numeroFactura(numeroFactura), fechaEmision(fechaEmision), monto(monto) {}

        // Métodos get
        string getNumeroFactura() { return numeroFactura; }
        string getFechaEmision() { return fechaEmision; }
        double getMonto() { return monto; }

        // Métodos set
        void setNumeroFactura(string nuevoNumeroFactura) { numeroFactura = nuevoNumeroFactura; }
        void setFechaEmision(string nuevaFechaEmision) { fechaEmision = nuevaFechaEmision; }
        void setMonto(double nuevoMonto) { monto = nuevoMonto; }
};

int main() {
    // Crear algunas facturas
    Factura factura1("12345", "01/01/2022", 100.50);
    Factura factura2("67890", "02/02/2022", 200.75);

    // Imprimir información sobre las facturas
    cout << "Factura 1: " << factura1.getNumeroFactura() << ", " << factura1.getFechaEmision() << ", " << factura1.getMonto() << endl;
    cout << "Factura 2: " << factura2.getNumeroFactura() << ", " << factura2.getFechaEmision() << ", " << factura2.getMonto() << endl;

    // Cambiar y imprimir la información de una factura
    factura1.setNumeroFactura("54321");
    factura1.setFechaEmision("03/03/2022");
    factura1.setMonto(150.25);
    cout << "Factura 1 (actualizada): " << factura1.getNumeroFactura() << ", " << factura1.getFechaEmision() << ", " << factura1.getMonto() << endl;

    return 0;
}