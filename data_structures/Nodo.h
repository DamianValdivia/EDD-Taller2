#ifndef NODO_H
#define NODO_H

class Cancion;

struct NodoCancion {
    Cancion* dato;
    NodoCancion* siguiente;
    NodoCancion* anterior;

    NodoCancion(Cancion* d);
    ~NodoCancion();
};

struct NodoCadena {
    char* dato;
    NodoCadena* siguiente;
    NodoCadena* anterior;

    NodoCadena(const char* d);
    ~NodoCadena();
};

struct NodoArbolCancion {
    Cancion* dato;
    NodoArbolCancion* izquierda;
    NodoArbolCancion* derecha;
    int altura;

    NodoArbolCancion(Cancion* d);
    ~NodoArbolCancion();
};

struct NodoTrie {
    NodoTrie* hijos[36];
    bool esFinPalabra;
    int frecuencia;
    char cancionOriginal[256];

    NodoTrie();
    ~NodoTrie();
};

#endif // NODO_H
