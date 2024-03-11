#include <iostream>
#include <cmath>
using namespace std;
const double epsilon = 1e-10;
int main(){
    float a = 3.1/0.;
    if (a == false)
        cout << "El resultado es: " << a << endl;
    else
        cout << "No se puede dividir por 0" << endl;

}