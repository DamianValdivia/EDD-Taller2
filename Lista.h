#include "Gestion.h"
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>

//Creacion de todos los metodos que se aplican en el main

void cargarDatos(Lista &lista) { //cargarmos el music_sourcce para ir creando canciones y añadiendolas al final de la lista
    ifstream archivo("music_source.txt");
    string linea;
    if (!archivo.is_open()) return;
    getline(archivo, linea);
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string id, nom, art, alb, an, dur, rut;
        getline(ss, id, ',');
        getline(ss, nom, ',');
        getline(ss, art, ',');
        getline(ss, alb, ',');
        getline(ss, an, ',');
        getline(ss, dur, ',');
        getline(ss, rut, ',');
        if (!id.empty()) {
            Cancion c(stoi(id), nom, art, alb, stoi(an), stoi(dur), rut);
            lista.agregarAlFinal(c);
        }
    }
    archivo.close();
}

void cargarStatus(bool &aleatorio, string &repeticion) {
    ifstream archi("status.cfg");
    string linea;
    if (!archi.is_open()) return;
    while (getline(archi, linea)) {
        if (linea.find("ALEATORIO=") != string::npos) {
            aleatorio = (linea.substr(10) == "1");
        }
        if (linea.find("REPETICION=") != string::npos) {
            repeticion = linea.substr(11);
        }
    }
    archi.close();
}

void mezclarListaManual(Lista &lista) {
    if (lista.primero == nullptr) return;
    int total = 0;
    Nodo* temp = lista.primero;
    while (temp != nullptr) { 
        total++; 
        temp = temp->siguiente; 
    }
    if (total < 2) return;
    for (int i = 0; i < total * 3; i++) {
        int p1 = rand() % total;
        int p2 = rand() % total;
        Nodo *n1 = lista.primero;
        Nodo *n2 = lista.primero;
        for (int j = 0; j < p1; j++) n1 = n1->siguiente;
        for (int k = 0; k < p2; k++) n2 = n2->siguiente;
        Cancion aux = n1->dato;
        n1->dato = n2->dato;
        n2->dato = aux;
    }
}

void guardarStatus(Nodo* actual, Lista &cola, bool modoAleatorio, string modoRepeticion, bool reproduciendo) { //Se mantenga la seleccion por si el codigo se cierra
    ofstream archi("status.cfg");
    archi << "ALEATORIO=" << (modoAleatorio ? "1" : "0") << endl;
    archi << "REPETICION=" << modoRepeticion << endl;
    archi << "REPRODUCIENDO=" << (reproduciendo ? "1" : "0") << endl;
    if (actual) {
        archi << "ULTIMA_CANCION=" << actual->dato.nombre << endl;
    }
    archi.close();
}

void rellenarColaAutomatico(Lista &registro, Lista &cola) { //Si la cola esta vacia se le rellena automaticamente
    cola.vaciar();
    Nodo* temp = registro.primero;
    while (temp != nullptr) {
        cola.agregarAlFinal(temp->dato);
        temp = temp->siguiente;
    }
    mezclarListaManual(cola);
}