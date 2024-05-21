#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>

enum ESTADO{
QUIETO,
CAMINANDO_ADELANTE,
CAMINANDO_ATRAS,
SALTANDO,
CAYENDO,
};
class Personaje {
private:
    sf::CircleShape _shape;
    ESTADO _estado;//que esta haciendo el personaje?
    float _velocidadSalto;
    sf::Vector2f _posicion;

public:
    Personaje();
    void cmd();
    void update();
    sf::CircleShape& getDraw();
};

#endif // PERSONAJE_H
