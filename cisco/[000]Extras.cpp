#include<iostream>
using namespace std;
int main(){
    {
        /*Código fuente 
        C++ 
        (programa.cpp)
            |
        Compilador C++ Código objeto 
        (programa.obj)
            |
        Enlazador  <-- Biblioteca C++
        (linker)
            |
        Programa 
        ejecutable 
        (programa.exe)
    */
    }
    {
        //*ETQUETAS
        goto buen_momo;
        cout << "Que mal momo" << endl; //Nunca se ejecutará
        for(int i = 0; i <= 5; i++){    //Nunca se ejecutará
            cout << i << endl;          //Nunca se ejecutará
        }                               //Nunca se ejecutará
        buen_momo:
        cout << "Que buen momo" << endl;//Apartir de aquí se ejecutará
        for(int i = 0; i <= 5; i++){    
            cout << i << endl;          
        }
    }
    {
        //*CAMBIO DE VARIABLES
        int x = 5;
        int y = 10;
        cout << "X : " << x << endl;
        cout << "Y : " << y << endl;
        swap(x, y);
        cout << "Valor de x: " << x << endl;
        cout << "Valor de y: " << y << endl;
    }
    {
        //*DECLARACION DE SALTO
        {
            //*BREAK
            int contador = 1; 
                for (contador = 1; contador <= 5; contador++) {
                    if (contador == 3) {
                    break;
                    // Sale del bucle cuando contador es igual a 3
                }
                cout << contador << " ";
                }
        }
        {
            //*CONTINUE
            int contador = 1; 
                for (contador = 1; contador <= 5; contador++) {
                    if (contador == 3) {
                    continue;
                    // Salta el resto del bucle cuando contador es igual a 3
                }
                cout << contador << " ";
                }
        }
    }
    {
        //*DECLARACION GOTO
        int contador = 1;
        bucle:
        cout << contador << " ";
        
        if (contador <= 5) {
            contador++;
            goto bucle;
        }
    }
}