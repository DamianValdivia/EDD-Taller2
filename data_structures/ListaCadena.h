#ifndef LISTA_CADENA_H
#define LISTA_CADENA_H

#include "Nodo.h"
#include <iostream>

class ListaCadena {
private:
    NodoCadena* cabeza;
    NodoCadena* cola;
    int tamanio;

public:
    ListaCadena();
    ~ListaCadena();

    void agregar(const char* cadena);
    void agregarAlInicio(const char* cadena);
    bool eliminar(const char* cadena);
    int obtenerTamanio() const;
    NodoCadena* obtenerCabeza() const;
    NodoCadena* obtenerCola() const;
    void limpiar();
    bool estaVacia() const;
};

#endif // LISTA_CADENA_H
