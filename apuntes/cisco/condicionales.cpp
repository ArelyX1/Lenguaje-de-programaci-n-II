#include <iostream>
using namespace std;

int main() {
    string texto = "BuEnos dIas.";
    int contador = 0;

    for (char letra : texto) {
        switch (tolower(letra)) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                contador++;
                break;
            default:
                break;
        }
    }

    cout << "El número de vocales en el texto es: " << contador << endl;

    return 0;
}