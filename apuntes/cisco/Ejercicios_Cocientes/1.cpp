#include<iostream>
using namespace std;

int main(){
    int x, y, z, w;
    cout << "Para la ecuación (x+y)/(z+w) \n";
    cout << "Ingrese los valores x , y, z, w:\n";
    cin >> x >> y >> z >> w;
    string resultado = (z+w == 0) ? "El denominador no puede ser 0" : "El resultado es: " + to_string((x+y)/(z+w));


    cout << resultado;
}