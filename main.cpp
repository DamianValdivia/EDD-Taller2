#include <iostream>
#include "../classes/Gestion.h"
#include <cstring>

using namespace std;

void mostrarMenu() {
    cout << "   REPRODUCTOR DE MUSICA   "<< endl;
    cout << "1. Ver todas las canciones" << endl;
    cout << "2. Buscar cancion por nombre" << endl;
    cout << "3. Ver Top 10 canciones" << endl;
    cout << "4. Reproducir cancion" << endl;
    cout << "5. Cargar canciones" << endl;
    cout << "6. Guardar canciones" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    Gestion gestion;
    int opcion;
    char buffer[256];

    gestion.cargarCancionesDesdeArchivo("../data/music_source.txt");

    while (true) {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                gestion.mostrarTodasLasCanciones();
                break;

            case 2: {
                cout << "Ingrese el nombre o parte de la cancion a buscar: ";
                cin.getline(buffer, sizeof(buffer));
                gestion.buscarCancion(buffer);
                break;
            }

            case 3:
                gestion.mostrarTop10();
                break;

            case 4: {
                cout << "Ingrese el ID de la cancion: ";
                int id;
                cin >> id;
                gestion.reproducirCancion(id);
                break;
            }

            case 5: {
                cout << "Ingrese la ruta del archivo: "; // aqui hay que optimizarlo, pa no tener que pedir la ruta
                cin.getline(buffer, sizeof(buffer));
                gestion.cargarCancionesDesdeArchivo(buffer);
                break;
            }

            case 6: {
                cout << "Ingrese la ruta del archivo de destino: "; //aqui igual
                cin.getline(buffer, sizeof(buffer));
                gestion.guardarCancionesEnArchivo(buffer);
                break;
            }

            case 0:
                cout << "Cerrando..." << endl;
                return 0;

            default:
                cout << "Opcion invalida." << endl;
        }
    }

    return 0;
}
