#include <SFML/Graphics.hpp>

#include"Monedas.h"

Moneda::Moneda()
{
    _shapeMoneda.setFillColor(sf::Color::Yellow);
    _shapeMoneda.setRadius(10);
    _shapeMoneda.setPosition(300,200);
    _visible=true;

}

sf::CircleShape& Moneda::getDraw()
{
    // Código de la función getDraw()
    return _shapeMoneda;
}
