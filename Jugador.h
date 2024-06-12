#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <string>

class Jugador {
private:
    char nombre[30];
    int puntaje;

public:
    Jugador(const std::string& nombreJugador, int puntajeInicial = 0);
    bool grabarArchivo(const char* filename = "records.dat");
    void setPuntaje(int puntaje);
    int getPuntaje() const;
    const char* getNombre() const;
    static void mostrarTodosJugadores(const char* filename = "records.dat");
};

#endif // JUGADOR_H_INCLUDED
