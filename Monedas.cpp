#include <SFML/Graphics.hpp>
#include"Monedas.h"


Moneda::Moneda(float x, float y, int radio) {
     _shapeMoneda.setFillColor(sf::Color::Yellow);
    _shapeMoneda.setPosition(x, y);
    _shapeMoneda.setRadius(radio);
    _visible=true;
}

void Moneda::desaparecer(){

 _visible=false;

}

void Moneda::aparecer(){
_visible=true;
}

const sf::CircleShape& Moneda::getDraw() const {
      if (_visible) {
        return _shapeMoneda;
    } else {
        // Si la moneda no debe ser dibujada, devuelve una forma fuera de la pantalla
        static sf::CircleShape emptyShape;
        return emptyShape;
    }
}
