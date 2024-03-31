#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
    int num;
    cout << "Ingrese un numero: ";
    cin >> num;
    string absoluto_num = (num < 0)? "El valor absoluto del numero es: " + to_string(abs(num)) : "El valor ya es positivo";
    cout << absoluto_num << endl;
}