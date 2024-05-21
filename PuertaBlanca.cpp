#include <SFML/Graphics.hpp>
#include"PuertaBlanca.h"


PuertaBlanca::PuertaBlanca(float ancho, float altura) {
        _puertaRec.setSize(sf::Vector2f(40, 65)); // Establecer el tamaño d LA PUERTA
        _puertaRec.setFillColor(sf::Color::White); // Establecer el color de PUERTA
        // Establecer la posición del piso como fijo en la parte inferior de la ventana
        _puertaRec.setPosition(700,400);
    }

sf::RectangleShape& PuertaBlanca::getDraw()
{
    // Código de la función getDraw()
    return _puertaRec;
}
