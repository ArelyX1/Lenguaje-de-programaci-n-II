#include <iostream>
using namespace std;
int main()
{
    const int FILAS = 4;
    const int COLUMNAS = 4;
    int matriz[FILAS][COLUMNAS] = { {1, 2, 3, 4},
                                    {5, 6, 7, 8},
                                    {9, 10, 11, 12},
                                    {13, 14, 15, 16}};
    cout << "Diagonal principal de la matriz:\n";
    for (int i = 0; i < FILAS; ++i)
    cout << matriz[i][i] << endl;
    return 0;
}