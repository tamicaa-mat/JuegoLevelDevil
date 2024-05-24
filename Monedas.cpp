
#include <SFML/Graphics.hpp>

#include"Monedas.h"

Moneda::Moneda()
{
    _shapeMoneda.setFillColor(sf::Color::Yellow);
    _shapeMoneda.setRadius(10);
    _shapeMoneda.setPosition(300,200);
    _visible=true;

}

void Moneda::desaparecer(){

 _visible=false;

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
