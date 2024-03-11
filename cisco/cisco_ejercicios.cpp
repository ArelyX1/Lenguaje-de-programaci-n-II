#include <iostream>
#include <cmath>
using namespace std;
const double epsilon = 1e-10;
void mostrarvec(vector<int>& vec){
    for(size_t i = 0; i < vec.size(); i++){cout << vec[i] << " ";}
}
int main(){
    float a = 3.1/0.;
    if (a == false)
        cout << "El resultado es: " << a << endl;
    else
        cout << "No se puede dividir por 0" << endl;
    {
    vector<int> numeros;
    do{
        int temp;
        cout << "Ingrese un número: ";
        cin >> temp;
        if (temp == 0){break;
        } else {
            numeros.push_back(temp);}
    }while (true);
    mostrarvec(numeros);
    }

}
void mostrarvec(vector<int>& vec){
    for(size_t i = 0; i < vec.size(); i++){cout << vec[i] << " ";}
}
