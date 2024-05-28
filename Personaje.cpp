
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

bool Personaje::colisionaCon(const Moneda& moneda)const {
     return  _shape.getGlobalBounds().intersects(moneda.getDraw().getGlobalBounds());
}

bool Personaje::colisionaCon(const Trampa& trampa) const {
    // Obtiene la posición X del objeto _shape del personaje
    float posXPersonaje = _shape.getPosition().x;
    float posYPersonaje = ((_shape.getPosition().y)+50);//porque tengo a personaje en y=400 y el piso en y=450


    // Obtiene la posición X del objeto devuelto por getDraw() de la trampa
    float posXTrampa = trampa.getPosition().x;
    float posYTrampa = trampa.getPosition().y;

    if(posXPersonaje==posXTrampa&&posYPersonaje==posYTrampa){
            return true;

    }
}
