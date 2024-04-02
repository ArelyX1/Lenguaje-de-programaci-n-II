#include <iostream>
using namespace std;

int main(){
    int tama, temp = 1;
    cout << "Ingrese el tamaño del triángulo: ";
    cin >> tama;
    for (; tama; tama--){
        for (int j = 0; j < tama - 1; j++){
            cout << ' ';
        }
        string unos = string(temp, '*');
        temp += 2;
        cout << unos;
        cout << endl;
    }
    for (; tama; tama--){
        for (int j = 0; j < tama - 1; j++){
            cout << ' ';
        }
        string unos = string(temp, '*');
        temp += 2;
        cout << unos;
        cout << endl;
    }
}