# Reproductor de Música C++ (Taller de Estructuras de Datos)

Este proyecto consiste en un sistema de reproducción y gestión de música desarrollado en C++. Está diseñado para operar eficientemente en memoria mediante la implementación de estructuras de datos avanzadas hechas a medida, minimizando el uso de la biblioteca estándar (`std`) y priorizando el manejo manual de memoria dinámica con punteros.

## Características Principales

* **Carga y Guardado Persistente**: Lectura y escritura de la base de datos musical desde un archivo de texto (`music_source.txt`) utilizando formatos basados en delimitadores.
* **Sistema de Búsqueda por Prefijos**: Indexación de canciones para búsquedas rápidas utilizando estructuras especializadas.
* **Módulo de Rankings (TOP 10)**: Determinación en tiempo real de las canciones y artistas más escuchados del sistema.
* **Navegación Interactiva**: Interfaz de consola segmentada por pantallas dinámicas comandadas por caracteres de control y comandos compuestos.

---

## Estructuras de Datos Utilizadas

Como no podiamos usar la libreria estándar, todas las estructuras están hechas a mano en la carpeta `data_structures`:

1. **Lista Doblemente Enlazada (`Lista.h`)**: La uso para la cola de reproducción y para el registro de todas las canciones, porque me permite moverme hacia adelante y atrás con los punteros `siguiente` y `anterior`.
2. **Árbol Trie (`Trie.h`)**: Lo uso para indexar los nombres de los temas y los artistas. Sirve para buscar súper rápido por prefijos.
3. **Árbol AVL (`AVLCancion.h`)**: Para ordenar las canciones por artista de forma balanceada.
4. **Max-Heap (`HeapCancion.h`)**: Lo uso para ordenar el ranking del Top 10 según la cantidad de reproducciones de cada canción.

---

## Cómo están organizados los archivos

```text
.
├── main.cpp
├── music_source.txt
├── classes/
│   ├── Cancion.h
│   ├── Cancion.cpp
│   ├── Ranking.h
│   ├── Ranking.cpp
│   ├── Busqueda.h
│   ├── Busqueda.cpp
│   ├── Gestion.h
│   └── Gestion.cpp
└── data_structures/
    ├── ListaCancion.h
    ├── ListaCancion.cpp
    ├── AVLCancion.h
    ├── AVLCancion.cpp
    ├── Trie.h
    ├── Trie.cpp
    ├── HeapCancion.h
    └── HeapCancion.cpp
