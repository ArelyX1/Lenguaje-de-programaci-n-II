#include <iostream>
using namespace std;

int main(){
    const int var1 = 0; //?Necesita un inicializador
    cout << "TIPOS DE INT, INT SHORT Y LONG\n";
    int var2; //aprox de - 60 k 60k
    short var2_1; //-32768 a 32767
    long var2_2; // -9223372036854775808 .. 9223372036854775807
    unsigned short var2_3 = -1; // Para solo positivos // 0 64 k
    unsigned long var2_4;
    cout << "short: " << var2_3;
    var2_4 = -4;
    cout <<" unsigned " <<var2_4 << endl;
    float var3;
    double var4;
    long double var4_2;

    bool var5; //0 o 1 

    char var6;  //*Para un solo carácter
    signed char var9; // -128 .. 127
    unsigned char var8 = 126; //0 .. 255
    cout << var8 << endl;
    string var7;

    int hh;
    //? INicalizador
    hh = 10;
}