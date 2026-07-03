#ifndef TRIE_H
#define TRIE_H

#include "Nodo.h"
#include "ListaCadena.h"
#include <iostream>
#include <cctype>
#include <cstring>

class Trie {
private:
    NodoTrie* raiz;

    int obtenerIndice(char c);
    char obtenerCaracter(int indice);
    void convertirMinusculas(char* str);
    void buscarAux(NodoTrie* nodo, const char* prefijo, char* actual, int profundidad, ListaCadena& resultados);
    void limpiarAux(NodoTrie* nodo);

public:
    Trie();
    ~Trie();

    void insertar(const char* palabra);
    bool buscar(const char* palabra);
    void buscarPorPrefijo(const char* prefijo, ListaCadena& resultados);
    void limpiar();
};

#endif // TRIE_H
