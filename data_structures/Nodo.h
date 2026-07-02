#ifndef NODO_H
#define NODO_H

template <typename T>
struct Nodo {
    T dato;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(const T& d) : dato(d), siguiente(nullptr), anterior(nullptr) {}
};

template <typename T>
struct NodoArbol {
    T dato;
    NodoArbol* izquierda;
    NodoArbol* derecha;
    int altura;

    NodoArbol(const T& d) : dato(d), izquierda(nullptr), derecha(nullptr), altura(1) {}
};

struct NodoTrie {
    NodoTrie* hijos[36];  // 26 letras + 10 dígitos
    bool esFinPalabra;

    NodoTrie() : esFinPalabra(false) {
        for (int i = 0; i < 36; i++) {
            hijos[i] = nullptr;
        }
    }
};

#endif // NODO_H
