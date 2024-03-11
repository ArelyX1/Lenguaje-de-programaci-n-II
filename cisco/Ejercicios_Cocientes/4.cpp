#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float a, b, c, x, y, z;
    cout << "Ingrese los valores de a, b, c, x, y, z: " << endl;
    cin >> a >> b >> c >> x >> y >> z;
    float numerador = a + b / c, denominador = x + y / z;
    string rpta_A = (!isinf(denominador))? "El resultado es: " + to_string(numerador/denominador) : "No se puede dividir por 0";
    cout << rpta_A << endl;
}