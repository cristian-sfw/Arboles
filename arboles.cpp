
#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;
};

Nodo* crearNodo(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->izquierda = nullptr;
    nuevo->derecha = nullptr;
    return nuevo;
}

Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == nullptr) {
        return crearNodo(valor);
    }

    if (valor < raiz->dato) {
        raiz->izquierda = insertar(raiz->izquierda, valor);
    } else if (valor > raiz->dato) {
        raiz->derecha = insertar(raiz->derecha, valor);
    }

    return raiz;
}

void preorden(Nodo* raiz) {
    if (raiz != nullptr) {
        cout << raiz->dato << " ";
        preorden(raiz->izquierda);
        preorden(raiz->derecha);
    }
}

void inorden(Nodo* raiz) {
    if (raiz != nullptr) {
        inorden(raiz->izquierda);
        cout << raiz->dato << " ";
        inorden(raiz->derecha);
    }
}

void posorden(Nodo* raiz) {
    if (raiz != nullptr) {
        posorden(raiz->izquierda);
        posorden(raiz->derecha);
        cout << raiz->dato << " ";
    }
}

int main() {
    Nodo* raiz = nullptr;
    int numero;

    cout << "Ingrese 5 numeros para el arbol:\n";

    for (int i = 0; i < 5; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> numero;
        raiz = insertar(raiz, numero);
    }

    cout << "\nRecorrido Preorden: ";
    preorden(raiz);

    cout << "\nRecorrido Inorden: ";
    inorden(raiz);

    cout << "\nRecorrido Posorden: ";
    posorden(raiz);

    cout << endl;

    return 0;
}

