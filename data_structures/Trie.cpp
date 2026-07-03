#include "Trie.h"

int Trie::obtenerIndice(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    if (c >= 'A' && c <= 'Z') return c - 'A';
    if (c >= '0' && c <= '9') return 26 + (c - '0');
    return -1;
}

char Trie::obtenerCaracter(int indice) {
    if (indice < 26) return 'a' + indice;
    if (indice < 36) return '0' + (indice - 26);
    return ' ';
}

void Trie::convertirMinusculas(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void Trie::buscarAux(NodoTrie* nodo, const char* prefijo, char* actual, int profundidad, ListaCadena& resultados) {
    if (nodo == nullptr) return;

    if (nodo->esFinPalabra) {
        actual[profundidad] = '\0';
        resultados.agregar(actual);
    }

    for (int i = 0; i < 36; i++) {
        if (nodo->hijos[i] != nullptr) {
            actual[profundidad] = obtenerCaracter(i);
            buscarAux(nodo->hijos[i], prefijo, actual, profundidad + 1, resultados);
        }
    }
}

void Trie::limpiarAux(NodoTrie* nodo) {
    if (nodo == nullptr) return;
    for (int i = 0; i < 36; i++) {
        limpiarAux(nodo->hijos[i]);
    }
    delete nodo;
}

Trie::Trie() {
    raiz = new NodoTrie();
}

Trie::~Trie() {
    limpiar();
}

void Trie::insertar(const char* palabra) {
    char temp[256];
    strcpy(temp, palabra);
    convertirMinusculas(temp);

    NodoTrie* actual = raiz;
    for (int i = 0; temp[i]; i++) {
        int indice = obtenerIndice(temp[i]);
        if (indice == -1) continue;

        if (actual->hijos[indice] == nullptr) {
            actual->hijos[indice] = new NodoTrie();
        }
        actual = actual->hijos[indice];
    }
    actual->esFinPalabra = true;
    actual->frecuencia++;
}

bool Trie::buscar(const char* palabra) {
    char temp[256];
    strcpy(temp, palabra);
    convertirMinusculas(temp);

    NodoTrie* actual = raiz;
    for (int i = 0; temp[i]; i++) {
        int indice = obtenerIndice(temp[i]);
        if (indice == -1) continue;

        if (actual->hijos[indice] == nullptr) {
            return false;
        }
        actual = actual->hijos[indice];
    }
    return actual->esFinPalabra;
}

void Trie::buscarPorPrefijo(const char* prefijo, ListaCadena& resultados) {
    char temp[256];
    strcpy(temp, prefijo);
    convertirMinusculas(temp);

    NodoTrie* actual = raiz;
    for (int i = 0; temp[i]; i++) {
        int indice = obtenerIndice(temp[i]);
        if (indice == -1) continue;

        if (actual->hijos[indice] == nullptr) {
            return;
        }
        actual = actual->hijos[indice];
    }

    char buffer[256];
    strcpy(buffer, temp);
    buscarAux(actual, temp, buffer, strlen(temp), resultados);
}

void Trie::limpiar() {
    limpiarAux(raiz);
    raiz = new NodoTrie();
}
