#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

void titulo();
void eleccion(char *caracter, char);
void dibujar_tabla(vector<vector<string>> tabla);
void selec_casilla(vector<vector<string>> tabla);
bool comprobar_jugador(vector<vector<string>> tabla, char);
bool comprobar_bot(vector<vector<string>> tabla, char);
int main(){
    titulo();
    srand(time(NULL));
    char bot = 97 + rand() % 26;
    char jugador;
    bool gano;
    eleccion(&jugador, bot);
    cout << "====================JUGADORES======================\n";
    cout << "                  " <<jugador<<"    VS     "<<bot<<"             \n";
    cout << "===================================================\n";
    vector<vector<string>> tabla(4, vector<string>(4, "0"));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            string valor = to_string(i * 4 + j + 1);
            tabla[i][j] = valor;
        }
    }
    dibujar_tabla(tabla);
    selec_casilla(tabla);
    do {
    selec_casilla(tabla);
    gano = comprobar_jugador(tabla, jugador);
    gano = comprobar_bot(tabla, bot);
    } while(gano == true);
}

void titulo(){
cout << "|''||''|               |''||''|                  |''||''|                     /||                   /||   \n";
cout << "   ||     ''              ||                        ||                      // ||                 // ||   \n";
cout << "   ||     ||  .|'',       ||     '''|.  .|'',       ||    .|''|, .|''|,    //..||..    \\ /       //..||.. \n";
cout << "   ||     ||  ||          ||    .|''||  ||          ||    ||  || ||..||        ||       ><           ||   \n";
cout << "  .||.   .||. `|..'      .||.   `|..||. `|..'      .||.   `|..|' `|...         ||      / \\           ||   "<< endl;
}

void eleccion(char *caracter, char bot){
    cout << 
    "------------------------------\n";
    cout <<
    "INGRESA TU CARACTER PARA JUGAR\n";
    cout <<
    "-------------------------------\n";
    cin >> *caracter;
    while (*caracter == bot){
        cout << "Caracter ya escojido por el bot" << endl;
        cin >> *caracter;
    }
}
void dibujar_tabla(vector<vector<string>> tabla){
    cout << "+-----------------------+" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "|     "<<"|     "<< "|     " <<"|     |"<< endl;
        for (int j = 0; j < 4; j++) {
            (i >= 2 && tabla[i][j] != "9") ? cout <<"|  " << tabla[i][j] << " ": cout << "|  " << tabla[i][j] << "  ";
        }
        cout << "|\n|     |     |     |     |";
        cout << "\n+-----+-----+-----+-----+";
        cout << endl;
    }
}
void selec_casilla(vector<vector<string>> tabla){
    string casilla;
    cout << "E S C O J E   T U   C A S I L L A: ";
    cin >> casilla;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            (tabla[i][j] == casilla) ? tabla[i][j] = casilla : tabla[i][j] = tabla[i][j];
        }
    }
}

bool comprobar_jugador(vector<vector<string>> tabla, string jugador){
    for (int i = 0; i < 4; i++) {
        if ((tabla[i][0] == jugador) && (tabla[i][1] == jugador) && (tabla[i][2] == jugador)) {
            return true;
        }
        if ((tabla[0][i] == jugador) && (tabla[1][i] == jugador) && (tabla[2][i] == jugador)) {
            return true;
        }
    }
    if ((tabla[0][0] == jugador) && (tabla[1][1] == jugador) && (tabla[2][2] == jugador)) {
        return true;
    }
    if ((tabla[0][3] == jugador) && (tabla[1][2] == jugador) && (tabla[2][1] == jugador)) {
        return true;
    }
    return false;
}
bool comprobar_bot(vector<vector<string>> tabla, string bot){
    for (int i = 0; i < 4; i++) {
        if ((tabla[i][0] == bot) && (tabla[i][1] == bot) && (tabla[i][2] == bot)) {
            return true;
        }
        if ((tabla[0][i] == bot) && (tabla[1][i] == bot) && (tabla[2][i] == bot)) {
            return true;
        }
    }
    if ((tabla[0][0] == bot) && (tabla[1][1] == bot) && (tabla[2][2] == bot)) {
        return true;
    }
    if ((tabla[0][3] == bot) && (tabla[1][2] == bot) && (tabla[2][1] == bot)) {
        return true;
    }
    return false;
}