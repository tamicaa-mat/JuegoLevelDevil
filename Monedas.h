
#ifndef MONEDAS_H_INCLUDED
#define MONEDAS_H_INCLUDED

#include <SFML/Graphics.hpp>

class Moneda {
private:
    sf::CircleShape _shapeMoneda;
    bool _visible;

public:
    Moneda(float x, float y, int radio);
    void desaparecer();
    const sf::CircleShape& getDraw() const;
};

#endif // MONEDAS_H_INCLUDED
