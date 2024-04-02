#include <iostream>
#include <cmath>
using namespace std;

const double PI = M_PI;
int main(){
    long double lado;
    cout << "Ingrese el lado de un cuadrado: ";
    cin >> lado;
    cout << "El perímetro del cuadrado es: " << 4 * lado << endl;
    cout << "El área del cuadrado es: " << pow(lado, 2) << endl;
}