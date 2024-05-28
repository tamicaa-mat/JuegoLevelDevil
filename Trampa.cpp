#include <SFML/Graphics.hpp>
#include"Trampa.h"


Trampa::Trampa(float posX, float posY) :
    _trampa(sf::Vector2f(50.0f, 150.0f))
{
    _trampa.setFillColor(sf::Color::White); // Establecer el color del piso
    _trampa.setPosition(posX, posY);
    _visible =false;
}


sf::Vector2f Trampa::getPosition() const {
    return _trampa.getPosition();
}


void Trampa::aparecer()
{

    _visible=true;

}


const sf::RectangleShape& Trampa::getDraw() const
{
    if (_visible)
    {
        return _trampa;
    }
    else
    {
        // Si la trampá no debe ser dibujada, devuelve una forma fuera de la pantalla
        static sf::RectangleShape emptyShape;
        return emptyShape;
    }
}
