#include <iostream>
#include <cmath>
using namespace std;

int main(){
    /*Tipos de variables PRIMITIVOS:
        - char
        - int
        - float
        - double
        - void
    Otras variables:
        - bool
        - string
        - wchar_t
        - vector
        - array
    Modificadores de tipo:
        - signed
        - unsigned
        - short
        - long
        - long long
    Estruturas de datos:
        - struct
        - class
        - union
        - enum
    Palabras reservadas:
        - typedef
        - auto
        - nullptr
        - decltype
        - using
    Especeficadores de tipo:
        - const
        - static
        - volatile
        - extern
        - register
        - mutable
        - thread_local(para variables especificas de hilos de ejecución)
    Palabras reservadas para la definición de clases:
        - friend
        - virtual
        - inline
        - explicit
        - default
        - delete
        - new
        - override
        - final
    Operadores:
        - sizeof
        - typeid
        - alignof
        - alignas
        - noexcept
        - throw
        - new
        - delete
    Palabras reservadas para el manejo de excepciones:
        - try   
        - catch
        - throw
    Palabras reservadas para la verificación en tiempo de compilación:
        - static_assert
        - constexpr
    */

    char var0 = 'a';
    char var0_1 = 97;
    int var1 = 999'999'999;
    float var2 = 0.22222222222;
    double var3 = 3e-9;
//--------------------------------------------------------------------------------------------------------------
    //*INTERVALOS:
        /* 
        int -2147483648 a 2147483647 32 bits
        rango de magnitudes: float 1.17549e-38 hasta 3.40282e+38 32 bits 
        char -128 a 127 8 bits
        double 2.22507e-308 hasta 1.79769e+308 64 bits
        */
//--------------------------------------------------------------------------------------------------------------
    //!DIVICION POR 0 PERO CON FLOAT, con int sale una excepcion
    float var4 = 1.0 / 0.0;
    cout << "Entero:\t" << var4 << endl; //? Entero:	inf
        //!int f = 1 / 0;
        //!cout << "Entero:\t" << f << endl; //? Error de ejecución
//--------------------------------------------------------------------------------------------------------------
    //*CONTADORES post, pre incremento y decremento
        /*Es distinto:
            ++var y var++
                o
            --var y var--
            1. Primero aumenta y luego asigna
            2. Primero asigna y luego aumenta*/
    int i = 4;
    //int j = 2 * i++;
    cout << "pre incremento" << 2 * ++i << endl; //10
        //?primero aumenta y luego asigna a i
    cout << "Post incremento" << 2 * i++ << endl; //10 
        //?primero i devuelve el valor y luego aumenta, en otras palabras 2 * i(4) y luego i = i + 1
        // Ahora i = 6
//--------------------------------------------------------------------------------------------------------------
    //*ESCAPE CHARACTERS
    /*\n LF(line feed) Salto de línea
    \r CR(carriage return) Retorno de carro
    \t HT(tab) Tabulador
    \v VT(vertical tab) Tabulador vertical
    \b BS(backspace) Retroceso
    \f FF(form feed) Avance de página
    \a BEL(bell) Timbre
    \0 NULL
    */
//--------------------------------------------------------------------------------------------------------------
    //*TCHAR
    char p = '\x27';
    cout << p << endl; // 39
    //? \x27 es el valor hexadecimal de 39 pero no coloco el caracter de la tabla ASCII
    char character = 'A' + 32;
    cout << character << endl;
    character = 'A' + ' ' ;
    cout << character << endl;
    character = 65 + ' ';
    cout << character << endl;
    character = 97 - ' ';
    cout << character << endl;
    character = 'a' - 32;
    cout << character << endl;
    character = 'a' - ' ';
    cout << character << endl;
        //PARA SABER EL VALOR ASCII DE UN CARACTER O SU REPRESENTACIÓN
    character = 'X';
	int integer = character;
	cout << character << " " << static_cast<int>(character);
	cout << " " << integer << " " << static_cast<char>(integer);
//--------------------------------------------------------------------------------------------------------------
    {
        //*FLOAT
        {
            //*SUBDESBORDAMIENTO Y DESBORDAMIENTO
            //SUB: CUANDO EL VALOR ES MÁS PEQUEÑO QUE EL VALOR MINIMO DE LA MAGNITUD
            //?SUB = 0
            //DES: CUANDO EL VALOR ES MÁS GRANDE QUE EL VALOR MÁXIMO DE LA MAGNITUD
            //?DES = inf
        }
        float num = 1.234666;
        cout << num << endl; //Simplifica a 6 digitos pero los digitos completos esta guardado en la memoria
            //!Perdida de precisión
        double a = 0.1, b = 0.2, c = 0.3;
        if(a + b != c) //Entra al if porque los flotantes pueden ser representados en binario, asi que usa aprox.
            cout << "Your computer is out of order";
            //?Solucion
        {
            double epsilon = 1e-10;
            if(abs(a + b - c) < epsilon)
                cout << "Your computer is out of order";
        }
    }
//--------------------------------------------------------------------------------------------------------------
    //*MODIFICADORES
    const int var1_5 = 0; //?Necesita un inicializador
    cout << "TIPOS DE INT, INT SHORT Y LONG\n";
    int var2_4; //aprox de - 60 k 60k 32 bits
    short var2_1; //-32768 a 32767 16 bits
    long var2_2; // -9223372036854775808 .. 9223372036854775807 64 bits
    unsigned short var2_3 = -1; // Para solo positivos // 0 64 k 16 bits
    unsigned long var2_9; // 0 .. 18446744073709551615 64 bits
    cout << "short: " << var2_3;
    var2_4 = -4;
    cout <<" unsigned " <<var2_4 << endl;
    float var3_2;
    double var4_4;
    long double var4_2;

    bool var5; //0 o 1 

    char var6;  // Para un solo carácter
    signed char var9; // -128 .. 127
    unsigned char var8 = 126; //0 .. 255
    cout << var8 << endl;
    string var7;

    int hh;
    //? INicalizador
    hh = 10;

}