#include <iostream> 
#include <string> 
using namespace std; 
int main()
{ 
 string titulos[5]; 
string autores[5]; 
cout <<"Ingrese la información de los libros: "<< endl;
 for (int i=0; i<5; i++) 
 { 
cout<<"\n******* Libro "<<i+1<<"*******:\n";
 cout<<"Titulo: ";cin>>titulos[i];
 cout<<"Autor: ";cin>>autores[i]; 
} 
//Lo siguiente muestra la información ingresada de los cinco libros 
 cout<<"********* Listado de libros ********* "<< endl;
 cout<<"Titulo\t Autor"<<endl; 
 int i = 0; 
 while ( i < 5) 
 { 
 cout<<titulos[i]<<"\t"<<autores[i]<<endl;
 i++; 
} 
} 