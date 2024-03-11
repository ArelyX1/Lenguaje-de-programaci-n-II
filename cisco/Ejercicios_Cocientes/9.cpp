#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cout << "Ingrese un a, b, c: ";
    cin >> a >> b >> c;
    if (a % b){
        if (a % c){
            if (b % c){
                cout << "No son multiplos";
            }
            else{
                cout << "Son multiplos A CON B y A CON C";
            }
        }
        else{
            if (b % c){
                cout << "Son multiplos A CON B y B CON C";
            }
            else{
                cout << "Son multiplos A CON B, A CON C y B CON C";
            }
        }
    }
    else{
        cout << "Ninguno es multiplo de otro";
    }
} 
//!TODO MAL