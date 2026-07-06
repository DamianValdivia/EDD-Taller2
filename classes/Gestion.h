#ifndef GESTION_H
#define GESTION_H

#include "../data_structures/ListaCancion.h"
#include "../data_structures/AVLCancion.h"
#include "../data_structures/Trie.h"
#include "../data_structures/HeapCancion.h"
#include "Cancion.h"
#include "Busqueda.h"
#include "Ranking.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

class Gestion {
private:
    ListaCancion* canciones;
    AVLCancion* cancionesPorArtista;
    Busqueda* busqueda;
    Ranking* ranking;
    int proximoIdCancion;

public:
    Gestion();
    ~Gestion();

    void cargarCancionesDesdeArchivo(const char* archivo);
    void guardarCancionesEnArchivo(const char* archivo);
    void mostrarTodasLasCanciones();
    void reproducirCancion(int idCancion);
    void buscarCancion(const char* prefijo);
    void mostrarTop10();
    ListaCancion* getCanciones();
    
    void mostrarCancionesDeArtistaAlfabetico(const char* artista);
};

#endif // GESTION_H
