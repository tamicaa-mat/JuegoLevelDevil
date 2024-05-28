#ifndef NIVEL1_H_INCLUDED
#define NIVEL1_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "PuertaBlanca.h"
#include "Monedas.h"
#include "piso.h"
#include "Obstaculo.h"
#include"Trampa.h"

class Nivel1 {
private:
    Personaje pp;
    Moneda m;
    Piso piso;
    Trampa trmp;
    PuertaBlanca pb;
    Obstaculo obstaculo1;
    Obstaculo obstaculo2;
    sf::Text textoNivel;
    sf::Text textoGameOver;
    sf::Font fuente;
    sf::RenderWindow& ventana;
    int vidas;
    bool gameOver;
    bool gameOverResolved; // Nueva variable para controlar la resolución de "Game Over"

public:
    Nivel1(sf::RenderWindow& vent);
    void manejarEntrada();
    void actualizar();
    void dibujar();
    bool isGameOverResolved() const; // Nueva función
};

#endif // NIVEL1_H_INCLUDED
