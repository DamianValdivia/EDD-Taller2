#pragma once
#include "..\data_structures\Lista.h"
#include <string>

using namespace std;

void cargarDatos(Lista &lista);
void cargarStatus(bool &aleatorio, string &repeticion);
void mezclarListaManual(Lista &lista);
void guardarStatus(Nodo* actual, Lista &cola, bool modoAleatorio, string modoRepeticion, bool reproduciendo);
void rellenarColaAutomatico(Lista &registro, Lista &cola);