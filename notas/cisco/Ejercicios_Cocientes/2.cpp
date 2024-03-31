#include <iostream>
using namespace std;

int main(){
    int x, y;
    cout << "Ingrese el primer y segundo número: ";
    cin >> x >> y;
    cout << "X : " << x << "\nY : " << y << endl;
    swap(x, y);
    cout << "Valor de x: " << x << "\nValor de y: " << y << endl;
}