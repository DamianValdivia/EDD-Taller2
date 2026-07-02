#pragma once
#include <string>
using namespace std;

class Cancion { //Clase cancion con su construuctoor y sus correspondientes atributos
public:
	int id;
	string nombre;
	string artista;
	string album;
	int anio;
	int duracion;
	string ruta;


	Cancion(int idconst, string nombreconst, string artconst, string albconst, int anioconst, int duracionconst, string rutaconst) {
		id = idconst;
		nombre = nombreconst;
		artista = artconst;
		album = albconst;
		anio = anioconst;
		duracion = duracionconst;
		ruta = rutaconst;
	}


	Cancion() {
		id = 0;
	}
};