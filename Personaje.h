
#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>

#include "Obstaculo.h"
#include"Monedas.h"
#include"Trampa.h"
#include"PuertaBlanca.h"

enum ESTADO{
    QUIETO,
    CAMINANDO_ADELANTE,
    CAMINANDO_ATRAS,
    SALTANDO,
    SALTANDO_ADELANTE,
    SALTANDO_ATRAS,
    CAYENDO,
};

class Personaje {
private:
 // sf::Sprite _shape;
 //sf::Texture _shapeTexture;
  sf::CircleShape _shape;
    ESTADO _estado; // Qué está haciendo el personaje
    float _velocidadSalto;
    float _velocidadSaltoHorizontal;
    float _velocidadMovimiento;
    float _velocidadCaida;
    bool fueraJuego=false;// Nueva variable para la velocidad de movimiento
    sf::Vector2f _posicion;

public:
    Personaje(float x,float y);
    void cmd();
    void update();
    //sf::CircleShape& getDraw();
    sf::Drawable& getDraw();
    void activarCaida();
    bool colisionaCon(const Obstaculo& obstaculo); // Nueva función
    bool colisionaCon(const Moneda& moneda) const; // Declaración de colisionaCon
    bool colisionaCon(const Trampa& trampa) ;
    bool colisionPuertaBlanca(const PuertaBlanca& puertablanca);
};

#endif // PERSONAJE_H

