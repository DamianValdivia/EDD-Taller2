#ifndef AVL_CANCION_H
#define AVL_CANCION_H

#include "Nodo.h"
#include "ListaCancion.h"
#include <iostream>
#include <algorithm>
#include <cstring>

class Cancion;

class AVLCancion {
private:
    NodoArbolCancion* raiz;

    int obtenerAltura(NodoArbolCancion* nodo);
    int obtenerBalance(NodoArbolCancion* nodo);
    void actualizarAltura(NodoArbolCancion* nodo);
    NodoArbolCancion* rotarDerecha(NodoArbolCancion* y);
    NodoArbolCancion* rotarIzquierda(NodoArbolCancion* x);
    NodoArbolCancion* insertarAux(NodoArbolCancion* nodo, Cancion* cancion);
    void inOrdenAux(NodoArbolCancion* nodo, ListaCancion& resultado);
    void limpiarAux(NodoArbolCancion* nodo);

public:
    AVLCancion();
    ~AVLCancion();

    void insertar(Cancion* cancion);
    void inOrden(ListaCancion& resultado);
    void limpiar();
    bool estaVacio() const;
};

#endif // AVL_CANCION_H
