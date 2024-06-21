
#include <SFML/Graphics.hpp>
#include"PuertaBlanca.h"


PuertaBlanca::PuertaBlanca(float x, float y) {
        _puertaRec.setSize(sf::Vector2f(40, 65)); // Establecer el tamaño d LA PUERTA
        _puertaRec.setFillColor(sf::Color::White); // Establecer el color de PUERTA
        // Establecer la posición del piso como fijo en la parte inferior de la ventana
        _puertaRec.setPosition(x,y);

    }

sf::RectangleShape& PuertaBlanca::getDraw()
{
    // Código de la función getDraw()
    return _puertaRec;
}

sf::Vector2f PuertaBlanca::getPosition() const {
    return _puertaRec.getPosition();
}


void PuertaBlanca::setPosicion(float x, float y) {
    _puertaRec.setPosition(x, y);
}


