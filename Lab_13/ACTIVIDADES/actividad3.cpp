#include <iostream>
using namespace std;
int main()
{
    const int TAMANO = 5;
    int numeros[TAMANO] = {1, 2, 3, 4, 5};
    int suma = 0;
    for (int i = 0; i < TAMANO; ++i)
    suma += numeros[i];
    cout << "La suma de los elementos del vector es: " << suma <<endl;
    return 0;
}
