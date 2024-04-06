#include <iostream>
#include <string>
#include <vector>
using namespace std;


//Usuario, proyecto, archivos, comentarios; gestionar, agregar, compartir
class IUsuario{
    public:
        virtual void login(string *id, string *contra) = 0;
        virtual void logout() = 0;
        virtual ~IUsuario(){};
};
class IProyecto{
    public:
        virtual void crear(string nomb, string desc) = 0;
        virtual void eliminar() = 0;
        virtual ~IProyecto(){};
};
class IArchivo{
    public:
        virtual void agregar() = 0;
        virtual void compartir() = 0;
        virtual void eliminar() = 0;
        virtual ~IArchivo(){};
};
class IComentario{
    public:
        virtual void comentar() = 0;
        virtual void eliminar() = 0;
        virtual ~IComentario(){};
};


class Usuario : public IUsuario{
    protected:
        string id;
        string contra;
    public:
        Usuario(string id, string contra){
            this->id = id;
            this->contra = contra;
        }
        void login(string *id, string *contra) override{
            if(this->id == *id && this->contra == *contra){
                cout << "Bienvenido " << this->id;
            }else{
                cout << "Usuario o contraseña incorrectos";
            }
        }
        void logout() override{
            cout << "Sesion cerrada";
        }
};
class Administrador : public Usuario{
    private:
        string id;
        string contra;
    public:
        Administrador(string id, string contra){
            this->id = id;
            this->contra = contra;
        }
};

class Proyecto : public IProyecto{
    public:
        string nombre;
        string descripcion;
        
        Proyecto(string nombre, string descripcion){
            this->nombre = nombre;
            this->descripcion = descripcion;
        }
        void crear(string nomb, string desc) override{
            cout << "Proyecto creado";
        }
};

class Comentario : public IComentario{
    public:
        string comentario;
        vector <Proyecto> proyectos;
        Comentario(string comentario){
            this->comentario = comentario;
        }
}; 

class Archivo : public IArchivo{
    public:
        string nombre;
        string extension;
        string contenido;
        Archivo(string nombre, string extension, string contenido){
            this->nombre = nombre;
            this->extension = extension;
            this->contenido = contenido;
        }
        void agregar() override{
            cout << "Archivo agregado";
        }
        void compartir() override{
            cout << "Archivo compartido";
        }
        void eliminar() override{
            cout << "Archivo eliminado";
        }
};

int main(){
    cout << "hola";
}