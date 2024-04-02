#include <iostream>
using namespace std;

class banco{
    protected:
        float saldo;
    public:
        string nombre;
        string direccion;
        string telefono;
        banco(string, string, string, float);
        void setSaldo(float saldo_nuevo){this -> saldo = saldo_nuevo;}
        virtual float getSaldo(){return saldo;}
};

banco::banco(string nombre_inicial, string direccion_inicial, string telefono_inicial, float saldo_inicial){
    this -> nombre = nombre_inicial;
    this -> direccion = direccion_inicial;
    this -> telefono = telefono_inicial;
    this -> saldo = saldo_inicial;
}

class cuenta : public banco{
    protected:
        string titular;
        float saldo_personal;
    public:
        cuenta(string, string, string, float, string, float);
        void setTitular(string titular_nuevo){titular = titular_nuevo;}
        string getTitular(){return titular;}
        void setSaldo(float saldo_nuevo){this -> saldo_personal = saldo_nuevo;}
        float getSaldo() override {return saldo_personal;}
        void retirar(float cantidad);
        void depositar(float cantidad);
};

cuenta::cuenta(string nombre_inicial, string direccion_inicial, string telefono_inicial, float saldo_banco, string titular_inicial, float saldo_cuenta_inicial) : banco(nombre_inicial, direccion_inicial, telefono_inicial, saldo_banco){
    if(saldo_cuenta_inicial > saldo_banco){
        throw invalid_argument("El saldo inicial de la cuenta no puede ser mayor que el saldo del banco");
    }
    this -> titular = titular_inicial;
    this -> saldo_personal = saldo_cuenta_inicial;
    banco::saldo -= saldo_cuenta_inicial; // Actualiza el saldo del banco
}

void cuenta::retirar(float cantidad){
    if(cantidad > saldo_personal){
        throw invalid_argument("No se puede retirar esa cantidad, NO HAY PLATA");
    }else{
        saldo_personal -= cantidad;
        banco::saldo -= cantidad; // Actualiza el saldo del banco
    }
}

void cuenta::depositar(float cantidad){
    saldo_personal += cantidad;
    banco::saldo += cantidad; // Actualiza el saldo del banco
}

int main(){
    cuenta* cuenta1 = new cuenta("Banco chaskilandia", "Calle Amazonas", "902177449", 10000, "Juanito to pape", 50000);
    cout << "Nombre del banco: " << cuenta1 -> nombre << endl;
    cout << "Direccion del banco: " << cuenta1 -> direccion << endl;
    cout << "Telefono del banco: " << cuenta1 -> telefono << endl;
    cout << "Titular de la cuenta: " << cuenta1 -> getTitular() << endl;
    cout << "Saldo de la cuenta: " << cuenta1 -> getSaldo() << endl;
    cuenta1 -> retirar(500);
    cout << "Saldo de la cuenta: " << cuenta1 -> getSaldo() << endl;
    cuenta1 -> depositar(1000);
    cout << "Saldo de la cuenta: " << cuenta1 -> getSaldo() << endl;
    return 0;
}