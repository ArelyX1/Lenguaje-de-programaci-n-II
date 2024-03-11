#include <iostream>
using namespace std;
int main(){
    {
        // OPERADORES LOGICOS
        //? && (AND) - Devuelve true si ambos operandos son verdaderos
        //? || (OR) - Devuelve true si al menos uno de los operandos es verdadero

        //OTROS OPERADORES
        /*equivalencias
        //?variable > 0    ------     !(variable <= 0)
        //?variable != 0   ------     !(variable == 0)*/
        //bit a bit
        //* &	and (as in bitand)
        //* |	inclusive or (as in bitor)
        //* ~	compl (as in compliment)
        //* ^	xor
    }
//--------------------------------------------------------------------------------------------------------------
    {
        //*CONDICIONAL ANIDADA
        int numero = 10;
        if (numero > 0){
            if (numero < 10){
                cout << "El número es positivo y menor que 10." << endl;
            } else {
                cout << "El número es positivo y mayor o igual que 10." << endl;
            }
        } else {
            cout << "El número es negativo." << endl;
        }
    }
//--------------------------------------------------------------------------------------------------------------
    {
        //*CONDICIONAl EN CASCADA
        int numero2 = 20;
        if (numero2 < 0){
            cout << "El número es negativo." << endl;
        } else if (numero2 == 20){
            cout << "El número es 20." << endl;
        } else if (numero2 > 0){
            cout << "El número es positivo." << endl;
        }
    }
//--------------------------------------------------------------------------------------------------------------
    {
        //*CONDICIONAL SWITCH
        char numero4 = 'd';
        switch (numero4){ //Switch expression
            case 'a': //case label
                cout << "El número es 1." << endl;
                break;
            case 'd':
                cout << "El número es 2." << endl;
                break;
            case '5':
                cout << "El número es 3." << endl;
                break;
            default:
                cout << "El número no es 1, 2 o 3." << endl;
        }
        {
            //*WHEN THE SWITCH EXPRESION IS EQUAL TO 2 RESULTS FOR A SINGLE CASE LABEL
            int i = 3;
            switch(i) {
                case 1: 
                    cout << "Only one?" << endl; 
                    break;
                case 2: 
                    cout << "I want more" << endl; 
                    break;
                case 3: 
                case 4: 
                    cout << "OK" << endl;
            }
        }
        {
            //*SWITCH CON RANGO
            int salario = 1059;
            switch (salario){
                case 0 ... 1000:
                    cout << "Pobre";
                    break;
                case 1001 ... 2000:
                    cout << "Clase media";
                    break;
                case 2001 ... 3000:
                    cout << "Clase media alta";
                    break;
                case 3001 ... 4000:
                    cout << "Rico";
                    break;
                default:
                    cout << "Muy rico";
            }
        }
    }
//--------------------------------------------------------------------------------------------------------------
    {
        //*CONDICIONAL TERNARIO
        int numero3 = -1;
        (numero3 > 0) ? cout << "El número es positivo." : cout << "El número es negativo.";
    }
//--------------------------------------------------------------------------------------------------------------
    {
        //*EQUIVALENCIA DE CONDICIONALES
        /*
        while(number != 0) {...}
    while(number) {...}
        

        
        if(number % 2 == 1)...
    if(number % 2)...



    int counter = 5;
        while(counter) {
            cout << "I am an awesome program" << endl;
            counter--;
        }
    while(counter--)
        cout << "I am an awesome program" << endl;*/
    }
}