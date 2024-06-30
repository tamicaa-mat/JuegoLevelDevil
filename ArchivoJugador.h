#ifndef ARCHIVOJUGADOR_H_INCLUDED
#define ARCHIVOJUGADOR_H_INCLUDED
#include <iostream>
#include <cstring>
#include "Jugador.h"

class ArchivoJugador {
private:
    char nombre[30];
    int numJugadores;
public:
      ArchivoJugador(const char *n = "partidas.dat") {
        strcpy(nombre, n);

    }
    int contarRegistros();
    bool grabarArchivo(Jugador obj);
    void mostrarTodosJugadores(const char* filename = "partidas.dat");
    Jugador leerRegistro(int pos);
};

















#endif // ARCHIVOJUGADOR_H_INCLUDED
