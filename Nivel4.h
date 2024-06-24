#ifndef NIVEL4_H_INCLUDED
#define NIVEL4_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "PuertaBlanca.h"
#include "Monedas.h"
#include "piso.h"
#include "Obstaculo.h"
#include "Trampa.h"
#include "Jugador.h"


class Nivel4 {
private:
    sf::RenderWindow& ventana;
    Jugador& jugador;
    Personaje pp;
    Moneda m, m2, m3;
    Piso piso;
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


    int vidas;
    bool gameOver;
    bool gameOverResolved;
    int contadorMonedas;

public:
    Nivel4(sf::RenderWindow& vent, Jugador& jug);
    void manejarEntrada();
    void actualizar();
    void dibujar();
    bool isGameOverResolved() const;
    bool isGameOver() const;
    void isGameOverModifica();
    int getContadorMonedas() const;
};








#endif // NIVEL4_H_INCLUDED
