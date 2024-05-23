#ifndef MONEDAS_H_INCLUDED
#define MONEDAS_H_INCLUDED

#include <SFML/Graphics.hpp>

class Moneda{
private:
    sf::CircleShape _shapeMoneda;
    sf::Vector2f _posicionMoneda;
    bool _visible; // Indicador de si la moneda está visible o no
public:
    Moneda();
    void cmd();
    void update();
    sf::CircleShape& getDraw();

};



#endif // MONEDAS_H_INCLUDED
