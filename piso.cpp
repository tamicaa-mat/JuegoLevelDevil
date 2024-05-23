#include <SFML/Graphics.hpp>
#include "piso.h"

 Piso::Piso(float ancho, float altura) {
        _forma.setSize(sf::Vector2f(800, 150)); // Establecer el tama�o del piso
        _forma.setFillColor(sf::Color::Blue); // Establecer el color del piso
        // Establecer la posici�n del piso como fijo en la parte inferior de la ventana
        _forma.setPosition(0.0f, 600.0f - altura);
    }



 sf::RectangleShape& Piso::getdraw() {
    return _forma;
}
