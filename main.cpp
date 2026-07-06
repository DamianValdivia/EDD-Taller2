#include "classes/Gestion.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    Gestion gestion;
    gestion.cargarCancionesDesdeArchivo("music_source.txt");

    int menuActual = 0;
    char artistaSeleccionado[256] = "";
    char comando[50];
    bool ejecutando = true;

    while (ejecutando) {
        limpiarPantalla();

        if (menuActual == 0) {
            cout << "=== REPRODUCTOR DE MUSICA ===" << endl;
            cout << "W - Mostrar todas las canciones" << endl;
            cout << "T - Ver Rankings TOP 10" << endl;
            cout << "X - Salir" << endl;
            cout << "\nIngrese opcion: ";
        } 
        else if (menuActual == 1) {
            gestion.mostrarTop10();
            cout << "\nIngrese comando: ";
        } 
        else if (menuActual == 2) {
            gestion.getRanking()->mostrarTop10Artistas();
            cout << "\nIngrese opcion (o numero de artista): ";
        } 
        else if (menuActual == 3) {
            gestion.mostrarCancionesDeArtistaAlfabetico(artistaSeleccionado);
            cout << "\nIngrese comando: ";
        }

        cin.getline(comando, sizeof(comando));

        if (menuActual == 0) {
            if (strcasecmp(comando, "W") == 0) {
                limpiarPantalla();
                gestion.mostrarTodasLasCanciones();
                cout << "\nPresione Enter para continuar...";
                cin.get();
            } else if (strcasecmp(comando, "T") == 0) {
                menuActual = 1;
            } else if (strcasecmp(comando, "X") == 0) {
                ejecutando = false;
            }
        } 
        else if (menuActual == 1) {
            if (strcasecmp(comando, "V") == 0) {
                menuActual = 0;
            } else if (strcasecmp(comando, "A") == 0) {
                menuActual = 2;
            } else if (toupper(comando[0]) == 'R') {
                int num = atoi(&comando[1]);
                ListaCancion temp;
                gestion.getRanking()->obtenerTop10Canciones(temp);
                NodoCancion* actual = temp.obtenerCabeza();
                int i = 1;
                while (actual != nullptr && i < num) {
                    actual = actual->siguiente;
                    i++;
                }
                if (actual != nullptr) {
                    limpiarPantalla();
                    gestion.reproducirCancion(actual->dato->getId());
                } else {
                    cout << "Numero invalido." << endl;
                }
                cout << "\nPresione Enter para continuar...";
                cin.get();
            } else if (toupper(comando[0]) == 'A' && isdigit(comando[1])) {
                int num = atoi(&comando[1]);
                cout << "Agregando a la cola cancion Nro: " << num << endl;
                cout << "\nPresione Enter para continuar...";
                cin.get();
            }
        } 
        else if (menuActual == 2) {
            if (strcasecmp(comando, "X") == 0) {
                menuActual = 0;
            } else if (isdigit(comando[0])) {
                int idx = atoi(comando);
                ListaCancion temp;
                gestion.getRanking()->obtenerTop10Artistas(temp);
                NodoCancion* actual = temp.obtenerCabeza();
                int i = 1;
                while (actual != nullptr && i < idx) {
                    actual = actual->siguiente;
                    i++;
                }
                if (actual != nullptr) {
                    strcpy(artistaSeleccionado, actual->dato->getArtista());
                    menuActual = 3;
                } else {
                    cout << "Artista no encontrado." << endl;
                    cout << "\nPresione Enter para continuar...";
                    cin.get();
                }
            }
        } 
        else if (menuActual == 3) {
            if (strcasecmp(comando, "V") == 0) {
                menuActual = 2;
            } else if (strcasecmp(comando, "X") == 0) {
                menuActual = 0;
            } else if (toupper(comando[0]) == 'R') {
                int num = atoi(&comando[1]);
                cout << "Reproduciendo cancion de artista filtrado Nro: " << num << endl;
                cout << "\nPresione Enter para continuar...";
                cin.get();
            }
        }
    }

    gestion.guardarCancionesEnArchivo("music_source.txt");
    return 0;
}
