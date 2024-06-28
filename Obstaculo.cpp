#include "Obstaculo.h"



Obstaculo::Obstaculo(float x, float y, float width, float height)
    : _velocidadHorizontal(0.0f),_velocidadVertical(0.0f) {
    _shape.setSize(sf::Vector2f(width, height));
    _shape.setFillColor(sf::Color::Red);
    _shape.setPosition(x, y);
    _position = sf::Vector2f(x, y);
    _visibleObst=true;
}



void Obstaculo::moverIzquierda() {
    _velocidadHorizontal=5.0f;
    _position.x -= (_velocidadHorizontal);
    _shape.move(_position.x,_position.y);
    _shape.setPosition(_position);
}

void Obstaculo::caer(){
    _velocidadVertical=2.5f;
    _position.y -= (-_velocidadVertical);
    _shape.move(_position.x,_position.y);
    _shape.setPosition(_position);
}

//void Obstaculo::caer(){
//    _velocidadVertical = 2.5f;
//    _position.y += _velocidadVertical;
//    _shape.setPosition(_position);
//}

void Obstaculo::iniciarCaida() {
    _debeCaer = true;
}

void Obstaculo::actualizarObst(float deltaTime) {
    if (_debeCaer) {
        caer();
    }
}

void Obstaculo::setVelocidadHorizontal(float velocidad) {
    _velocidadHorizontal = velocidad;
}

///TODO:FALTA REINICIAR EL OBSTACULO
void Obstaculo::setPosicion(float x, float y) {
    _position.x = x;
    _position.y = y;
    _shape.setPosition(_position);
}

//void Obstaculo::setVisible(bool visible) {
//    _visibleObst = visible;
//}

void Obstaculo::aparecer(){
    _visibleObst=true;
    _shape.setPosition(_shape.getPosition());
    _velocidadHorizontal=0.0;
}



const sf::RectangleShape& Obstaculo::getDraw() const {
     if (_visibleObst) {
        return _shape;
    } else {
        static sf::RectangleShape emptyShape;
        return emptyShape;
    }

}

sf::Vector2f Obstaculo::getPositionO()const
{
    return _shape.getPosition();
}
