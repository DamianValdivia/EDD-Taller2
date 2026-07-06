#include "Gestion.h"

using namespace std;

Gestion::Gestion() : proximoIdCancion(1) {
    canciones = new ListaCancion();
    cancionesPorArtista = new AVLCancion();
    busqueda = new Busqueda();
    ranking = new Ranking();
    busqueda->setCancionesReferencia(canciones);
}

Gestion::~Gestion() {
    delete canciones;
    delete cancionesPorArtista;
    delete busqueda;
    delete ranking;
}

void Gestion::cargarCancionesDesdeArchivo(const char* archivo) {
    ifstream archivo_in(archivo);
    if (!archivo_in.is_open()) {
        cout << "No se pudo abrir el archivo: " << archivo << endl;
        return;
    }

    char linea[512];
    while (archivo_in.getline(linea, sizeof(linea))) {
        char linea_copia[512];
        strcpy(linea_copia, linea);
        
        char* token = strtok(linea_copia, "|");
        if (token == nullptr) continue;

        char nombre[256], artista[256], album[256], genero[256];
        int duracion = 0;

        strcpy(nombre, token);
        token = strtok(nullptr, "|");
        if (token) strcpy(artista, token);
        token = strtok(nullptr, "|");
        if (token) strcpy(album, token);
        token = strtok(nullptr, "|");
        if (token) strcpy(genero, token);
        token = strtok(nullptr, "|");
        if (token) duracion = atoi(token);

        Cancion* cancion = new Cancion(proximoIdCancion++, nombre, artista, album, genero, duracion, 0);
        canciones->agregar(cancion);
        cancionesPorArtista->insertar(cancion);
        busqueda->indexarCancion(cancion);
        ranking->agregarCancionAlRanking(cancion);
    }
    archivo_in.close();
    cout << "Canciones cargadas correctamente." << endl;
}

void Gestion::guardarCancionesEnArchivo(const char* archivo) {
    ofstream archivo_out(archivo);
    if (!archivo_out.is_open()) {
        cout << "No se pudo abrir el archivo para guardar: " << archivo << endl;
        return;
    }

    NodoCancion* actual = canciones->obtenerCabeza();
    while (actual != nullptr) {
        archivo_out << actual->dato->getNombre() << "|"
                   << actual->dato->getArtista() << "|"
                   << actual->dato->getAlbum() << "|"
                   << actual->dato->getGenero() << "|"
                   << actual->dato->getDuracion() << "|"
                   << actual->dato->getReproducciones() << endl;
        actual = actual->siguiente;
    }
    archivo_out.close();
    cout << "Canciones guardadas correctamente." << endl;
}

void Gestion::mostrarTodasLasCanciones() {
    if (canciones->estaVacia()) {
        cout << "No hay canciones disponibles." << endl;
        return;
    }
    cout << "\n=== TODAS LAS CANCIONES ===" << endl;
    NodoCancion* actual = canciones->obtenerCabeza();
    while (actual != nullptr) {
        actual->dato->mostrar();
        actual = actual->siguiente;
    }
}

void Gestion::reproducirCancion(int idCancion) {
    NodoCancion* actual = canciones->obtenerCabeza();
    while (actual != nullptr) {
        if (actual->dato->getId() == idCancion) {
            actual->dato->incrementarReproducciones();
            cout << "Reproduciendo: " << actual->dato->getNombre() << endl;
            return;
        }
        actual = actual->siguiente;
    }
    cout << "Cancion no encontrada." << endl;
}

void Gestion::buscarCancion(const char* prefijo) {
    ListaCancion* resultados = new ListaCancion();
    busqueda->buscarCancionesPorNombre(prefijo, *resultados);

    if (resultados->obtenerTamanio() == 0) {
        cout << "No se encontraron canciones con: " << prefijo << endl;
        delete resultados;
        return;
    }

    cout << "\n=== RESULTADOS DE BUSQUEDA ===" << endl;
    NodoCancion* actual = resultados->obtenerCabeza();
    while (actual != nullptr) {
        actual->dato->mostrar();
        actual = actual->siguiente;
    }
    delete resultados;
}

void Gestion::mostrarTop10() {
    ranking->mostrarTop10Canciones();
}

ListaCancion* Gestion::getCanciones() {
    return canciones;
}

void Gestion::mostrarCancionesDeArtistaAlfabetico(const char* artista) {
    if (canciones->estaVacia()) return;

    ListaCancion filtradas;
    NodoCancion* actual = canciones->obtenerCabeza();
    while (actual != nullptr) {
        if (strcmp(actual->dato->getArtista(), artista) == 0) {
            filtradas.agregar(actual->dato);
        }
        actual = actual->siguiente;
    }

    if (filtradas.obtenerTamanio() == 0) {
        cout << "No se encontraron canciones para el artista: " << artista << endl;
        return;
    }

    bool intercambiado;
    do {
        intercambiado = false;
        NodoCancion* nodo = filtradas.obtenerCabeza();
        while (nodo != nullptr && nodo->siguiente != nullptr) {
            if (strcmp(nodo->dato->getNombre(), nodo->siguiente->dato->getNombre()) > 0) {
                Cancion* aux = nodo->dato;
                nodo->dato = nodo->siguiente->dato;
                nodo->siguiente->dato = aux;
                intercambiado = true;
            }
            nodo = nodo->siguiente;
        }
    } while (intercambiado);

    cout << "Ranking TOP 10 Artistas mas escuchados:\n" << endl;
    cout << "Artista: " << artista << endl;

    NodoCancion* impresor = filtradas.obtenerCabeza();
    int i = 1;
    while (impresor != nullptr) {
        cout << "  " << i << ". " << impresor->dato->getNombre() << endl;
        impresor = impresor->siguiente;
        i++;
    }

    cout << "\nOpciones:" << endl;
    cout << "R<num> - Reproducir cancion seleccionada" << endl;
    cout << "A<num> - Agregar cancion seleccionada al final de la lista de reproduccion actual" << endl;
    cout << "V - Volver al listado de TOP 10 artistas" << endl;
    cout << "X - Volver al menu principal" << endl;
}
