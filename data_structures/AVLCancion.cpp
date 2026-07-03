#include "AVLCancion.h"
#include "../classes/Cancion.h"

int AVLCancion::obtenerAltura(NodoArbolCancion* nodo) {
    return (nodo == nullptr) ? 0 : nodo->altura;
}

int AVLCancion::obtenerBalance(NodoArbolCancion* nodo) {
    return (nodo == nullptr) ? 0 : obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha);
}

void AVLCancion::actualizarAltura(NodoArbolCancion* nodo) {
    if (nodo != nullptr) {
        nodo->altura = 1 + std::max(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha));
    }
}

NodoArbolCancion* AVLCancion::rotarDerecha(NodoArbolCancion* y) {
    NodoArbolCancion* x = y->izquierda;
    NodoArbolCancion* T2 = x->derecha;

    x->derecha = y;
    y->izquierda = T2;

    actualizarAltura(y);
    actualizarAltura(x);

    return x;
}

NodoArbolCancion* AVLCancion::rotarIzquierda(NodoArbolCancion* x) {
    NodoArbolCancion* y = x->derecha;
    NodoArbolCancion* T2 = y->izquierda;

    y->izquierda = x;
    x->derecha = T2;

    actualizarAltura(x);
    actualizarAltura(y);

    return y;
}

NodoArbolCancion* AVLCancion::insertarAux(NodoArbolCancion* nodo, Cancion* cancion) {
    if (nodo == nullptr) {
        return new NodoArbolCancion(cancion);
    }

    int comparacion = strcmp(cancion->getArtista(), nodo->dato->getArtista());
    
    if (comparacion < 0) {
        nodo->izquierda = insertarAux(nodo->izquierda, cancion);
    } else if (comparacion > 0) {
        nodo->derecha = insertarAux(nodo->derecha, cancion);
    } else {
        return nodo;
    }

    actualizarAltura(nodo);
    int balance = obtenerBalance(nodo);

    if (balance > 1 && strcmp(cancion->getArtista(), nodo->izquierda->dato->getArtista()) < 0) {
        return rotarDerecha(nodo);
    }

    if (balance < -1 && strcmp(cancion->getArtista(), nodo->derecha->dato->getArtista()) > 0) {
        return rotarIzquierda(nodo);
    }

    if (balance > 1 && strcmp(cancion->getArtista(), nodo->izquierda->dato->getArtista()) > 0) {
        nodo->izquierda = rotarIzquierda(nodo->izquierda);
        return rotarDerecha(nodo);
    }

    if (balance < -1 && strcmp(cancion->getArtista(), nodo->derecha->dato->getArtista()) < 0) {
        nodo->derecha = rotarDerecha(nodo->derecha);
        return rotarIzquierda(nodo);
    }

    return nodo;
}

void AVLCancion::inOrdenAux(NodoArbolCancion* nodo, ListaCancion& resultado) {
    if (nodo == nullptr) return;
    inOrdenAux(nodo->izquierda, resultado);
    resultado.agregar(nodo->dato);
    inOrdenAux(nodo->derecha, resultado);
}

void AVLCancion::limpiarAux(NodoArbolCancion* nodo) {
    if (nodo == nullptr) return;
    limpiarAux(nodo->izquierda);
    limpiarAux(nodo->derecha);
    delete nodo;
}

AVLCancion::AVLCancion() : raiz(nullptr) {}

AVLCancion::~AVLCancion() {
    limpiarAux(raiz);
}

void AVLCancion::insertar(Cancion* cancion) {
    raiz = insertarAux(raiz, cancion);
}

void AVLCancion::inOrden(ListaCancion& resultado) {
    inOrdenAux(raiz, resultado);
}

void AVLCancion::limpiar() {
    limpiarAux(raiz);
    raiz = nullptr;
}

bool AVLCancion::estaVacio() const {
    return raiz == nullptr;
}
