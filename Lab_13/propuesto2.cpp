#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void printFor(int tama) {
        int elemento, suma = 0;
        for (Node* current = head; current != nullptr; current = current->next) {
            elemento = current->data;
            suma += elemento  % tama;
        }
        cout << suma << endl;
        for (Node* current = head; current != nullptr; current = current->next) {
            (current->data == suma) ? cout << "si hay un número en la lista que es igual a la suma de los resto" : cout << false;
        }
    }

    int size() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

private:
    Node* head;
};

int main() {
    LinkedList lista;
    int valor;

    cout << "Ingrese valores a la lista (0 para salir):" << endl;
    do {
        cin >> valor;
        if (valor != 0) {
            lista.insert(valor);
        }
    } while (valor != 0);

    cout << "Lista resultante: ";
    lista.print();
    cout << "La suma es de los restos es: ";
    int tama = lista.size();
    lista.printFor(tama);

    return 0;
}