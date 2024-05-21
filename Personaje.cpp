// Personaje.cpp
#include "Personaje.h"

Personaje::Personaje() //constructor por defecto
{
    _shape.setFillColor(sf::Color::Magenta);
    _shape.setRadius(20);
    _shape.setPosition(100,300);
    _estado=ESTADO::QUIETO;//inicialmente siempre esta quieto
    _velocidadSalto=0;

}

void Personaje::cmd()
{
    if(_estado==QUIETO)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            _estado=ESTADO::SALTANDO;
            _velocidadSalto=10;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            _estado=ESTADO::CAMINANDO_ADELANTE;


        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            _estado=ESTADO::CAMINANDO_ATRAS;

        }

    }


}


void Personaje::update()
{
    switch(_estado)
    {
    case QUIETO:


        break;
    case CAMINANDO_ADELANTE:
        _shape.move(1,0);
        _estado=ESTADO::QUIETO;

        break;
    case CAMINANDO_ATRAS:
        _shape.move(-1,0);
        _estado=ESTADO::QUIETO;

        break;
    case SALTANDO:
        _velocidadSalto -= 1;//quito la gravedad al salto
        _shape.move(0,-_velocidadSalto);
        // Verificar si el personaje ha alcanzado el límite inferior de la pantalla
        if (_shape.getPosition().y >500)
        {
            _estado = ESTADO::QUIETO; // Cambiar al estado QUIETO
            _velocidadSalto = 0; // Reiniciar la velocidad de salto
            _shape.setPosition(_shape.getPosition().x, 500); // Establecer la posición en el límite superior de la pantalla
        }
        break;
    case CAYENDO:


        break;


    }

}

sf::CircleShape& Personaje::getDraw()
{
    // Código de la función getDraw()
    return _shape;
}
