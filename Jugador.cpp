#include "Jugador.h"
#include <cstring>
#include <iostream>

Jugador::Jugador(const std::string& nombreJugador, int puntajeInicial,int nivel) : puntaje(puntajeInicial),_nivel(nivel) {
    strncpy(nombre, nombreJugador.c_str(), sizeof(nombre) - 1);
    nombre[sizeof(nombre) - 1] = '\0';
}

void Jugador::setNombre(const std::string& nombreJugador) {

    std::strncpy(nombre, nombreJugador.c_str(), sizeof(nombre) - 1);

    nombre[sizeof(nombre) - 1] = '\0';
}




Jugador::Jugador()  {
    nombre[0] = '\0';
}


void Jugador::setPuntaje(int pun) {
    puntaje = pun;
}

int Jugador::getPuntaje() const {
    return puntaje;
}

void Jugador::setNivel(int niv) {
    _nivel = niv;
}

 int Jugador::getNivel() const {
    return _nivel;
}


const char* Jugador::getNombre() const {
    return nombre;
}


//    Jugador jugador("", 0 , 1);
//
//    while (fread(&jugador, sizeof jugador, 1, p) == 1) {
//        std::cout << "Nombre: " << jugador.getNombre() << ", Puntaje: " << jugador.getPuntaje() << std::endl;
//        std::cout<<"Nivel: "<<jugador.getNivel()<<std::endl;
//    fclose(p);
//    }



 void Jugador::mostrarDatos()  {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Puntaje: " << puntaje << std::endl;
        std::cout << "Nivel: " << _nivel << std::endl;
    }

//bool Jugador::grabarArchivo(const char* filename) {
//    FILE *p;
//    p = fopen(filename, "ab");
//    if (p == NULL) {
//        perror("Error al abrir el archivo");
//        return false;
//    }
//    bool grabo = fwrite(this, sizeof *this, 1, p);
//    fclose(p);
//    return grabo;
//}
