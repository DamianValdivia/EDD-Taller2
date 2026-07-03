#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include "../data_structures/Trie.h"
#include "../data_structures/ListaCancion.h"
#include "../data_structures/ListaCadena.h"
#include "Cancion.h"
#include <iostream>
#include <cstring>

class Busqueda {
private:
    Trie* trieNombres;
    Trie* trieArtistas;
    ListaCancion* cancionesReferencia;

public:
    Busqueda();
    ~Busqueda();

    void setCancionesReferencia(ListaCancion* canciones);
    void indexarCancion(Cancion* cancion);
    void buscarCancionesPorNombre(const char* prefijo, ListaCancion& resultados);
    void buscarCancionesPorArtista(const char* prefijo, ListaCancion& resultados);
};

#endif // BUSQUEDA_H
