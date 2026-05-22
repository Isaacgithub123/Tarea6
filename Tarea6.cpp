#include <iostream>
#include <cstdlib>
#include <ctime>
#include "LinkedList.h"
#include "Bucket.h"
using namespace std;

void radixSort(LinkedList<int>& lista, int base) {
    if (lista.getSize() <= 1)
        return;

    lista.moveToStart();
    int maximo = lista.getValue();
    for (int i = 0; i < lista.getSize(); i++) {
        int valor = lista.getValue();
        if (valor > maximo)
            maximo = valor;
        lista.next();
    }

    for (int exp = 1; maximo / exp > 0; exp *= base) {
        Bucket<int> buckets(base);

        lista.moveToStart();
        for (int i = 0; i < lista.getSize(); i++) {
            int valor = lista.getValue();
            int digito = (valor / exp) % base;
            buckets.add(digito, valor);
            lista.next();
        }

        lista.clear();

        for (int i = 0; i < buckets.size(); i++) {
            LinkedList<int>& cubeta = buckets.get(i);
            cubeta.moveToStart();
            for (int j = 0; j < cubeta.getSize(); j++) {
                lista.append(cubeta.getValue());
                cubeta.next();
            }
        }
    }
}

int main() {
    char repetir;

    do {
        int tamanoLista;
        cout << "INGRESE EL TAMAÑO DE LA LISTA A ORDENAR: ";
        cin >> tamanoLista;

        int baseNumerica;
        cout << "INGRESE LA BASE NUMÉRICA A UTILIZAR: ";
        cin >> baseNumerica;

        LinkedList<int> lista;

        srand(time(NULL));
        cout << "\nNÚMEROS GENERADOS: ";
        for (int i = 0; i < tamanoLista; i++) {
            int numero = rand() % 1000;
            lista.append(numero);
            cout << numero << " ";
        }
        cout << endl;

        cout << "\nLISTA ORIGINAL:" << endl;
        lista.print();

        radixSort(lista, baseNumerica);

        cout << "\nLISTA ORDENADA:" << endl;
        lista.print();

        cout << "\n¿DESEA REPETIR? (s/n): ";
        cin >> repetir;

    } while (repetir == 's' || repetir == 'S');

    return 0;
}