#include <iostream>

using namespace std;

class IPersonaje{
    public:
        string nombre;
        string personalidad;
        IPersonaje(string _personalidad, string _nombre) : personalidad(_personalidad), nombre(_nombre){}
        void correr(){
            cout << nombre << " esta corriendo\n";
        }
        void gritar(){
            cout << nombre << " esta gritando\n";
        }
        void escapar(){
            cout << nombre << " esta escapando\n";
        }
};

class Cazador : public IPersonaje{
    public:
        Cazador(): IPersonaje("Valiente", "Cazador"){}
        void protegerBosque(){
            cout << nombre << " esta protegiendo el bosque\n";
        }
        void rescatarCaperucita(){
            cout << nombre << " esta rescatando a la caperucita mientra pelea epicamente\n";
        }
};

class Caperucita : public IPersonaje{
    public:
        Caperucita():IPersonaje("Inocente", "Caperucita Roja"){}
        void caminarBosque(){
            cout << nombre << " esta caminando por el bosque\n";
        }
        void visitarAbuela(){
            cout << nombre << " va a visitara su abuela\n";
        }
        void interactuar(IPersonaje *personaje){
            cout << nombre << " esta interactuando con " <<  personaje -> nombre << endl;
        }
};

class Lobo : public IPersonaje{
    public:
        Lobo(): IPersonaje("Malvado", "Lobo"){}
        void disfrazar(){
            cout << nombre << " esta disfrazandose\n";
        }
        void acechar(){
            cout << nombre << " esta acechando\n";
        }
        void engañar(IPersonaje *personaje){
            cout << nombre << " esta engañando a " << personaje -> nombre << endl;
        }
        void devorar(IPersonaje *personaje){
            cout << nombre << " esta devorando a " << personaje -> nombre << endl;
        }
};

class abuela : public IPersonaje{
    public:
        abuela(): IPersonaje("Sabia", "Abuela"){}
        void recibirRegalo(){
            cout << nombre << " esta recibiendo un regalo\n";
        }
        void esperarVisita(){
            cout << nombre << " esta esperando a su nieta\n";
        }
};

class Casa{
    private:
        string material;
        string dueño;
    public:
        Casa(string _material, string _dueño): material(_material), dueño(_dueño){}
        void abrirPuerta(){
            cout << "La puerta de la casa se esta abriendo\n";
        }
};

int main(){
    Lobo *lobo = new Lobo();
    Caperucita *cape = new Caperucita();
    cape -> interactuar(lobo);
}