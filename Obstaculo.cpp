#include "Obstaculo.h"

Obstaculo::Obstaculo(float x, float y, float width, float height) {
    _shape.setSize(sf::Vector2f(width, height));
    _shape.setFillColor(sf::Color::Red);
    _shape.setPosition(x, y);

}

//const sf::RectangleShape& Obstaculo::getDraw() const {
//     if (_visibleObst) {
//        return _shape;
//    } else {
//        static sf::RectangleShape emptyShape;
//        return emptyShape;
//    }
//
//}


const sf::RectangleShape& Obstaculo::getDraw() const {

        return _shape;

}



//
//void Obstaculo::setVisible(bool visible) {
//    _visibleObst = visible;
//}
//
//void Obstaculo::aparecer(){
//    _visibleObst=true;
//}

