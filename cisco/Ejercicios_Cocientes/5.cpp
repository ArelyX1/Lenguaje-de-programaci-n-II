#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float celsius;
    cout << "Ingrese la temperatura en Celsius: ";
    cin >> celsius;
    cout << "La temperatura en Fahrenheit es: " << celsius * (9. / 5.) + 32 << endl;
}