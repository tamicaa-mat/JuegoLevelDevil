#include <SFML/Graphics.hpp>
#include "piso.h"

 Piso::Piso(float ancho, float altura) {
        _forma.setSize(sf::Vector2f(800, 150)); // Establecer el tamaño del piso
        _forma.setFillColor(sf::Color::Blue); // Establecer el color del piso
        // Establecer la posición del piso como fijo en la parte inferior de la ventana
        _forma.setPosition(0.0f, 600.0f - altura);
    }


void Piso::setColor(const sf::Color& color) {
    _forma.setFillColor(color);
}
void Piso::setPosition(float x, float y) {
    _forma.setPosition(x, y);
}
 sf::RectangleShape& Piso::getdraw() {
    return _forma;
}
void Piso::setSize(float ancho, float altura) {
    _forma.setSize(sf::Vector2f(ancho, altura));
}
