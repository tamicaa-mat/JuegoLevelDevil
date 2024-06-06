#ifndef NIVEL2_H_INCLUDED
#define NIVEL2_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "PuertaBlanca.h"
#include "Monedas.h"
#include "piso.h"
#include "Obstaculo.h"
#include"Trampa.h"

class Nivel2 {
private:
     sf::RenderWindow& ventana;
    Personaje pp;
    Moneda m,m2,m3;
    Piso piso;
    Trampa trmp;
    PuertaBlanca pb;
    Obstaculo obstaculo1;
    Obstaculo obstaculo2;
    sf::Text textoNivel;
    sf::Text textoGameOver;
    sf::Font fuente;
    int vidas;
    bool gameOver;
    bool gameOverResolved; // Nueva variable para controlar la resoluci�n de "Game Over"

public:
    Nivel2(sf::RenderWindow& vent);
    void manejarEntrada();
    void actualizar();
    void dibujar();
    bool isGameOverResolved() const; // Nueva funci�n
};


#endif // NIVEL2_H_INCLUDED