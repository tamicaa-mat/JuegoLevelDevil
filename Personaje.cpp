#include <cmath>
#include "Personaje.h"

Personaje::Personaje(float x, float y)
{
    _shape.setFillColor(sf::Color::Magenta);
    _shape.setRadius(20);
    _shape.setPosition(x, y);
    _estado = ESTADO::QUIETO;
    _velocidadSalto = 0;
    _velocidadSaltoHorizontal = 0;
    _velocidadMovimiento = 2.0f;
    _velocidadCaida = 0.1f;
    fueraJuego = false;
}

 void Personaje::setEstado(ESTADO est){
    _estado=est;
    }


sf::Drawable& Personaje::getDraw()
{
    return _shape; // Devolver el objeto _shape del personaje
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

void Personaje::activarCaida()
{
    _estado = ESTADO::CAYENDO;
    _velocidadCaida = 5.0f;

}

void Personaje::caer()
{
    _estado = ESTADO::CAYENDO;

}

void Personaje::reset(float x, float y)
{
    _shape.setPosition(x, y);
    _estado = ESTADO::QUIETO;
    _velocidadSalto = 0;
    _velocidadSaltoHorizontal = 0;
    _velocidadCaida = 0.1f;
    fueraJuego = false;
}

void Personaje::update()
{
    switch (_estado)
    {
    case QUIETO:

        break;

    case CAMINANDO_ADELANTE:
        _shape.move(_velocidadMovimiento, 0);
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            _estado = ESTADO::QUIETO;
        }
        break;

    case CAMINANDO_ATRAS:
        _shape.move(-_velocidadMovimiento, 0);
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
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
        _shape.move(_velocidadMovimiento+1, -_velocidadSalto);
        if (_shape.getPosition().y > 400)
        {
            _estado = ESTADO::QUIETO; // Cambiar al estado QUIETO
            _velocidadSalto = 0; // Reiniciar la velocidad de salto
            _shape.setPosition(_shape.getPosition().x, 400); // Establecer la posición en el límite superior de la pantalla
        }
        break;

    case SALTANDO_ATRAS:
        _velocidadSalto -= 1.0f;
        _shape.move(-_velocidadMovimiento-1, -_velocidadSalto);
        if (_shape.getPosition().y > 400)
        {
            _estado = ESTADO::QUIETO; // Cambiar al estado QUIETO
            _velocidadSalto = 0; // Reiniciar la velocidad de salto
            _shape.setPosition(_shape.getPosition().x, 400); // Establecer la posición en el límite superior de la pantalla
        }
        break;

    case CAYENDO:
        _shape.move(0, _velocidadCaida);
        _velocidadCaida += 0.5f; // Aumentar la velocidad de caída
        if (_shape.getPosition().y > 600) // Si cae fuera de la pantalla
        {
            fueraJuego = true;
        }
        break;
    }
}

bool Personaje::colisionaCon(const Obstaculo& obstaculo)
{
    return _shape.getGlobalBounds().intersects(obstaculo.getDraw().getGlobalBounds());
}

bool Personaje::colisionaCon(const Moneda& moneda) const
{
    return _shape.getGlobalBounds().intersects(moneda.getDraw().getGlobalBounds());
}

bool Personaje::colisionaCon(const Trampa& trampa)
{
    float posXPersonaje = _shape.getPosition().x;
    float posYPersonaje = _shape.getPosition().y+50; // Ajuste de posición vertical

    float posXTrampa = trampa.getPosition().x;
    float posYTrampa = trampa.getPosition().y;

    if (posXPersonaje == posXTrampa && posYPersonaje == posYTrampa)
    {

        return true;
    }

    return false;
}



bool Personaje::colisionaConTrampaN2(const Trampa& trampa)
{
    sf::Vector2f posPersonaje = _shape.getPosition();
    float radioPersonaje = _shape.getRadius();

    sf::Vector2f posTrampa = trampa.getPosition();
    sf::Vector2f sizeTrampa = trampa.getSize();

    // Obtener el centro del círculo (personaje)
    sf::Vector2f centroPersonaje = sf::Vector2f(posPersonaje.x + radioPersonaje, posPersonaje.y + radioPersonaje);

    // Obtener el centro del rectángulo (trampa)
    sf::Vector2f centroTrampa = sf::Vector2f(posTrampa.x + sizeTrampa.x / 2, posTrampa.y + sizeTrampa.y / 2);

    // Calcular la distancia entre los centros
    float distanciaX = std::abs(centroPersonaje.x - centroTrampa.x);
    float distanciaY = std::abs(centroPersonaje.y - centroTrampa.y);

    // Comparar la distancia con los radios y dimensiones
    if (distanciaX <= (radioPersonaje + sizeTrampa.x / 2) &&
        distanciaY <= (radioPersonaje + sizeTrampa.y / 2))

    {
        return true;
    }

    return false;
}


bool Personaje::colisionPuertaBlanca(const PuertaBlanca& _puertaRec)
{
    float posXPersonaje = _shape.getPosition().x;
    float posYPersonaje = _shape.getPosition().y;
    float posXPuerta = _puertaRec.getPosition().x;
    float posYPuerta = _puertaRec.getPosition().y;

    if (posXPersonaje == posXPuerta && posYPersonaje == posYPuerta)
    {
        return true;
    }

    return false;
}

sf::Vector2f Personaje::getPosition() const
{
    return _shape.getPosition();
}
