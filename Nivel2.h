#ifndef NIVEL2_H_INCLUDED
#define NIVEL2_H_INCLUDED
#include <SFML/Audio.hpp>

#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "PuertaBlanca.h"
#include "Monedas.h"
#include "piso.h"
#include "Obstaculo.h"
#include"Trampa.h"
#include"Jugador.h"
#include "Nivel1.h"
#include"ArchivoJugador.h"
class Nivel2 {
private:
     sf::RenderWindow& ventana;
    Jugador& jugador;
    Personaje pp;
    Moneda m,m2,m3;
    Piso piso,pisoArriba;
    Trampa trmp;
    PuertaBlanca pb;
    Obstaculo obstaculo1;
    Obstaculo obstaculo2;

    sf::Text textoVidas;
    sf::Text textoPuntos;
    sf::Text textoGameOver;
    sf::Font fuente;
    sf::Texture fondoTexture;
    sf::Sprite fondoSprite;
    sf::SoundBuffer buffer;
    sf::Sound sound;

    int vidas;
    bool gameOver;
    bool gameOverResolved;
    int contadorMonedas;

public:
    Nivel2(sf::RenderWindow& vent, Jugador& jug);
    void manejarEntrada();
    void actualizar();
    void dibujar();
    void isGameOverModifica();
    bool isGameOver() const;
    bool isGameOverResolved() const;
     int getContadorMonedas() const;
};


#endif // NIVEL2_H_INCLUDED
