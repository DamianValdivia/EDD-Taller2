#include "Ranking.h"

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
    std::cout << "\n=== TOP 10 CANCIONES ===" << std::endl;
    Cancion** elementos = heapCanciones->obtenerElementos();
    
    int cantidad = 0;
    while (cantidad < 10 && cantidad < heapCanciones->obtenerTamanio()) {
        std::cout << cantidad + 1 << ". ";
        elementos[cantidad]->mostrar();
        cantidad++;
    }
}

void Ranking::mostrarTop10Artistas() {
    std::cout << "\n=== TOP 10 ARTISTAS ===" << std::endl;
    Cancion** elementos = heapArtistas->obtenerElementos();
    
    int cantidad = 0;
    while (cantidad < 10 && cantidad < heapArtistas->obtenerTamanio()) {
        std::cout << cantidad + 1 << ". " << elementos[cantidad]->getNombre() 
                  << " (" << elementos[cantidad]->getReproducciones() << " reproducciones)" << std::endl;
        cantidad++;
    }
}
