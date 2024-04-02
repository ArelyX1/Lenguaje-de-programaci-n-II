#include <iostream>
using namespace std;

int main(){
    int tama, temp = 1;
    string unos = "1";
    cout << "Ingrese el tamaño del triángulo: ";
    cin >> tama;
    for (; tama; tama--){
        for (int j = 0; j < tama - 1; j++){
            cout << 0;
        }
        unos = string(temp, '1');
        temp += 2;
        cout << unos;
        for (int j = 0; j < tama - 1 ; j++){
            cout << 0;
        }
        cout << endl;
    }
}