#ifndef NIVEL1_H_INCLUDED
#define NIVEL1_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "PuertaBlanca.h"
#include "Monedas.h"
#include "piso.h"
#include "Obstaculo.h"
#include "Trampa.h"

class Nivel1 {
private:
    sf::RenderWindow& ventana;
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
    int vidas;
    bool gameOver;
    bool gameOverResolved;
    int contadorMonedas;

public:
    Nivel1(sf::RenderWindow& vent);
    void manejarEntrada();
    void actualizar();
    void dibujar();
    bool isGameOverResolved() const;
    bool isGameOver() const; // Nuevo método
};

#endif // NIVEL1_H_INCLUDED
