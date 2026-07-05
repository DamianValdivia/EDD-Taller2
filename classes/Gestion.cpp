#include "Gestion.h"

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
    std::ifstream archivo_in(archivo);
    if (!archivo_in.is_open()) {
        std::cout << "No se pudo abrir el archivo: " << archivo << std::endl;
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
    std::cout << "Canciones cargadas correctamente." << std::endl;
}

void Gestion::guardarCancionesEnArchivo(const char* archivo) {
    std::ofstream archivo_out(archivo);
    if (!archivo_out.is_open()) {
        std::cout << "No se pudo abrir el archivo para guardar: " << archivo << std::endl;
        return;
    }

    NodoCancion* actual = canciones->obtenerCabeza();
    while (actual != nullptr) {
        archivo_out << actual->dato->getNombre() << "|"
                   << actual->dato->getArtista() << "|"
                   << actual->dato->getAlbum() << "|"
                   << actual->dato->getGenero() << "|"
                   << actual->dato->getDuracion() << "|"
                   << actual->dato->getReproducciones() << std::endl;
        actual = actual->siguiente;
    }
    archivo_out.close();
    std::cout << "Canciones guardadas correctamente." << std::endl;
}

void Gestion::mostrarTodasLasCanciones() {
    if (canciones->estaVacia()) {
        std::cout << "No hay canciones disponibles." << std::endl;
        return;
    }
    std::cout << "\n=== TODAS LAS CANCIONES ===" << std::endl;
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
            std::cout << "Reproduciendo: " << actual->dato->getNombre() << std::endl;
            return;
        }
        actual = actual->siguiente;
    }
    std::cout << "Cancion no encontrada." << std::endl;
}

void Gestion::buscarCancion(const char* prefijo) {
    ListaCancion* resultados = new ListaCancion();
    busqueda->buscarCancionesPorNombre(prefijo, *resultados);

    if (resultados->obtenerTamanio() == 0) {
        std::cout << "No se encontraron canciones con: " << prefijo << std::endl;
        delete resultados;
        return;
    }

    std::cout << "\n=== RESULTADOS DE BUSQUEDA ===" << std::endl;
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
