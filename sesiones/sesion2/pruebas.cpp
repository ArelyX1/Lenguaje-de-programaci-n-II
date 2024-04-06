#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Usuario, proyecto, archivos, comentarios; gestionar, agregar, compartir
class IUsuario {
public:
    virtual void login(const string& id, const string& contra) = 0;
    virtual void logout() = 0;
    virtual ~IUsuario() {}
};

class IProyecto {
public:
    virtual void crear(const string& nomb, const string& desc) = 0;
    virtual void eliminar() = 0;
    virtual ~IProyecto() {}
};

class IArchivo {
public:
    virtual void agregar() = 0;
    virtual void compartir() = 0;
    virtual void eliminar() = 0;
    virtual ~IArchivo() {}
};

class IComentario {
public:
    virtual void comentar() = 0;
    virtual void eliminar() = 0;
    virtual ~IComentario() {}
};

class Usuario : public IUsuario {
protected:
    string id;
    string contra;

public:
    Usuario(const string& id, const string& contra) : id(id), contra(contra) {}

    void login(const string& id, const string& contra) override {
        if (this->id == id && this->contra == contra) {
            cout << "Bienvenido " << this->id << endl;
        } else {
            cout << "Usuario o contraseña incorrectos" << endl;
        }
    }

    void logout() override {
        cout << "Sesion cerrada" << endl;
    }
};

class Administrador : public Usuario {
public:
    Administrador(const string& id, const string& contra) : Usuario(id, contra) {}
};

class Proyecto : public IProyecto {
public:
    string nombre;
    string descripcion;

    Proyecto(const string& nomb, const string& desc) : nombre(nomb), descripcion(desc) {}

    void crear(const string& nomb, const string& desc) override {
        cout << "Proyecto creado" << endl;
    }
};

class Comentario : public IComentario {
public:
    string comentario;
    vector<Proyecto> proyectos;

    Comentario(const string& comentario) : comentario(comentario) {}

    void comentar() override {
        cout << "Comentario agregado: " << this->comentario << endl;
    }

    void eliminar() override {
        cout << "Comentario eliminado" << endl;
    }
};

class Archivo : public IArchivo {
public:
    string nombre;
    string extension;
    string contenido;

    Archivo(const string& nombre, const string& extension, const string& contenido)
        : nombre(nombre), extension(extension), contenido(contenido) {}

    void agregar() override {
        cout << "Archivo agregado" << endl;
    }

    void compartir() override {
        cout << "Archivo compartido" << endl;
    }

    void eliminar() override {
        cout << "Archivo eliminado" << endl;
    }
};

int main() {
    cout << "Hola" << endl;

    Usuario usuario("usuario1", "contraseña1");
    Proyecto proyecto("Proyecto 1", "Descripción del proyecto 1");
    Comentario comentario("Comentario 1");
    Archivo archivo("Archivo 1", "txt", "Contenido del archivo 1");

    usuario.login("usuario1", "contraseña1");
    proyecto.crear("Proyecto 1", "Descripción del proyecto 1");
    comentario.comentar();
    archivo.agregar();
    usuario.logout();

    return 0;
}