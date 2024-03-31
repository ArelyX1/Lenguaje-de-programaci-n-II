#include <iostream>
using namespace std;
void cuadrado(int vector[], int tamanio);
void imprimir(const int vector[], int tamanio);
int main()
{
    const int DIM = 5;
    int vector[DIM] = {1, 2, 3, 4, 5};
    cuadrado(vector, DIM);
    imprimir(vector, DIM);
    return 0;
}
void cuadrado(int vector[], int tamanio)
{
    for (int i = 0; i < tamanio; ++i)
 vector[i] *= vector[i];
}
void imprimir(const int vector[], int tamanio)
{
    for (int i = 0; i < tamanio; ++i)
    cout << vector[i] << " ";
    cout << endl;
}