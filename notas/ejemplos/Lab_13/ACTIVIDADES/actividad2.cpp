#include <iostream>
using namespace std;
const int FILAS = 2;
const int COLS = 3;
void mostrarMatriz(const int m[][COLS], int nrofilas, int nrocols);
void cuadradoMatriz(int m[][COLS], int nrofilas, int nrocols);
int main()
{
    int matriz[FILAS][COLS] = {{1, 2, 3}, {4, 5, 6}};
    mostrarMatriz(matriz, FILAS, COLS);
    cuadradoMatriz(matriz, FILAS, COLS);
    mostrarMatriz(matriz, FILAS, COLS);
 return 0;
}
void mostrarMatriz(const int m[][COLS], int nrofilas, int nrocols)
{
    cout << "Mostrando matriz: \n";
    for (int i = 0; i < nrofilas; ++i)
    {
    for (int j = 0; j < nrocols; ++j)
    cout << m[i][j] << " ";
    cout << "\n";
    }
    cout << "\n";
}
void cuadradoMatriz(int m[][COLS], int nrofilas, int nrocols)
{
    for (int i = 0; i < nrofilas; ++i)
    {
    for (int j = 0; j < nrocols; ++j)
    m[i][j] *= m[i][j];
    }
}