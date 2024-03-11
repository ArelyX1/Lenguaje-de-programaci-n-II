#include <iostream>
using namespace std;

int main(){
    int n, m, cont = 0;
    cout << "Ingrese dos números: ";
    cin >> n >> m;
    for(; n; n--){
        cont += (n % m)? 0 : n;
    }
    cout << "La suma es " + to_string(cont);
}