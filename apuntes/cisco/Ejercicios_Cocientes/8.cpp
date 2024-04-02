#include <iostream>
using namespace std;

int main(){
    char letra;
    cout << "Ingrese un caracter: ";
    cin >> letra;
    (letra < 'A' || letra > 'Z')? (letra < 'a' || letra > 'z')? cout << "El caracter ingresado no es una letra" : cout << "El caracter ingresado es una letra minuscula" : cout << "El caracter ingresado es una letra mayuscula";
} 