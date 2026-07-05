#ifndef RANKING_H
#define RANKING_H

#include "../data_structures/HeapCancion.h"
#include "../data_structures/ListaCancion.h"
#include "Cancion.h"
#include <iostream>

class Ranking {
private:
    HeapCancion* heapCanciones;
    HeapCancion* heapArtistas;

public:
    Ranking();
    ~Ranking();

    void agregarCancionAlRanking(Cancion* cancion);
    void agregarArtistaAlRanking(Cancion* artistaPseudo);
    void obtenerTop10Canciones(ListaCancion& resultados);
    void obtenerTop10Artistas(ListaCancion& resultados);
    void mostrarTop10Canciones();
    void mostrarTop10Artistas();
};

#endif // RANKING_H
