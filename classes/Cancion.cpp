#include "Cancion.h"

Cancion::Cancion() : id(0), duracion(0), reproducciones(0) {
    strcpy(nombre, "");
    strcpy(artista, "");
    strcpy(album, "");
    strcpy(genero, "");
}

Cancion::Cancion(int id, const char* nombre, const char* artista, const char* album, 
                 const char* genero, int duracion, int reproducciones)
    : id(id), duracion(duracion), reproducciones(reproducciones) {
    strcpy(this->nombre, nombre);
    strcpy(this->artista, artista);
    strcpy(this->album, album);
    strcpy(this->genero, genero);
}

int Cancion::getId() const { return id; }
const char* Cancion::getNombre() const { return nombre; }
const char* Cancion::getArtista() const { return artista; }
const char* Cancion::getAlbum() const { return album; }
const char* Cancion::getGenero() const { return genero; }
int Cancion::getDuracion() const { return duracion; }
int Cancion::getReproducciones() const { return reproducciones; }

void Cancion::setId(int id) { this->id = id; }
void Cancion::setNombre(const char* nombre) { strcpy(this->nombre, nombre); }
void Cancion::setArtista(const char* artista) { strcpy(this->artista, artista); }
void Cancion::setAlbum(const char* album) { strcpy(this->album, album); }
void Cancion::setGenero(const char* genero) { strcpy(this->genero, genero); }
void Cancion::setDuracion(int duracion) { this->duracion = duracion; }
void Cancion::setReproducciones(int reproducciones) { this->reproducciones = reproducciones; }

void Cancion::incrementarReproducciones() {
    reproducciones++;
}

void Cancion::mostrar() const {
    std::cout << "[" << id << "] " << nombre << " - " << artista 
              << " (" << reproducciones << " reproducciones)" << std::endl;
}
