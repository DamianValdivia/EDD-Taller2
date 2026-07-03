#ifndef CANCION_H
#define CANCION_H

#include <cstring>
#include <iostream>

class Cancion {
private:
    int id;
    char nombre[256];
    char artista[256];
    char album[256];
    char genero[256];
    int duracion;
    int reproducciones;

public:
    Cancion();
    Cancion(int id, const char* nombre, const char* artista, const char* album, 
            const char* genero, int duracion, int reproducciones);

    int getId() const;
    const char* getNombre() const;
    const char* getArtista() const;
    const char* getAlbum() const;
    const char* getGenero() const;
    int getDuracion() const;
    int getReproducciones() const;

    void setId(int id);
    void setNombre(const char* nombre);
    void setArtista(const char* artista);
    void setAlbum(const char* album);
    void setGenero(const char* genero);
    void setDuracion(int duracion);
    void setReproducciones(int reproducciones);

    void incrementarReproducciones();

    void mostrar() const;
};

#endif // CANCION_H
