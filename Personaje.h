
#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>
#include "Obstaculo.h"
#include"Monedas.h"
#include"Trampa.h"

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
    sf::CircleShape _shape;
    ESTADO _estado; // Qué está haciendo el personaje
    float _velocidadSalto;
    float _velocidadSaltoHorizontal;
    float _velocidadMovimiento; // Nueva variable para la velocidad de movimiento
    sf::Vector2f _posicion;

public:
    Personaje();
    void cmd();
    void update();
    sf::CircleShape& getDraw();
    void activarCaida();
    bool colisionaCon(const Obstaculo& obstaculo); // Nueva función
    bool colisionaCon(const Moneda& moneda) const; // Declaración de colisionaCon
    bool colisionaCon(const Trampa& trampa) ;
};

#endif // PERSONAJE_H

