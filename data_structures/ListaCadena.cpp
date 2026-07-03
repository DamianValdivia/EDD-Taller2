#include "ListaCadena.h"
#include <cstring>

ListaCadena::ListaCadena() : cabeza(nullptr), cola(nullptr), tamanio(0) {}

ListaCadena::~ListaCadena() {
    limpiar();
}

void ListaCadena::agregar(const char* cadena) {
    NodoCadena* nuevo = new NodoCadena(cadena);
    if (cabeza == nullptr) {
        cabeza = cola = nuevo;
    } else {
        cola->siguiente = nuevo;
        nuevo->anterior = cola;
        cola = nuevo;
    }
    tamanio++;
}

void ListaCadena::agregarAlInicio(const char* cadena) {
    NodoCadena* nuevo = new NodoCadena(cadena);
    if (cabeza == nullptr) {
        cabeza = cola = nuevo;
    } else {
        nuevo->siguiente = cabeza;
        cabeza->anterior = nuevo;
        cabeza = nuevo;
    }
    tamanio++;
}

bool ListaCadena::eliminar(const char* cadena) {
    NodoCadena* actual = cabeza;
    while (actual != nullptr) {
        if (strcmp(actual->dato, cadena) == 0) {
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

int ListaCadena::obtenerTamanio() const {
    return tamanio;
}

NodoCadena* ListaCadena::obtenerCabeza() const {
    return cabeza;
}

NodoCadena* ListaCadena::obtenerCola() const {
    return cola;
}

void ListaCadena::limpiar() {
    NodoCadena* actual = cabeza;
    while (actual != nullptr) {
        NodoCadena* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
    cabeza = cola = nullptr;
    tamanio = 0;
}

bool ListaCadena::estaVacia() const {
    return tamanio == 0;
}
