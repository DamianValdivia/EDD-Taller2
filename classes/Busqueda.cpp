#include "Busqueda.h"

Busqueda::Busqueda() {
    trieNombres = new Trie();
    trieArtistas = new Trie();
    cancionesReferencia = nullptr;
}

Busqueda::~Busqueda() {
    delete trieNombres;
    delete trieArtistas;
}

void Busqueda::setCancionesReferencia(ListaCancion* canciones) {
    cancionesReferencia = canciones;
}

void Busqueda::indexarCancion(Cancion* cancion) {
    trieNombres->insertar(cancion->getNombre());
    trieArtistas->insertar(cancion->getArtista());
}

void Busqueda::buscarCancionesPorNombre(const char* prefijo, ListaCancion& resultados) {
    if (cancionesReferencia == nullptr || cancionesReferencia->estaVacia()) {
        std::cout << "No hay canciones indexadas." << std::endl;
        return;
    }

    ListaCadena coincidencias;
    trieNombres->buscarPorPrefijo(prefijo, coincidencias);

    NodoCancion* actual = cancionesReferencia->obtenerCabeza();
    while (actual != nullptr) {
        NodoCadena* match = coincidencias.obtenerCabeza();
        while (match != nullptr) {
            if (strcmp(actual->dato->getNombre(), match->dato) == 0) {
                resultados.agregar(actual->dato);
                break;
            }
            match = match->siguiente;
        }
        actual = actual->siguiente;
    }
}

void Busqueda::buscarCancionesPorArtista(const char* prefijo, ListaCancion& resultados) {
    if (cancionesReferencia == nullptr || cancionesReferencia->estaVacia()) {
        std::cout << "No hay canciones indexadas." << std::endl;
        return;
    }

    ListaCadena coincidencias;
    trieArtistas->buscarPorPrefijo(prefijo, coincidencias);

    NodoCancion* actual = cancionesReferencia->obtenerCabeza();
    while (actual != nullptr) {
        NodoCadena* match = coincidencias.obtenerCabeza();
        while (match != nullptr) {
            if (strcmp(actual->dato->getArtista(), match->dato) == 0) {
                resultados.agregar(actual->dato);
                break;
            }
            match = match->siguiente;
        }
        actual = actual->siguiente;
    }
}
