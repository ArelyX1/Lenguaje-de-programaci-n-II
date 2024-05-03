#include <iostream>
#include <stdlib.h>

using namespace std;

class ICasa{
    public:
        string material;
        string resistencia;
        string color;
        string duenio;
        ICasa(string _material, string _resistencia, string _color, string _duenio) : material(_material), resistencia(_resistencia), color(_color), duenio(_duenio){}
        void soportarAtaque(){
            cout << "Casa esta soportando un ataque\n";
        }
        void destruir(){
            cout << "Casa esta siendo destruida\n";
        }
};

class ICerdo{
    public:
        string personalidad;
        ICasa *casa;
        string instrumento;
        ICerdo(ICasa *casa, string _personalidad, string _instrumento) : personalidad(_personalidad), instrumento(_instrumento), casa(casa){}
        void construirCasa(ICasa *casa){
            this -> casa = casa;
            cout << "Cerdo esta construyendo su casa\n";
        }
        void tocarInstrumento(){
            cout << "Cerdo esta cantando y tocando su " << instrumento << endl;
        }
        void cantar(){
            cout << "Cerdo esta cantando\n";
        }
        void bailar(){
            cout << "Cerdo esta bailando\n";
        }
        void correr(){
            cout << "Cerdo esta corriendo\n";
        }
        void caminar(){
            cout << "Cerdo esta caminando\n";
        }
        void huir(){
            cout << "Cerdo esta huyendo\n";
        }
        void gritar(){
            cout << "Cerdo esta gritando\n";
        }
        void reir(){
            cout << "Cerdo esta riendo\n";
        }
        void burlar(){
            cout << "Cerdo esta burlandose\n";
        }
        void escapar(){
            cout << "Cerdo esta escapando\n";
        }
};

class CasaLadrillo : public ICasa{
    public:
        CasaLadrillo(string _dueño) : ICasa("Ladrillo", "Fuerte", "Rojo", _dueño){}
};

class CasaPaja : public ICasa{
    public:
        CasaPaja(string _dueño) : ICasa("Paja", "Debil", "Amarillo", _dueño){}
};

class CasaMadera : public ICasa{
    public:
        CasaMadera(string _dueño) : ICasa("Madera", "Medio", "Cafe", _dueño){}
};

class CerdoPractico : public ICerdo{
    public:
        CerdoPractico(ICasa *casa): ICerdo(casa, "Practico", "Guitarra"){}
};

class CerdoFlautista : public ICerdo{
    public:
        CerdoFlautista(ICasa *casa): ICerdo(casa, "Musical", "Flauta"){}
};

class CerdoViolinista : public ICerdo{
    public:
        CerdoViolinista(ICasa *casa): ICerdo(casa, "Musical", "Violin"){}
};

class Lobo{
    public:
        string personalidad;
        Lobo(string _personalidad) : personalidad(_personalidad){}
        void soplar(ICasa *casa){
            cout << "Lobo esta soplando la casa\n";
            casa -> destruir();
        }
        void gritar(){
            cout << "Lobo esta gritando\n";
        }
        void hablar(){
            cout << "Lobo esta hablando\n";
        }
        void espiar(){
            cout << "Lobo esta espiando\n";
        }
        void empujar(){
            cout << "Lobo esta empujando\n";
        }
        void engañar(){
            cout << "Lobo esta engañando\n";
        }
        void mentir(){
            cout << "Lobo esta mintiendo\n";
        }
        void fingir(){
            cout << "Lobo esta fingiendo\n";
        }
        void reir(){
            cout << "Lobo esta riendo\n";
        }    
};

int main(){
    exit(0);
}