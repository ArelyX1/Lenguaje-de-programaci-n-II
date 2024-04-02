#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> originalVector(10);
    vector<int> multipliedVector(10);

    for (int i = 0; i < 10; ++i) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> originalVector[i];
    }

    int n;
    cout << "Ingrese el número por el cual multiplicar: ";
    cin >> n;

    for (int i = 0; i < 10; ++i) {
        multipliedVector[i] = originalVector[i] * n;
    }

    cout << "El segundo arreglo es: ";
    for (int i = 0; i < 10; ++i) {
        cout << multipliedVector[i] << " ";
    }

    return 0;
}