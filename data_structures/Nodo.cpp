#include "Nodo.h"
#include "../classes/Cancion.h"
#include <cstring>
#include <iostream>

NodoCancion::NodoCancion(Cancion* d) : dato(d), siguiente(nullptr), anterior(nullptr) {}

NodoCancion::~NodoCancion() {}

NodoCadena::NodoCadena(const char* d) : siguiente(nullptr), anterior(nullptr) {
    dato = new char[strlen(d) + 1];
    strcpy(dato, d);
}

NodoCadena::~NodoCadena() {
    if (dato) delete[] dato;
}

NodoArbolCancion::NodoArbolCancion(Cancion* d) : dato(d), izquierda(nullptr), derecha(nullptr), altura(1) {}

NodoArbolCancion::~NodoArbolCancion() {}

NodoTrie::NodoTrie() : esFinPalabra(false), frecuencia(0) {
    cancionOriginal[0] = '\0';
    for (int i = 0; i < 36; i++) {
        hijos[i] = nullptr;
    }
}

NodoTrie::~NodoTrie() {}
