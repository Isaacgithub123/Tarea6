#include <iostream>
#include <cstdlib>
#include <ctime>
#include "LinkedList.h"
using namespace std;

int main() {
    int tamanoLista;
    cout << "Ingrese el tamaño de la lista a ordenar: ";
    cin >> tamanoLista;

    int baseNumerica;
    cout << "Ingrese la base numérica a utilizar: ";
    cin >> baseNumerica;

    LinkedList<int> lista;

    srand(time(NULL));
    cout << "\nNúmeros generados: ";
    for (int i = 0; i < tamanoLista; i++) {
        int numero = rand() % 100;
        lista.append(numero);
        cout << numero << " ";
    }
    cout << endl;

    cout << "\nLista original:" << endl;
    lista.print();

    return 0;
}