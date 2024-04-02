#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> vec = {1, 45, 54, 71, 76, 12};
    auto minElemento = min_element(vec.begin(), vec.end()); //auto: deducción del tipo de variable
    auto maxElemento = max_element(vec.begin(), vec.end()); // min/max_element apunta pero no retorna nada
    cout << "El menor es: " << *minElemento << endl; //se muestra la dirección del campo apuntado
    cout << "El mayor es: " << *maxElemento << endl;
    return 0;
}