#include <SFML/Graphics.hpp>
#include "Trampa.h"

Trampa::Trampa(float posX, float posY) :
    _trampa(sf::Vector2f(50.0f, 150.0f)),
    _posicionInicial(posX, posY),
    _visible(false),
    _animando(false),
    _tiempoAnimacion(0.0f),
    _duracionAnimacion(1.0f) // La animación dura 1 segundo
{
    _trampa.setFillColor(sf::Color::White);
    _trampa.setPosition(posX, posY);
}

sf::Vector2f Trampa::getPosition() const {
    return _trampa.getPosition();
}

   sf::Vector2f Trampa::getSize() const {
        return _trampa.getSize();
    }



void Trampa::setVisible(bool visible) {
    _visible = visible;
}

void Trampa::aparecer() {
    _animando = true; // Iniciar animación
    _tiempoAnimacion = 5.0f;
    _visible = true;
}

void Trampa::reiniciar() {
    _trampa.setPosition(_posicionInicial);
    _visible = false;
    _animando = false;
    _tiempoAnimacion = 0.0f;
}

void Trampa::actualizar(float deltaTime) {
    if (_animando) {
        _tiempoAnimacion += deltaTime;
        float factor = _tiempoAnimacion / _duracionAnimacion;
        if (factor >= 1.0f) {
            _animando = false;
            factor = 1.0f;
        }
        // Escalado para hacer la animación de aparición
        _trampa.setScale(factor, factor);
    }
}

const sf::RectangleShape& Trampa::getDraw() const {
    if (_visible) {
        return _trampa;
    } else {
        static sf::RectangleShape emptyShape;
        return emptyShape;
    }
}

bool Trampa::getVisible() const {
    return _visible;
}


