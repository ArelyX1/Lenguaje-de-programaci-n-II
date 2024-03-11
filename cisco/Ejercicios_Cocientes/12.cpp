#include <iostream>
using namespace std;

int main(){
    int n, suma = 0;
    cout << "Ingrese un número: ";
    cin >> n;
    for (; n; n--){
        int facto = 1, temp = n;
        do{
            facto *= (temp)? temp : 1;
        } while(temp--);
        suma += facto;
    }
    cout << "La suma es " << suma;
}
/*
intput = 3
suma    n   facto
0       3   {1*3} = 3; {3*2} = 6; {6*1} = 6
6       2   {1*2} = 2; {2*1} = 2
8       1   {1*1} = 1
9       0
*/
