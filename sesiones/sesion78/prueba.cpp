#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    string filename = "data.csv";
    string line_to_modify = "5,John,Doe,john.doe@example.com";
    string new_line = "2,Jane,Doe,jane.doe@example.com";

    // Crear el archivo CSV
    ofstream file(filename, ios::out);
    if (!file.is_open()) {
        cerr << "Error al crear el archivo: " << filename << endl;
        return 1;
    }

    // Escribir algunas líneas de ejemplo en el archivo
    file << "1,Alice,Smith,alice.smith@example.com\n";
    file << line_to_modify << "\n";
    file << "3,Bob,Johnson,bob.johnson@example.com\n";
    file.close();

    // Abrir el archivo en modo de lectura y escritura
    fstream file_rw(filename, ios::in | ios::out | ios::ate);
    if (!file_rw.is_open()) {
        cerr << "Error al abrir el archivo: " << filename << endl;
        return 1;
    }

    // Buscar la línea a modificar
    file_rw.seekg(0, ios::beg);
    string current_line;
    bool found = false;
    int line_number = 0;
    vector<string> lines;
    while (getline(file_rw, current_line)) {
        line_number++;
        lines.push_back(current_line);
        if (current_line == line_to_modify) {
            found = true;
        }
    }

    if (!found) {
        cerr << "No se encontró la línea a modificar: " << line_to_modify << endl;
        file_rw.close();
        return 1;
    }

    // Preguntar al usuario si desea modificar la línea
    char modify_line;
    cout << "¿Desea modificar la línea? (S/N): ";
    cin >> modify_line;

    if (tolower(modify_line) == 's') {
        // Modificar la línea y escribirla de vuelta al archivo
        file_rw.seekg(0, ios::beg);
        for (int i = 0; i < lines.size(); i++) {
            if (i == line_number - 1) {
                file_rw << new_line << "\n";
            } else {
                file_rw << lines[i] << "\n";
            }
        }
    } else {
        cout << "No se modificó la línea." << endl;
    }

    file_rw.close();
    return 0;
}