<<<<<<< HEAD
#include "Personaje.h"

Personaje::Personaje() //constructor por defecto
{
    _shape.setFillColor(sf::Color::Magenta);
    _shape.setRadius(20);
    _shape.setPosition(0,400);
    _estado=ESTADO::QUIETO;//inicialmente siempre esta quieto
    _velocidadSalto=0;
    _velocidadSaltoHorizontal=0;
    _velocidadMovimiento = 2.0f; // Establecer una velocidad de movimiento inicial
}

void Personaje::cmd()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if (_estado == QUIETO || _estado == CAMINANDO_ADELANTE || _estado == CAMINANDO_ATRAS)
        {
            _estado = ESTADO::SALTANDO;
            _velocidadSalto = 20;
        }
        else if (_estado == CAMINANDO_ADELANTE)
        {
            _estado = ESTADO::SALTANDO_ADELANTE;
            _velocidadSalto = 20;
            _velocidadSaltoHorizontal = 5;
        }
        else if (_estado == CAMINANDO_ATRAS)
        {
            _estado = ESTADO::SALTANDO_ATRAS;
            _velocidadSalto = 20;
            _velocidadSaltoHorizontal = 5;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if (_estado == QUIETO)
        {
            _estado = ESTADO::CAMINANDO_ADELANTE;
        }
        else if (_estado == SALTANDO)
        {
            _estado = ESTADO::SALTANDO_ADELANTE;
            _velocidadSaltoHorizontal = 5;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if (_estado == QUIETO)
        {
            _estado = ESTADO::CAMINANDO_ATRAS;
        }
        else if (_estado == SALTANDO)
        {
            _estado = ESTADO::SALTANDO_ATRAS;
            _velocidadSaltoHorizontal = 5;
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
        _shape.move(_velocidadMovimiento, 0);
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            _estado = ESTADO::QUIETO;
        }
        break;

    case CAMINANDO_ATRAS:
        _shape.move(-_velocidadMovimiento, 0);
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            _estado = ESTADO::QUIETO;
        }
        break;

    case SALTANDO:
        _velocidadSalto -= 1; // Quitar la gravedad al salto
        _shape.move(0, -_velocidadSalto);
        if (_shape.getPosition().y > 400)
        {
            _estado = ESTADO::QUIETO; // Cambiar al estado QUIETO
            _velocidadSalto = 0; // Reiniciar la velocidad de salto
            _shape.setPosition(_shape.getPosition().x, 400); // Establecer la posición en el límite superior de la pantalla
        }
        break;

    case SALTANDO_ADELANTE:
        _velocidadSalto -= 1.0f; // Aplica gravedad
        _shape.move(_velocidadMovimiento, -_velocidadSalto);
        if (_shape.getPosition().y > 400)
        {
            _estado = ESTADO::QUIETO; // Cambiar al estado QUIETO
            _velocidadSalto = 0; // Reiniciar la velocidad de salto
            _shape.setPosition(_shape.getPosition().x, 400); // Establecer la posición en el límite superior de la pantalla
        }
        break;

    case SALTANDO_ATRAS:
        _velocidadSalto -= 1.0f;
        _shape.move(-_velocidadMovimiento, -_velocidadSalto);
        if (_shape.getPosition().y > 400)
        {
            _estado = ESTADO::QUIETO; // Cambiar al estado QUIETO
            _velocidadSalto = 0; // Reiniciar la velocidad de salto
            _shape.setPosition(_shape.getPosition().x, 400); // Establecer la posición en el límite superior de la pantalla
        }
        break;

    case CAYENDO:
        break;
    }
}

sf::CircleShape& Personaje::getDraw()
{
    return _shape;
}

bool Personaje::colisionaCon(const Obstaculo& obstaculo) {
    return _shape.getGlobalBounds().intersects(obstaculo.getDraw().getGlobalBounds());
}
=======
// Personaje.cpp
#include "Personaje.h"

Personaje::Personaje() //constructor por defecto
{
    _shape.setFillColor(sf::Color::Magenta);
    _shape.setRadius(20);
    _shape.setPosition(0,400);
    _estado=ESTADO::QUIETO;//inicialmente siempre esta quieto
    _velocidadSalto=0;
    _velocidadSaltoHorizontal=0;

}

void Personaje::cmd()
{
    if(_estado==QUIETO)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            _estado=ESTADO::SALTANDO;
            _velocidadSalto=20;
        }


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            _estado=ESTADO::CAMINANDO_ATRAS;

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            _estado=ESTADO::CAMINANDO_ADELANTE;

        }

    }
      if(_estado==SALTANDO){
           if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            _estado=ESTADO::SALTANDO_ADELANTE;
            _velocidadSalto=20;
            _velocidadSaltoHorizontal=5;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            _estado=ESTADO::SALTANDO_ATRAS;
            _velocidadSalto=20;
            _velocidadSaltoHorizontal=5;
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
        if (_shape.getPosition().y >400)
        {
            _estado = ESTADO::QUIETO; // Cambiar al estado QUIETO
            _velocidadSalto = 0;// Reiniciar la velocidad de salto
            _shape.setPosition(_shape.getPosition().x, 400); // Establecer la posición en el límite superior de la pantalla
        }
        break;
    case SALTANDO_ADELANTE:
         _velocidadSalto -= 1.0f; // Aplica gravedad
        _velocidadSaltoHorizontal-=2;
        _shape.move(1,-_velocidadSalto);

        if (_shape.getPosition().y >400)
        {
            _estado = ESTADO::QUIETO; // Cambiar al estado QUIETO
            _velocidadSalto = 0; // Reiniciar la velocidad de salto
            _shape.setPosition(_shape.getPosition().x, 400); // Establecer la posición en el límite superior de la pantalla
        }
        break;
    case SALTANDO_ATRAS:
        _velocidadSalto -= 1.0f;
        _velocidadSaltoHorizontal-= 2;//quito la gravedad al salto vertical
        _shape.move(-1,-_velocidadSalto);
        // Verificar si el personaje ha alcanzado el límite inferior de la pantalla
        if (_shape.getPosition().y >400)
        {
            _estado = ESTADO::QUIETO; // Cambiar al estado QUIETO
            _velocidadSalto = 0; // Reiniciar la velocidad de salto
            _shape.setPosition(_shape.getPosition().x, 400); // Establecer la posición en el límite superior de la pantalla
        }
    case CAYENDO:


        break;


    }

}

sf::CircleShape& Personaje::getDraw()
{
    // Código de la función getDraw()
    return _shape;
}
>>>>>>> 6f61caf099bd79490bf4755cf2e83f910632a5e9
