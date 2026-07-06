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
    while (i > 0) {
        int padre = obtenerPadre(i);
        bool necesitaFlotar = false;

       
        if (elementos[padre]->getReproducciones() < elementos[i]->getReproducciones()) {
            necesitaFlotar = true;
        }
       
        else if (elementos[padre]->getReproducciones() == elementos[i]->getReproducciones()) { //faltaba el ordewn alfabetico
            int compNombre = strcmp(elementos[padre]->getNombre(), elementos[i]->getNombre());
            if (compNombre > 0) { // El padre va después alfabéticamente, así que el menor sube
                necesitaFlotar = true;
            } else if (compNombre == 0) {
                
                if (strcmp(elementos[padre]->getArtista(), elementos[i]->getArtista()) > 0) { //sino artista
                    necesitaFlotar = true;
                }
            }
        }

        if (necesitaFlotar) {
            intercambiar(i, padre);
            i = padre;
        } else {
            break;
        }
    }
}

void HeapCancion::hundirAbajo(int i) {
    int mayor = i;
    int izq = obtenerHijoIzq(i);
    int der = obtenerHijoDer(i);

 
    if (izq < tamanio) {
        if (elementos[izq]->getReproducciones() > elementos[mayor]->getReproducciones()) {
            mayor = izq;
        } else if (elementos[izq]->getReproducciones() == elementos[mayor]->getReproducciones()) {
            int compNombre = strcmp(elementos[izq]->getNombre(), elementos[mayor]->getNombre());
            if (compNombre < 0) {
                mayor = izq;
            } else if (compNombre == 0) {
                if (strcmp(elementos[izq]->getArtista(), elementos[mayor]->getArtista()) < 0) {
                    mayor = izq;
                }
            }
        }
    }

   
    if (der < tamanio) {
        if (elementos[der]->getReproducciones() > elementos[mayor]->getReproducciones()) {
            mayor = der;
        } else if (elementos[der]->getReproducciones() == elementos[mayor]->getReproducciones()) {
            int compNombre = strcmp(elementos[der]->getNombre(), elementos[mayor]->getNombre());
            if (compNombre < 0) {
                mayor = der;
            } else if (compNombre == 0) {
                if (strcmp(elementos[der]->getArtista(), elementos[mayor]->getArtista()) < 0) {
                    mayor = der;
                }
            }
        }
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
