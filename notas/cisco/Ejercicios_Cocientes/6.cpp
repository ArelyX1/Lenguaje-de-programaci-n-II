#include <iostream>
#include <cmath>
using namespace std;
const double PI = M_PI;
int main(){
    long double radio;
    cout << "Ingrese el radio del ciculo: " << endl;
    cin >> radio;
    cout << "El area de circulo es: " << PI * pow(radio, 2) << endl;
}