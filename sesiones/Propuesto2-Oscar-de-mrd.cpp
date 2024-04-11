#include <iostream>
#include <string>
#include <vector>  //Incluye la biblioteca de vectores

using namespace std;

//Definimos Clase Asignatura
class Asignatura {
public:
    string codigo;
    string nombre;
    string descripcion;
    string profesor;

    //Constructor de la clase Asignatura
    Asignatura(string codigo, string nombre, string descripcion, string profesor)
        : codigo(codigo), nombre(nombre), descripcion(descripcion), profesor(profesor) {}

    //Funcion para mostrar la informacion de la asignatura
    void mostrarInformacion() {
        cout<<"Asignatura: "<<nombre<<" ("<<codigo<<")"<<endl;
        cout<<"Descripcion: "<<descripcion<<endl;
        cout<<"Profesor: "<<profesor<<endl;
        cout<<endl;
    }
};

//Definimos Clase Estudiante
class Estudiante {
public:
    string nombre;
    string direccion;
    string matricula;
    vector<Asignatura> asignaturasMatriculadas; //Atributo asignaturasMatriculadas de tipo vector de Asignatura
    vector<int> notas;  //Atributo notas de tipo vector de enteros
    vector<int> faltas; //Atributo faltas de tipo vector de enteros

    //Constructor de la clase Estudiante
    Estudiante(string nombre, string direccion, string matricula)
        : nombre(nombre), direccion(direccion), matricula(matricula), notas(vector<int>(0)), faltas(vector<int>(0)) {}

    //Funcion para matricular una asignatura a un estudiante
    void matricularAsignatura(Asignatura asignatura) {
        asignaturasMatriculadas.push_back(asignatura);  //Añade una asignatura al vector de asignaturasMatriculadas
        notas.push_back(0); //Añade una nota de cero al vector de notas
        faltas.push_back(0); //Añade un número de faltas de cero al vector de faltas
    }

    //Funcion para registrar una nota en una asignatura
    void registrarNota(int nota, int asignaturaIndex) {
        notas[asignaturaIndex] = nota;  //Establece la nota en el indice correspondiente del vector de notas
    }

    //Funcion para registrar una falta en una asignatura
    void registrarFalta(int falta, int asignaturaIndex) {
        faltas[asignaturaIndex]++;  //Incrementa el numero de faltas en el índice correspondiente del vector de faltas
    }

    //Funcion para mostrar la informacion del estudiante
    void mostrarInformacion() {
        cout<<"Estudiante: "<<nombre<<" ("<<matricula<<")"<<endl;
        cout<<"Direccion: "<<direccion<<endl;
        cout<<"Asignaturas Matriculadas:"<<endl;
        for (int i = 0; i < asignaturasMatriculadas.size(); i++) { //Es el encabezado de un bucle for que itera sobre el vector asignaturasMatriculadas del objeto Estudiante
        //Nota: ".size" es un metodo de la clase vector en C++, que devuelve el número de elementos actualmente almacenados en el vector
            //Imprime un guion y un espacio antes de la informacion de cada asignatura
            cout << "  - ";
            asignaturasMatriculadas[i].mostrarInformacion();  //Muestra la informacion
        }
        cout << endl;
    }
};

//Definimos Clase Profesor
class Profesor {
public:
    string nombre;
    string direccion;
    string telefono;
    vector<Asignatura> asignaturasImpartidas;  //Atributo asignaturasImpartidas de tipo vector de Asignatura

    //Constructor de la clase Profesor
    Profesor(string nombre, string direccion, string telefono)
        : nombre(nombre), direccion(direccion), telefono(telefono) {}

    //Funcion para mostrar la informacion del profesor
    void mostrarInformacion() {
        cout<<"Profesor: "<<nombre<<" ("<<telefono<<")"<<endl; 
        cout<<"Direccion: "<<direccion<<endl;
        cout<<"Asignaturas Impartidas:"<<endl;
        for (int i = 0; i < asignaturasImpartidas.size(); i++) { //Es el encabezado de un bucle for que itera sobre el vector asignaturasImpartodas del objeto Profesor
        //Nota: ".size" es un metodo de la clase vector en C++, que devuelve el número de elementos actualmente almacenados en el vector
            cout << "  - ";
            asignaturasImpartidas[i].mostrarInformacion(); //Muestra la informacion
        }
        cout << endl;
    }
};

int main() {
    //Crear asignaturas
    Asignatura asignatura1("A1", "Programacion I", "Introduccion a la programacion", "Profesor Juan");
    Asignatura asignatura2("A2", "Matematicas I", "Introduccion a las matematicas", "Profesora Maria");

    //Crear profesores
    Profesor profesor1("Profesor Juan", "Direccion 1", "123456789");
    Profesor profesor2("Profesora Maria", "Direccion 2", "987654321");

    //Asignar asignaturas a los profesores
    profesor1.asignaturasImpartidas.push_back(asignatura1);
    profesor2.asignaturasImpartidas.push_back(asignatura2);

    //Crear estudiantes
    Estudiante estudiante1("Estudiante Esdras", "Dirección A", "1A");
    Estudiante estudiante2("Estudiante Miguel", "Dirección B", "2B");

    //Matricular estudiantes en las asignaturas
    estudiante1.matricularAsignatura(asignatura1);
    estudiante1.matricularAsignatura(asignatura2);
    estudiante2.matricularAsignatura(asignatura1);
    estudiante2.matricularAsignatura(asignatura2);

    //Mostrar información por el terminal
    cout<<"Informacion de Asignaturas:"<<endl;
    asignatura1.mostrarInformacion();
    asignatura2.mostrarInformacion();

    cout<<"Informacion de Profesores:"<<endl;
    profesor1.mostrarInformacion();
    profesor2.mostrarInformacion();

    cout<<"Informacion de Estudiantes:"<<endl;
    estudiante1.mostrarInformacion();
    estudiante2.mostrarInformacion();

  //Chequealo andry :monkeY:
    return 0;
}
