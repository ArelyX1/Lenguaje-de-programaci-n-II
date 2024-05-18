#include "complementos/validaEntero.h"
#include "complementos/validaFloat.h"
#include "complementos/sha256.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;




int main() {
    string msg;
	while (1) {
		cout << "Escribe el mensaje:\n";
		cin >> ws;
		getline(cin, msg);

		string nuevo = SHA256::cifrar(msg);
		cout << "\nHash resultante: " << nuevo;  
		cout << "\n";
	}
    exit(0);
}