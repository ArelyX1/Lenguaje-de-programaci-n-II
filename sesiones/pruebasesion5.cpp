#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Clase CodigoQr que contiene un número aleatorio
class CodigoQr {
public:
    int numeroAleatorio;

    CodigoQr() {
        // Generar un número aleatorio entre 1 y 100
        numeroAleatorio = rand() % 100 + 1;
    }
};

// Clase CuentaBancariaQr que representa una cuenta bancaria por QR
class CuentaBancariaQr {
public:
    int saldo;
    CuentaBancariaQr(int saldo){
        this -> saldo = saldo;
    }
    // Función para aumentar el saldo de la cuenta bancaria por un valor dado
    void aumentarSaldo(int cantidad) {
        saldo += cantidad;
    }

    // Función para procesar un código QR y aumentar el saldo
    void procesarCodigoQr(CodigoQr* codigo, CuentaBancariaQr* otraCuenta, int cantidad) {
        aumentarSaldo(cantidad);
        otraCuenta->disminuirSaldo(cantidad);
    }

    // Función para disminuir el saldo de la cuenta bancaria por un valor dado
    void disminuirSaldo(int cantidad) {
        saldo -= cantidad;
    }
};

int main() {
    // Inicializar el generador de números aleatorios
    srand(time(NULL));

    // Crear dos objetos de la clase CuentaBancariaQr
    CuentaBancariaQr cuenta1(40), cuenta2(40);

    // Crear tres objetos de la clase CodigoQr
    CodigoQr qr1, qr2, qr3;

    // Ingresar la cantidad de saldo a aumentar
    int cantidadAumento;
    cout << "Ingrese la cantidad de saldo a aumentar: ";
    cin >> cantidadAumento;

    // Procesar los códigos QR y realizar las operaciones de saldo
    cuenta1.procesarCodigoQr(&qr1, &cuenta2, cantidadAumento);
    cuenta1.procesarCodigoQr(&qr2, &cuenta2, cantidadAumento);
    cuenta2.procesarCodigoQr(&qr3, &cuenta1, cantidadAumento);

    // Imprimir el saldo actual de las cuentas
    cout << "Saldo actual de la cuenta 1: " << cuenta1.saldo << endl;
    cout << "Saldo actual de la cuenta 2: " << cuenta2.saldo << endl;

    return 0;
}
