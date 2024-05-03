#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

class IFormaPago{
    public:
        virtual void pagar(float monto) = 0;
        virtual ~ IFormaPago(){}
};

class IDeposito{
    protected:
        float setMonto(){
            float *monto = 0;
            float temp;
            cin >> temp;
            monto = new float(temp);
            return *monto;
        }
};

class Banco : IDeposito{
    private:
        float capital;
        int dni;
    public:
        Banco(float capital, int dni){
            this -> capital;
            this -> dni;
        }
        void depositarBanco(){
            capital += IDeposito::setMonto();
        }
        void depositar(float cantidad){
            capital -= cantidad;
        }
};

class CodigoQr{
    public:
        int qr;
        CodigoQr(){
            srand(time(NULL));
            qr = (rand() % 9999) + 10000;
        }
};

class Yape : IFormaPago{
    private:
        float capital = 0;
        Banco *cuenta_bancaria;
        void aumentarSaldo(float n){
            capital += n;
        }
    public:
        Yape *otro_yape;
        const CodigoQr *codigo;

        Yape(CodigoQr *_codigo, Banco *_banco){
            this -> codigo = _codigo;
            this -> cuenta_bancaria = _banco;
        }
        void escanearQr(CodigoQr*codigo, float cantidad){
            aumentarSaldo(codigo -> qr);
            codigo -> qr =- cantidad;
        }


};

int main(){
    exit(0);
}
