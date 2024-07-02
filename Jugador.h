#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <string>

class Jugador {
private:
    char nombre[30];
    int puntaje;
    int _nivel;
public:
        Jugador();

    Jugador(const std::string& nombreJugador, int puntajeInicial = 0, int nivel=1);
    void setPuntaje(int puntaje);
    int getPuntaje() const;
    void setNivel(int niv);
    int getNivel()const;
    void mostrarDatos();
    void setNombre(const std::string& nombreJugador);
    const char* getNombre() const;
};

#endif // JUGADOR_H_INCLUDED
