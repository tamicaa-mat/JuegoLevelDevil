#include "Obstaculo.h"


//void Obstaculo::setVisible(bool visible) {
//    _visibleObst = visible;
//}
//
//void Obstaculo::aparecer(){
//    _visibleObst=true;
//}

//const sf::RectangleShape& Obstaculo::getDraw() const {
//     if (_visibleObst) {
//        return _shape;
//    } else {
//        static sf::RectangleShape emptyShape;
//        return emptyShape;
//    }
//
//}
Obstaculo::Obstaculo(float x, float y, float width, float height)
    : _velocidadHorizontal(0.0f) {
    _shape.setSize(sf::Vector2f(width, height));
    _shape.setFillColor(sf::Color::Red);
    _shape.setPosition(x, y);
    _position = sf::Vector2f(x, y);
}

const sf::RectangleShape& Obstaculo::getDraw() const {
    return _shape;
}

void Obstaculo::moverIzquierda() {
    _velocidadHorizontal=5.0f;
    _position.x -= (_velocidadHorizontal);
    _shape.move(_position.x,_position.y);
    _shape.setPosition(_position);
}

void Obstaculo::setVelocidadHorizontal(float velocidad) {
    _velocidadHorizontal = velocidad;
}

void Obstaculo::setPosicion(float x, float y) {
    _position.x = x;
    _position.y = y;
    _shape.setPosition(_position);
}
