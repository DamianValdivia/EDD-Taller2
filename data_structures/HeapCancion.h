#ifndef HEAP_CANCION_H
#define HEAP_CANCION_H

#include <iostream>
#include "../classes/Cancion.h"

class HeapCancion {
private:
    Cancion** elementos;
    int tamanio;
    int capacidad;

    int obtenerPadre(int i);
    int obtenerHijoIzq(int i);
    int obtenerHijoDer(int i);
    void intercambiar(int i, int j);
    void flotarArriba(int i);
    void hundirAbajo(int i);
    void redimensionar();

public:
    HeapCancion(int cap = 100);
    ~HeapCancion();

    void insertar(Cancion* cancion);
    Cancion* extraerMaximo();
    Cancion* obtenerMaximo() const;
    int obtenerTamanio() const;
    bool estaVacio() const;
    Cancion** obtenerElementos() const;
};

#endif // HEAP_CANCION_H
