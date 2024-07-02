#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED
#include <iostream>
#include <SFML/Graphics.hpp>
#include "ArchivoJugador.h"
#include "Jugador.h"

class MenuPrincipal {
private:
    sf::Font fuente;
    sf::Text textoBienvenida;
    sf::Text botonJugar;
    sf::Text botonRecords;
    sf::Text botonContinuarPartida;
    sf::RenderWindow& ventana;
    sf::Texture fondoTexture;
    sf::Sprite fondoSprite;
    sf::Text textoPartidas;
    bool botonJugarPresionado;
    bool botonRecordsPresionado;
    bool botonContinuarPartidaPresionado;

public:
    MenuPrincipal(sf::RenderWindow& vent);
    void manejarEntrada();
    void actualizar();
    void dibujar();
    bool esBotonJugarPresionado() const;
    bool esBotonRecordsPresionado() const;
    bool esBotonContinuarPartidaPresionado() const;
    void resetBotones();
//    int nivelJugador();
//    bool partidasVacias();
};

#endif // MENUPRINCIPAL_H_INCLUDED
