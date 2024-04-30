#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <cstring>
#include <string>
#include <limits>
#include <stdexcept>
#include <cctype>
using namespace std;

chrono::system_clock::time_point valida_fecha(int mes, int dia, int hora);

int main(){
    time_t tiempo = chrono::system_clock::to_time_t(valida_fecha(1, 25, 15));
    struct tm *timeinfo = localtime(&tiempo);
    cout << "Fecha: " << put_time(timeinfo, "%B %dth, %I%p") << endl;
}

chrono::system_clock::time_point valida_fecha(int mes, int dia, int hora){
    tm tiempo ={};
    tiempo.tm_year = 2024 - 1900;
    tiempo.tm_mon = mes - 1;
    tiempo.tm_mday = dia;
    tiempo.tm_hour = hora;
    time_t tiempo_t = mktime(&tiempo);
    if(tiempo_t == -1) throw invalid_argument("Fecha y tiempo inválidos");
    return chrono::system_clock::from_time_t(tiempo_t);
}
