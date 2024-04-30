#include <iostream>
#include <vector>
#include <memory>
#include <chrono>
#include <ctime>

using namespace std;

class Tarea {
private:
    string titulo;
    string descripcion;
    chrono::system_clock::time_point fechaLimite;
    bool completada;

public:
    Tarea(const string& titulo, const string& descripcion, const chrono::system_clock::time_point& fechaLimite)
        : titulo(titulo), descripcion(descripcion), fechaLimite(fechaLimite), completada(false) {}

    const string& getTitulo() const { return titulo; }
    const string& getDescripcion() const { return descripcion; }
    const chrono::system_clock::time_point& getFechaLimite() const { return fechaLimite; }
    bool estaCompletada() const { return completada; }

    void completar() { completada = true; }
    bool vencida() const {
        auto ahora = chrono::system_clock::now();
        return ahora > fechaLimite;
    }
};

class RepositorioTareas {
private:
    vector<shared_ptr<Tarea>> tareas;

public:
    void agregar(const shared_ptr<Tarea>& tarea) {
        tareas.push_back(tarea);
    }

    vector<shared_ptr<Tarea>> getTareasPendientes() const {
        vector<shared_ptr<Tarea>> pendientes;
        for (const auto& tarea : tareas) {
            if (!tarea->estaCompletada() && !tarea->vencida()) {
                pendientes.push_back(tarea);
            }
        }
        return pendientes;
    }

    vector<shared_ptr<Tarea>> getTareasVencidas() const {
        vector<shared_ptr<Tarea>> vencidas;
        for (const auto& tarea : tareas) {
            if (!tarea->estaCompletada() && tarea->vencida()) {
                vencidas.push_back(tarea);
            }
        }
        return vencidas;
    }
};

class ServicioTareas {
private:
    RepositorioTareas repositorio;

public:
    void crearTarea(const string& titulo, const string& descripcion, int anio, int mes, int dia, int hora, int minuto, int segundo) {
        auto fechaLimite = chrono::system_clock::from_time_t(mktime(&tm{0, 0, 0, dia, mes - 1, anio - 1900, 0, 0, -1}));
        auto tarea = make_shared<Tarea>(titulo, descripcion, fechaLimite);
        repositorio.agregar(tarea);
    }

    vector<shared_ptr<Tarea>> getTareasPendientes() const {
        return repositorio.getTareasPendientes();
    }

    vector<shared_ptr<Tarea>> getTareasVencidas() const {
        return repositorio.getTareasVencidas();
    }
};

void mostrarTareas(const vector<shared_ptr<Tarea>>& tareas) {
    if (tareas.empty()) {
        cout << "No hay tareas pendientes." << endl;
    } else {
        for (const auto& tarea : tareas) {
            cout << "- " << tarea->getTitulo() << endl;
        }
    }
}

int main() {
    ServicioTareas servicio;

    // Crear tarea
    servicio.crearTarea("Comprar pan", "Pan integral", 2023, 4, 9, 12, 0, 0);

    // Mostrar tareas pendientes
    vector<shared_ptr<Tarea>> pendientes = servicio.getTareasPendientes();
    mostrarTareas(pendientes);

    // Mostrar tareas vencidas
    vector<shared_ptr<Tarea>> vencidas = servicio.getTareasVencidas();
    mostrarTareas(vencidas);

    return 0;
}