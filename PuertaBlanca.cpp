#include <SFML/Graphics.hpp>
#include"PuertaBlanca.h"


PuertaBlanca::PuertaBlanca(const sf::Vector2f& posicion, const sf::Color& color) : _estadoPuerta(false), _posicionPuerta(posicion), _colorPuerta(color) {}

void setPosition(const sf::Vector2f& posicion)
{
    _posicionPuerta = posicion;
}
void setColor(const sf::Color& color)
{
    _colorPuerta = color;
}
