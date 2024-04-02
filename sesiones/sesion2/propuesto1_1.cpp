#include <iostream>
#include <vector>
using namespace std;

class Coche{
    private:
        string marca;
        string modelo;
        int anio;
        string color;
    public:
        Coche(string, string, int, string);
        void setMarca(string marca_nueva){marca = marca_nueva;}
        string getMarca(){return marca;}
        void setModelo(string modelo_nuevo){modelo = modelo_nuevo;}
        string getModelo(){return modelo;}
        void setAnio(int anio_nuevo){anio = anio_nuevo;}
        int getAnio(){return anio;}
        void setColor(string color_nuevo){color = color_nuevo;}
        string getColor(){return color;}
};

Coche::Coche(string marca_inicial, string modelo_inicial, int anio_inicial, string color_inicial){
    this -> marca = marca_inicial;
    this -> modelo = modelo_inicial;
    this -> anio = anio_inicial;
    this -> color = color_inicial;
}

int main(){
    vector<Coche> coches;
    Coche* toyota = new Coche("Toyota", "Corolla", 2020, "Blanco");
    coches.push_back(*toyota);
    Coche* honda = new Coche("Honda ", "Civic", 2019, "Neg ro");
    coches.push_back(*honda);
    Coche* ford = new Coche("Ford", "Fiesta", 2018, "Rojo");
    coches.push_back(*ford);
    for (size_t i = 0; i < coches.size(); i++){
        cout << "========================\n";
        cout << "Coche " << i + 1 << endl;
        cout << "========================\n";
        cout << "Marca: " << coches[i].getMarca() << endl;
        cout << "Modelo: " << coches[i].getModelo() << endl;
        cout << "Año: " << coches[i].getAnio() << endl;
        cout << "Color: " << coches[i].getColor() << endl;
    }
}