#include <iostream>
using namespace std;

class tienda{
    private:
        string nombre;
        string direccion;
        string telefono;
    public:
        tienda(string, string, string);
        void setNombre(string nombre_nuevo){nombre = nombre_nuevo;}
        string getNombre(){return nombre;}
        void setDireccion(string direccion_nueva){direccion = direccion_nueva;}
        string getDireccion(){return direccion;}
        void setTelefono(string telefono_nuevo){telefono = telefono_nuevo;}
        string getTelefono(){return telefono;}
};

tienda::tienda(string nombre_inicial, string direccion_inicial, string telefono_inicial){
    this -> nombre = nombre_inicial;
    this -> direccion = direccion_inicial;
    this -> telefono = telefono_inicial;
}

class producto{
    private:
        string nombre;
        string descripcion;
        float precio;
        int cantidad;
    public:
        producto(string, string, float, int);
        void setNombre(string nombre_nuevo){nombre = nombre_nuevo;}
        string getNombre(){return nombre;}
        void setDescripcion(string descripcion_nueva){descripcion = descripcion_nueva;}
        string getDescripcion(){return descripcion;}
        void setPrecio(float precio_nuevo){precio = precio_nuevo;}
        float getPrecio(){return precio;}
        void setCantidad(int cantidad_nueva){cantidad = cantidad_nueva;}
        int getCantidad(){return cantidad;}
};

producto::producto(string nombre_inicial, string descripcion_inicial, float precio_inicial, int cantidad_inicial){
    this -> nombre = nombre_inicial;
    this -> descripcion = descripcion_inicial;
    this -> precio = precio_inicial;
    this -> cantidad = cantidad_inicial;
}

int main(){
    tienda* tienda1 = new tienda("Tienda Pepito", "Calle los Chuyos", "902177449");
    producto* producto1 = new producto("chorizon", "20 cm de sabor", 15, 3);
    cout << "Nombre de la tienda: " << tienda1 -> getNombre() << endl;
    cout << "Direccion de la tienda: " << tienda1 -> getDireccion() << endl;
    cout << "Telefono de la tienda: " << tienda1 -> getTelefono() << endl;
    cout << "Nombre del producto: " << producto1 -> getNombre() << endl;
    cout << "Descripcion del producto: " << producto1 -> getDescripcion() << endl;
    cout << "Precio del producto: " << producto1 -> getPrecio() << endl;
    cout << "Cantidad del producto: " << producto1 -> getCantidad() << endl;
    return 0;
}
