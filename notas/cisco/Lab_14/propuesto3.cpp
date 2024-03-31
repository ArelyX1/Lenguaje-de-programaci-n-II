#include <iostream>
#include <cstring>
using namespace std;

void toLower(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}

int main() {
    char str[100];

    cout << "Ingrese una cadena de caracteres: ";
    cin.getline(str, 100);

    toLower(str);

    cout << "La cadena en minúsculas es: " << str << endl;

    return 0;
}