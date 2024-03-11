#include <iostream>
using namespace std;

int main(){
    int conter = 100'000; // = es el inicializador
    cout << 0x102321 << endl;
    /*POTENCIAS:
    SON USADAS CON E o e.
    
    PARA NUMEROS GRANDES USAR LA NOTACIÓN CIENTÍFICA 100'000'000*/
    cout << conter << endl;
    cout << 10e-2 << endl;
    float x = 0.0;
    float y = 1.0 / x;
    cout << y <<endl;
    // i++; ++i
    /*
    i = 0
    int var = i++
    int var2 = i
    */
    int temp = 1;
    int i = 1;
    int j = i++;
    cout << j << endl;
    
    j = ++i;
    cout << j << endl;
    int k = ++temp;
    cout << k << endl;

    char caracter = 65;
    cout << caracter << endl;

    /*Entidades de escape:
    \n  =  salto de linea
    \r  =  regreso al principio de linea
    \a  =  timbre (?)
    \0  =  valor nul
    */
    cout << "Hola\a" << endl;
    caracter = '\46';
    cout << caracter << endl;
    caracter = '\x27';
    cout << caracter << endl;


    char character = 'A';
    character += 32;
    character -= ' ';
    cout << character << endl;


    character = 'A' + 32;
    character = 'A' + ' ' ; 
    character = 65 + ' ';
    cout << character << endl;
    character = 97 - ' ';
    character = 'a' - 32;  
    character = 'a' - ' ';
    cout << character << endl;


    int byte = 255;
    cout << "Byte in hex: " << hex << byte << endl;
    cout << 0016;

    cout << "CHAR: " << static_cast<int>('Z') << endl;
    cout << "CHAR: " << dec << 0x5a << endl;
    return 0; // return 1 si esta mal

    /*Comentario
    de varios bloques 
    */
}