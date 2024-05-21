#include <SFML/Graphics.hpp>

#include"Monedas.h"

// Constructor que inicializa la moneda en una posición específica y con un color y radio dados
Monedas(const sf::Vector2f& posicion, const sf::Color& color, float radio)
    : _posicionMoneda(posicion), _color(color), _radio(radio) {}

sf::Vector2f getPositionX() const
{
    return _posicionMoneda;
}
sf::Vector2f getPositionY() const
{
    return _posicionMoneda;
}

sf::Color getColor() const
{
    return _color;
}
float getRadius() const
{
    return _radio;
}

// Métodos para establecer la posición, el color y el radio de la moneda
void setPosition(const sf::Vector2f& posicion)
{
    _posicionMoneda = posicion;
}
void setColor(const sf::Color& color)
{
    _color = color;
}
void setRadius(float radio)
{
    _radio = radio;
}

