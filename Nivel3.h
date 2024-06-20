#ifndef NIVEL3_H_INCLUDED
#define NIVEL3_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "PuertaBlanca.h"
#include "Monedas.h"
#include "piso.h"
#include "Obstaculo.h"
#include "Trampa.h"
#include "Jugador.h"


class Nivel3{
private:
   sf::RenderWindow& ventana;
    Jugador& jugador;
    Personaje pp;
    Moneda m, m2, m3, m4, m5, m6, m7, m8, m9, m10;
    Piso piso;
    Trampa trmp;
    //Trampa trmp2;
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
    Nivel3(sf::RenderWindow& vent, Jugador& jug);
    void manejarEntrada();
    void actualizar();
    void dibujar();
    void isGameOverModifica();
    bool isGameOverResolved() const;
    bool isGameOver() const;
    int getContadorMonedas() const;


};












#endif // NIVEL3_H_INCLUDED
