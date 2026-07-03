#ifndef LISTA_CANCION_H
#define LISTA_CANCION_H

#include "Nodo.h"
#include <iostream>

class Cancion;

class ListaCancion {
private:
    NodoCancion* cabeza;
    NodoCancion* cola;
    int tamanio;

public:
    ListaCancion();
    ~ListaCancion();

    void agregar(Cancion* cancion);
    void agregarAlInicio(Cancion* cancion);
    bool eliminar(Cancion* cancion);
    int obtenerTamanio() const;
    NodoCancion* obtenerCabeza() const;
    NodoCancion* obtenerCola() const;
    void limpiar();
    bool estaVacia() const;
};

#endif // LISTA_CANCION_H
