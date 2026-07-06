# Taller 2 - Estructuras de Datos (Reproductor de Música)

Este es mi proyecto para el Taller 2 de Estructuras de Datos. Es un reproductor de música simulado en consola hecho en C++. El objetivo principal del taller era implementar nuestras propias estructuras de datos desde cero para manejar la memoria dinámicamente y no usar nada de la STL (como `std::vector` o `std::list`).

## Qué hace el programa

*   **Controles de reproducción:** Puedes reproducir, pausar, ir a la canción siguiente, a la anterior o saltar a una canción específica de la lista usando su número.
*   **Modo Aleatorio (Shuffle):** Mezcla las canciones de la cola con una función propia que desordena los nodos.
*   **Modo Repetición:** Tiene opciones para repetir la canción actual (R1), repetir toda la lista (RA) o dejarlo desactivado.
*   **Búsqueda por texto:** Implementé un árbol Trie para poder buscar canciones y artistas escribiendo solo las primeras letras (búsqueda por prefijo).
*   **Guardado de estado:** Cuando sales del programa presionando la 'X', se crea un archivo llamado `status.cfg` que guarda si tenías el aleatorio activado, qué modo de repetición usabas y cuál fue la última canción que quedó sonando para la próxima vez que se abra.
*   **Top 10 (Rankings):** Uso un Heap (Montículo) para llevar el conteo de reproducciones y mostrar cuáles son las 10 canciones y artistas más escuchados.

---

## Estructuras de datos utilizadas

Como no podíamos usar la librería estándar, todas las estructuras están hechas a mano en la carpeta `data_structures`:

1.  **Lista Doblemente Enlazada (`Lista.h`):** La uso para la cola de reproducción y para el registro de todas las canciones, porque me permite moverme hacia adelante y atrás con los punteros `siguiente` y `anterior`.
2.  **Árbol Trie (`Trie.h`):** Lo uso para indexar los nombres de los temas y los artistas. Sirve para buscar súper rápido por prefijos.
3.  **Árbol AVL (`AVLCancion.h`):** Para ordenar las canciones por artista de forma balanceada.
4.  **Max-Heap (`HeapCancion.h`):** Lo uso para ordenar el ranking del Top 10 según la cantidad de reproducciones de cada canción.

---

## Cómo están organizados los archivos

*   `/classes`: Aquí está la lógica de las canciones, el sistema de búsqueda, el ranking y la clase `Gestion` que se encarga de conectar todo, leer el archivo de texto y guardar los datos.
*   `/data_structures`: Contiene todos los archivos `.h` con las estructuras que programé (Listas, Nodos, Tries, AVL, Heaps).
*   `main.cpp`: Tiene el bucle principal y los menús de la consola para interactuar con el reproductor.
*   `music_source.txt`: El archivo de texto de donde el programa lee todas las canciones separadas por comas.

---

## Controles del Menú Principal

Cuando ejecutas el programa, puedes usar estas letras para controlar el reproductor:

*   `W`: Reproducir / Pausar
*   `Q`: Canción anterior
*   `E`: Siguiente canción
*   `S`: Activar / Desactivar modo aleatorio
*   `R`: Cambiar el modo de repetición (Desactivado -> R1 -> RA)
*   `A`: Entrar a ver la Cola de reproducción actual
*   `L`: Ver el listado con todas las canciones registradas
*   `X`: Guardar el estado y salir del reproductor
