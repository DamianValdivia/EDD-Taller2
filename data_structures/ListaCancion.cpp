#include "ListaCancion.h"
#include "../classes/Cancion.h"

ListaCancion::ListaCancion() : cabeza(nullptr), cola(nullptr), tamanio(0) {}

ListaCancion::~ListaCancion() {
    limpiar();
}

void ListaCancion::agregar(Cancion* cancion) {
    NodoCancion* nuevo = new NodoCancion(cancion);
    if (cabeza == nullptr) {
        cabeza = cola = nuevo;
    } else {
        cola->siguiente = nuevo;
        nuevo->anterior = cola;
        cola = nuevo;
    }
    tamanio++;
}

void ListaCancion::agregarAlInicio(Cancion* cancion) {
    NodoCancion* nuevo = new NodoCancion(cancion);
    if (cabeza == nullptr) {
        cabeza = cola = nuevo;
    } else {
        nuevo->siguiente = cabeza;
        cabeza->anterior = nuevo;
        cabeza = nuevo;
    }
    tamanio++;
}

bool ListaCancion::eliminar(Cancion* cancion) {
    NodoCancion* actual = cabeza;
    while (actual != nullptr) {
        if (actual->dato == cancion) {
            if (actual->anterior != nullptr) {
                actual->anterior->siguiente = actual->siguiente;
            } else {
                cabeza = actual->siguiente;
            }
            if (actual->siguiente != nullptr) {
                actual->siguiente->anterior = actual->anterior;
            } else {
                cola = actual->anterior;
            }
            delete actual;
            tamanio--;
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

int ListaCancion::obtenerTamanio() const {
    return tamanio;
}

NodoCancion* ListaCancion::obtenerCabeza() const {
    return cabeza;
}

NodoCancion* ListaCancion::obtenerCola() const {
    return cola;
}

void ListaCancion::limpiar() {
    NodoCancion* actual = cabeza;
    while (actual != nullptr) {
        NodoCancion* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
    cabeza = cola = nullptr;
    tamanio = 0;
}

bool ListaCancion::estaVacia() const {
    return tamanio == 0;
}
