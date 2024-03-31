#include <iostream>
using namespace std;
int main(){
    //*BUCLE WHILE
    int contador = 0;
    while (contador < 10){
        cout << "El contador es: " << contador << endl;
        contador++;
    }

    //*BUCLE DO-WHILE
    int contador2 = 0;
    do {
        cout << "El contador es: " << contador2 << endl;
        contador2++;
    } while (contador2 < 10);

    //*BUCLE FOR
    for (int i = 0; i < 10; i++){
        cout << "El contador es: " << i << endl;
    }
    {
        /*Bucle for infinito
            for(;;) {
                the body goes here 
        */ 
    }
    {
        //*EJEMPLO DE BUCLE FOR
        int n, m, cont = 0;
        cout << "Ingrese dos números: ";
        cin >> n >> m;
        for(; n; n--){
            cont += (n % m)? 0 : n;
        }
    }
}