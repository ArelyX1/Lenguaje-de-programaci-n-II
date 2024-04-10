#include <iostream>
#include <string>
using namespace std;
class IPagina{
    virtual string getContenido() = 0;
    virtual int getNumero() = 0;
    virtual void setContenido(string) = 0;
    virtual void setNumero(int) = 0;
};
class Pagina : IPagina{
    private:
        string contenido;
        int numero;
    public:
        Pagina(int, string);
        string getContenido() override;
        int getNumero() override;
        void setContenido(string) override;
        void setNumero(int) override;
};

Pagina::Pagina(int numero, string contenido){
    this -> numero = numero;
    this -> contenido = contenido;
}
string Pagina::getContenido(){return contenido;}
int Pagina::getNumero(){return numero;}
void Pagina::setContenido(string contenido){this -> contenido = contenido;}
void Pagina::setNumero(int numero){this -> numero = numero;}

class Libro{
    private:
        string titulo;
        long int isbn;
        string autor;
        int anioPublicacion;
        Pagina *paginas[10];
        int numPaginas;
    public:
        Libro(string, long, string, int);
        string getTitulo();
        void setTitulo(string);
        long getIsbn();
        void setIsbn(long);
        string getAutor();
        void setAutor(string);
        int getAnio();
        void setAnio(int);
        void setPagina(Pagina *pagina);
        void setNumPaginas(int num){this -> numPaginas = num;};
        void getPaginass(){
            for(int i = 0; i < numPaginas; i++){
                cout << "Pagina: " << paginas[i] -> getNumero() << endl;
                cout << paginas[i] -> getContenido() << endl;
            }
        };
};
Libro::Libro(string titulo, long isbn, string autor, int anioPublicacion){
    this -> titulo = titulo;
    this -> isbn = isbn;
    this -> autor = autor;
    this -> anioPublicacion = anioPublicacion;
    numPaginas = 0;
}
string Libro::getTitulo(){return titulo;}
void Libro::setTitulo(string titulo){this -> titulo = titulo;}
long Libro::getIsbn(){return isbn;}
void Libro::setIsbn(long isbn){this -> isbn = isbn;}
string Libro::getAutor(){return autor;}
void Libro::setAutor(string autor){this -> autor = autor;}
int Libro::getAnio(){return anioPublicacion;}
void Libro::setAnio(int anio){this -> anioPublicacion = anio;}
void Libro::setPagina(Pagina *pagina){
    paginas[numPaginas] = pagina;
    numPaginas ++;
}


int main(){
    Libro elPepe("El pepe", 81382382398742, "pEPE_123", 2025);
    Pagina pagina1(1, "Pepito era una vez un niño bla bla bla ...");
    Pagina pagina2(2, "Luego de mucho pepto logro escapar de ....");
    Pagina pagina3(3, "Y murio pepito, con una sonrisa ...");
    elPepe.setPagina(&pagina1);
    elPepe.setPagina(&pagina2);
    elPepe.setPagina(&pagina3);
    elPepe.getPaginass();

}
