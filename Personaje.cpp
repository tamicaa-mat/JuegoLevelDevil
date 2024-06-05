
#include "Personaje.h"

Personaje::Personaje(float x, float y)
{
    _shape.setFillColor(sf::Color::Magenta);
    _shape.setRadius(20);
    _shape.setPosition(x, y); // Establecer la posición usando los parámetros x e y
    _estado = ESTADO::QUIETO; // Inicialmente siempre está quieto
    _velocidadSalto = 0;
    _velocidadSaltoHorizontal = 0;
    _velocidadMovimiento = 2.0f; // Establecer una velocidad de movimiento inicial
    _velocidadCaida=0.1f;
    fueraJuego = false;

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

}

void Personaje::update()
{
    switch(_estado)
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
        if (_velocidadCaida < -2)
        {
            _velocidadCaida = -2; // Limitar la velocidad mínima de caída
        }
        _velocidadCaida += (0.0005); // Aumentar la velocidad de caída gradualmente
        _shape.move(0, _velocidadCaida/100); // Mover hacia abajo con la velocidad de caída actualizada
        if (_shape.getPosition().y > 600)
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

bool Personaje::colisionaCon(const Moneda& moneda)const
{
    return  _shape.getGlobalBounds().intersects(moneda.getDraw().getGlobalBounds());
}

bool Personaje::colisionaCon(const Trampa& trampa)
{
    // Obtiene la posición X del objeto _shape del personaje
    float posXPersonaje = _shape.getPosition().x;
    float posYPersonaje = ((_shape.getPosition().y)+50);//porque tengo a personaje en y=400 y el piso en y=450


    // Obtiene la posición X del objeto devuelto por getDraw() de la trampa
    float posXTrampa = trampa.getPosition().x;
    float posYTrampa = trampa.getPosition().y;

    if(posXPersonaje==posXTrampa&&posYPersonaje==posYTrampa)
    {

        activarCaida(); // Llamar a la función auxiliar para activar la caída
        return true;

    }

    return false; // Indicar que no hubo colisión


}

bool Personaje::colisionPuertaBlanca(const PuertaBlanca& _puertaRec)
{
    float posXPersonaje = _shape.getPosition().x;
    float posYPersonaje = _shape.getPosition().y;
    float posXPuerta = _puertaRec.getPosition().x;
    float posYPuerta = _puertaRec.getPosition().y;
    if(posXPersonaje==posXPuerta&&posYPersonaje==posYPuerta)
    {
        return true;
    }

}

