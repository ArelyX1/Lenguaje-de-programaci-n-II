#include "validaEntero.h"
#include "validaFloat.h"

#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>

using namespace std;

class Vector{
    private:
    vector<tuple<int, int>> vectorTuplas;

public:
    Vector(const vector<tuple<int, int>>& v) : vectorTuplas(v) {}

    Vector operator+(const Vector& other) {
        vector<tuple<int, int>> resultado(this->vectorTuplas.size());
        
        for (size_t i = 0; i < this->vectorTuplas.size(); i++) {
            int x1, y1, x2, y2;
            tie(x1, y1) = this->vectorTuplas[i];
            tie(x2, y2) = other.vectorTuplas[i];
            resultado[i] = make_tuple(x1 + x2, y1 + y2);
        }
        return Vector(resultado);
    }
    void mostrar(){
        for (const auto& tupla : this->vectorTuplas) {
            int x, y;
            tie(x, y) = tupla;
            cout << "(" << x << ", " << y << ")" << endl;
        }
    }
};

int main() {
    vector<tuple<int, int>> vect1 = {
        make_tuple(1, 2),
        make_tuple(3, 4)
    };
    
    vector<tuple<int, int>> vect2 = {
        make_tuple(5, 6),
        make_tuple(7, 8)
    };

    Vector vector1(vect1);
    Vector vector2(vect2);

    Vector suma = vector1 + vector2;
    suma.mostrar();
}