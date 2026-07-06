# Reproductor de Música C++ (Taller de Estructuras de Datos)
**Integrantes:** Maximiliano Castillo y Damián Valdivia

Este proyecto consiste en un sistema de reproducción y gestión de música desarrollado en C++. Está diseñado para operar eficientemente en memoria mediante la implementación de estructuras de datos avanzadas hechas a medida, minimizando el uso de la biblioteca estándar (`std`) y priorizando el manejo manual de memoria dinámica con punteros.

## Características Principales

* **Carga y Guardado Persistente**: Lectura y escritura de la base de datos musical desde un archivo de texto (`music_source.txt`) utilizando formatos basados en delimitadores.
* **Sistema de Búsqueda por Prefijos**: Indexación de canciones para búsquedas rápidas utilizando estructuras especializadas.
* **Módulo de Rankings (TOP 10)**: Determinación en tiempo real de las canciones y artistas más escuchados del sistema.
* **Navegación Interactiva**: Interfaz de consola segmentada por pantallas dinámicas comandadas por caracteres de control y comandos compuestos.

---

## Estructuras de Datos Utilizadas

Como no podiamos usar la libreria estándar, todas las estructuras están hechas a mano en la carpeta `data_structures`:

1. **Lista Doblemente Enlazada (`Lista.h`)**: La uso para la cola de reproducción y para el registro de todas las canciones.
2. **Árbol Trie (`Trie.h`)**: Lo uso para indexar los nombres de los temas y los artistas, permitiendo búsquedas rápidas por prefijos.
3. **Árbol AVL (`AVLCancion.h`)**: Para ordenar las canciones por artista de forma balanceada.
4. **Max-Heap (`HeapCancion.h`)**: Lo uso para ordenar el ranking del Top 10 según la cantidad de reproducciones.

---
### Como ejecutar

En consola escribir g++ main.cpp classes/*.cpp data_structures/*.cpp -o reproductor: 
Luego ./reproductor
---

## Guía del Menú y Controles

Cuando ejecutas el programa, puedes utilizar los siguientes comandos para interactuar con el reproductor:

### Tabla de Comandos
| Comando | Acción que realiza |
| :--- | :--- |
| `W` | Reproducir o Pausar la canción actual. |
| `Q` | Retroceder a la canción anterior en la cola. |
| `E` | Saltar a la siguiente canción en la cola. |
| `S` | Alternar entre modo aleatorio (Shuffle) activado o desactivado. |
| `R` | Cambiar modo de repetición (Desactivado > R1 > RA). |
| `A` | Abrir la vista detallada de la Cola de reproducción. |
| `T` | Acceder al módulo de Rankings (TOP 10). |
| `L` | Listar todas las canciones registradas en la base de datos. |
| `X` | Guardar cambios en el archivo y salir del programa. |

### Visualización del flujo de navegación
```text
[MENÚ PRINCIPAL]
=== REPRODUCTOR DE MUSICA ===
W - Mostrar canciones | T - Ver Rankings | X - Salir

[RANKING TOP 10]
R<num> - Reproducir | A<num> - Agregar a cola | A - Ver Top Artistas | V - Volver

[DETALLE ARTISTA]
R<num> - Reproducir | V - Volver al Ranking | X - Volver a Menú Principal

