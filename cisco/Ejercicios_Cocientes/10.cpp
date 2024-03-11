#include <iostream>
using namespace std;

int main(){
    int salario;
    cout << "Ingrese el salario: ";
    cin >> salario;
    switch (salario){
        case 0 ... 1000:
            cout << "Pobre";
            break;
        case 1001 ... 2000:
            cout << "Clase media";
            break;
        case 2001 ... 3000:
            cout << "Clase media alta";
            break;
        case 3001 ... 4000:
            cout << "Rico";
            break;
        default:
            cout << "Muy rico";
    }
}