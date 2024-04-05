#include <iostream>
#include <string>

class Producto {
public:
    Producto(const std::string& name, double price) : name_(name), price_(price) {}

    std::string getName() const { return name_; }
    double getPrice() const { return price_; }

private:
    std::string name_;
    double price_;
};

int main() {
    Producto producto("Ejemplo", 10.0);
    std::cout << "Nombre: " << producto.getName() << std::endl;
    std::cout << "Precio: " << producto.getPrice() << std::endl;
    return 0;
}