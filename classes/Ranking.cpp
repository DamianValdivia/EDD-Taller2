#include "Ranking.h"
#include <iostream>
#include <cstring>

using namespace std;

Ranking::Ranking() {
    heapCanciones = new HeapCancion(100);
    heapArtistas = new HeapCancion(100);
}

Ranking::~Ranking() {
    delete heapCanciones;
    delete heapArtistas;
}

void Ranking::agregarCancionAlRanking(Cancion* cancion) {
    heapCanciones->insertar(cancion);
}

void Ranking::agregarArtistaAlRanking(Cancion* artistaPseudo) {
    heapArtistas->insertar(artistaPseudo);
}

void Ranking::obtenerTop10Canciones(ListaCancion& resultados) {
    Cancion** elementos = heapCanciones->obtenerElementos();
    
    int cantidad = 0;
    while (cantidad < 10 && cantidad < heapCanciones->obtenerTamanio()) {
        resultados.agregar(elementos[cantidad]);
        cantidad++;
    }
}

void Ranking::obtenerTop10Artistas(ListaCancion& resultados) {
    Cancion** elementos = heapArtistas->obtenerElementos();
    
    int cantidad = 0;
    while (cantidad < 10 && cantidad < heapArtistas->obtenerTamanio()) {
        resultados.agregar(elementos[cantidad]);
        cantidad++;
    }
}

void Ranking::mostrarTop10Canciones() {
    cout << "Ranking TOP 10 Canciones mas escuchadas:\n" << endl;
    Cancion** elementos = heapCanciones->obtenerElementos();
    
    int cantidad = 0;
    while (cantidad < 10 && cantidad < heapCanciones->obtenerTamanio()) {
        cout << " " << cantidad + 1 << ". [" 
             << elementos[cantidad]->getReproducciones() << "] " 
             << elementos[cantidad]->getNombre() << " - " 
             << elementos[cantidad]->getArtista() << endl;
        cantidad++;
    }
    
    cout << "\nOpciones:" << endl;
    cout << "R<num> - Reproducir cancion seleccionada" << endl;
    cout << "A<num> - Agregar cancion seleccionada al final de la lista de reproduccion actual" << endl;
    cout << "A - Top 10 artistas mas escuchados" << endl;
    cout << "V - Volver al menu principal" << endl;
}

void Ranking::mostrarTop10Artistas() {
    cout << "Ranking TOP 10 Artistas mas escuchados:\n" << endl;
    Cancion** elementos = heapArtistas->obtenerElementos();
    
    int cantidad = 0;
    while (cantidad < 10 && cantidad < heapArtistas->obtenerTamanio()) {
        cout << " " << cantidad + 1 << ". " << elementos[cantidad]->getArtista() << endl;
        cantidad++;
    }
    
    cout << "\nOpciones:" << endl;
    cout << "Seleccione el numero de artista para ver sus canciones o X para salir." << endl;
}
