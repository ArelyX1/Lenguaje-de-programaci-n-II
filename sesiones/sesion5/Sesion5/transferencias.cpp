#include "validaEnteros.h"

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <ctime>
#include <limits>
#include <exception>
using namespace std;

int menu();
int iniciar_banco();
void crear_banco();
int menu_plin();
int menu_banco();

class Banco;
class Plin;
class Yape;
class CodigoQr{
    public:
        int qr;

        CodigoQr(){
            qr = (rand() % 9999) + 10000;
        }
};

class IFormaPago{
    protected:
        float capital = 0;
        int celular = 0;
        Banco *cuenta_bancaria;
        const CodigoQr *codigo;

    public:
        virtual void aumentarSaldo(float monto) = 0;
        virtual void disminuirSaldo(float monto) = 0;
        virtual void depositar() = 0;
        virtual void escanearQr(int codigo, float cantidad, IFormaPago *otro) = 0;
        virtual void getInfo() = 0;
        virtual void depositarCelular(int celular, float cantidad, IFormaPago *otro) = 0;
        int getCodigoqr(){
            return codigo -> qr;
        }
        int getCelular(){
            return celular;
        }
        virtual ~ IFormaPago(){}
};

class IDeposito{
    protected:
        float setMonto(){
            float *monto = 0;
            float temp;
            cout << "Ingrese el monto: ";
            cin >> temp;
            monto = new float(temp);
            return *monto;
        }
};

class Banco : IDeposito{
    private:
        float capital = 0;
        int dni;
    public:
        Banco(int dni){
            this -> capital = 0l;
            this -> dni = dni;
        }

        int getDni(){
            return dni;
        }

        void getInfo(){
            cout << "Capital del banco: " << capital << endl;
        }

        void depositarBanco(){
            capital += IDeposito::setMonto();
        }
        float depositar(){
            float temp = capital;
            capital -= IDeposito::setMonto();
            return temp - capital;
        }
};



class Yape : public IFormaPago{
    private:
        void aumentarSaldo(float cantidad) override {
            capital += cantidad;
        }
        void disminuirSaldo(float cantidad) override{
            capital -= cantidad;
        }
    public:

        Yape(Banco *_banco, int _celular){
            this -> codigo = new CodigoQr();
            this -> cuenta_bancaria = _banco;
            this -> celular = _celular;
        }

        void depositar() override{
            capital = cuenta_bancaria->depositar();
        }

        void getInfo() override {
            cout << "Capital del yape: " << capital << endl;
            cuenta_bancaria -> getInfo();
            cout << "Código QR: " << codigo -> qr << endl;
        }

        void escanearQr(int codigo, float cantidad, IFormaPago *otro) override{
            if (codigo  == otro -> getCodigoqr()){
                aumentarSaldo(cantidad);
                otro -> disminuirSaldo(cantidad);
            }
            else{
                cout << "Código QR incorrecto" << endl;
            }
        }

        void depositarCelular(int celular, float cantidad, IFormaPago *otro) override{
            if (celular == otro -> getCelular()){
                aumentarSaldo(cantidad);
                otro -> disminuirSaldo(cantidad);
            }
            else{
                cout << "Celular incorrecto" << endl;
            }

        }
            
};

class Plin : public IFormaPago{
    private:
        void aumentarSaldo(float cantidad) override {
            capital += cantidad;
        }
        void disminuirSaldo(float cantidad) override{
            capital -= cantidad;
        }
    public:

        Plin(Banco *_banco, int _celular){
            this -> codigo = new CodigoQr();
            this -> cuenta_bancaria = _banco;
            this -> celular = _celular;
        }
        void depositar() override{
            capital = cuenta_bancaria->depositar();
        }

        void getInfo() override {
            cout << "Capital del yape: " << capital << endl;
            cuenta_bancaria -> getInfo();
            cout << "Código QR: " << codigo -> qr << endl;
        }

        void escanearQr(int codigo, float cantidad, IFormaPago *otro) override{
            if (codigo  == otro -> getCodigoqr()){
                aumentarSaldo(cantidad);
                otro -> disminuirSaldo(cantidad);
            }
            else{
                cout << "Código QR incorrecto" << endl;
            }
        }

        void depositarCelular(int celular, float cantidad, IFormaPago *otro) override{
            if (celular == otro -> getCelular()){
                aumentarSaldo(cantidad);
                otro -> disminuirSaldo(cantidad);
            }
            else{
                cout << "Celular incorrecto" << endl;
            }

        }
};

vector<Banco*> bancos;
vector<Yape*> yapes;
vector<Plin*> plines;

int main(){
    srand(time(NULL));
    do{
        switch (menu())
        {
        case 1:
            char op;
            do{
                cout << "Ingrese su Yape/banco (S) Iniciar Sesion (N) Registrarse al banco/Yape: ";
                cin >> op;
                if (op == 'S' || op == 's')  iniciar_banco();
                else if (op == 'N' || op == 'n' ) crear_banco();
                else continue;
                break;  
            } while (1);
        
        default:
            break;
        }
    } while (1);
    
    exit(0);
}
int menu(){
    cout << "Agregar Yape        ----------------- 1" << endl;
    cout << "Agregar Plin        ----------------- 2" << endl;
    cout << "Opciones Yape       ----------------- 3" << endl;
    cout << "Opciones Plin       ----------------- 4" << endl;
    int opcion = getInputInt();
    return opcion;
}

int iniciar_banco(){
    int dni;
    cout << "Ingrese su DNI para iniciar sesión: ";
    cin >> dni;
    cout << "Ingrese su celular: ";
    int celular;
    cin >> celular;
    for (int i = 0; i < bancos.size(); i++){
        if (bancos[i] -> getDni() == dni){
            cout << "Se ha conectado con Yape" << endl;
            Yape *yape = new Yape(bancos[i], celular);
            yapes.push_back(yape);
            return 1;
        }
    }
    cout << "No se ha conectado con Yape" << endl;
    return 0;
}

void crear_banco(){
    int dni; 
    cout << "Ingrese su DNI para registrarse al banco: ";
    cin >> dni;
    Banco *banco = new Banco(dni);
    bancos.push_back(banco);
}

int menu_yape(){
    cout << "Depositar a yape dinero del banco     ----------------- 1" << endl;
    cout << "Depositar otro yape o plin por numero ----------------- 2" << endl;
    cout << "Escanear QR                           ----------------- 3" << endl;
    cout << "Ver información                       ----------------- 3" << endl;
    int opcion = getInputInt();
    return 0;
}