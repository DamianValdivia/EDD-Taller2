#include "HeapCancion.h"

int HeapCancion::obtenerPadre(int i) { return (i - 1) / 2; }

int HeapCancion::obtenerHijoIzq(int i) { return 2 * i + 1; }

int HeapCancion::obtenerHijoDer(int i) { return 2 * i + 2; }

void HeapCancion::intercambiar(int i, int j) {
    Cancion* temp = elementos[i];
    elementos[i] = elementos[j];
    elementos[j] = temp;
}

void HeapCancion::flotarArriba(int i) {
    while (i > 0 && elementos[obtenerPadre(i)]->getReproducciones() < elementos[i]->getReproducciones()) {
        intercambiar(i, obtenerPadre(i));
        i = obtenerPadre(i);
    }
}

void HeapCancion::hundirAbajo(int i) {
    int mayor = i;
    int izq = obtenerHijoIzq(i);
    int der = obtenerHijoDer(i);

    if (izq < tamanio && elementos[izq]->getReproducciones() > elementos[mayor]->getReproducciones()) {
        mayor = izq;
    }
    if (der < tamanio && elementos[der]->getReproducciones() > elementos[mayor]->getReproducciones()) {
        mayor = der;
    }

    if (mayor != i) {
        intercambiar(i, mayor);
        hundirAbajo(mayor);
    }
}

void HeapCancion::redimensionar() {
    capacidad *= 2;
    Cancion** nuevoArray = new Cancion*[capacidad];
    for (int i = 0; i < tamanio; i++) {
        nuevoArray[i] = elementos[i];
    }
    delete[] elementos;
    elementos = nuevoArray;
}

HeapCancion::HeapCancion(int cap) : tamanio(0), capacidad(cap) {
    elementos = new Cancion*[capacidad];
}

HeapCancion::~HeapCancion() {
    delete[] elementos;
}

void HeapCancion::insertar(Cancion* cancion) {
    if (tamanio == capacidad) {
        redimensionar();
    }
    elementos[tamanio] = cancion;
    flotarArriba(tamanio);
    tamanio++;
}

Cancion* HeapCancion::extraerMaximo() {
    if (tamanio == 0) {
        throw std::runtime_error("Heap vacio");
    }
    Cancion* maximo = elementos[0];
    elementos[0] = elementos[tamanio - 1];
    tamanio--;
    if (tamanio > 0) {
        hundirAbajo(0);
    }
    return maximo;
}

Cancion* HeapCancion::obtenerMaximo() const {
    if (tamanio == 0) {
        throw std::runtime_error("Heap vacio");
    }
    return elementos[0];
}

int HeapCancion::obtenerTamanio() const {
    return tamanio;
}

bool HeapCancion::estaVacio() const {
    return tamanio == 0;
}

Cancion** HeapCancion::obtenerElementos() const {
    return elementos;
}
