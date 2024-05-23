#include "Obstaculo.h"

Obstaculo::Obstaculo(float x, float y, float width, float height) {
    _shape.setSize(sf::Vector2f(width, height));
    _shape.setFillColor(sf::Color::Red);
    _shape.setPosition(x, y);
}

const sf::RectangleShape& Obstaculo::getDraw() const {
    return _shape;
}
