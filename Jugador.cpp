#include "Jugador.h"
#include <cstring>
#include <iostream>

Jugador::Jugador(const std::string& nombreJugador, int puntajeInicial) : puntaje(puntajeInicial) {
    strncpy(nombre, nombreJugador.c_str(), sizeof(nombre) - 1);
    nombre[sizeof(nombre) - 1] = '\0';
}

bool Jugador::grabarArchivo(const char* filename) {
    FILE *p;
    p = fopen(filename, "ab");
    if (p == NULL) {
        perror("Error al abrir el archivo");
        return false;
    }
    bool grabo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return grabo;
}

void Jugador::setPuntaje(int puntaje) {
    this->puntaje = puntaje;
}

int Jugador::getPuntaje() const {
    return puntaje;
}

const char* Jugador::getNombre() const {
    return nombre;
}

void Jugador::mostrarTodosJugadores(const char* filename) {
    FILE *p = fopen(filename, "rb");
    if (p == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    Jugador jugador("", 0);
    while (fread(&jugador, sizeof jugador, 1, p) == 1) {
        std::cout << "Nombre: " << jugador.getNombre() << ", Puntaje: " << jugador.getPuntaje() << std::endl;
    }

    fclose(p);
}
