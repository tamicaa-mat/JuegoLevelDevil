
#include <SFML/Graphics.hpp>
#include"PuertaBlanca.h"


PuertaBlanca::PuertaBlanca(float x, float y) {
        _puertaRec.setSize(sf::Vector2f(40, 65)); // Establecer el tamaño d LA PUERTA
        _puertaRec.setFillColor(sf::Color::White); // Establecer el color de PUERTA
        // Establecer la posición del piso como fijo en la parte inferior de la ventana
        _puertaRec.setPosition(x,y);
        _tiempoAchicando=0.0;
        _cerrando=false;
        _visiblePB=false;

    }


sf::Vector2f PuertaBlanca::getPosition() const {
    return _puertaRec.getPosition();
}


void PuertaBlanca::setPosition(float x, float y) {
    _puertaRec.setPosition(x, y);
}
void PuertaBlanca::iniciarCerrado() {
    _cerrando = true;
}

void PuertaBlanca::achicar(float deltaTime){

    if(_cerrando){
            _tiempoAchicando += deltaTime;
    _tiempoAchicando = 100.0f;
   sf::Vector2f size = _puertaRec.getSize();
            size.y -= 0.2f; // Reducir altura en 1 píxel
            if (size.y < 0) size.y = 0; // Asegurarse de que no sea negativo
            _puertaRec.setSize(size);
    }

}

void PuertaBlanca::setVisible(bool ver){

_visiblePB=ver;

}

void PuertaBlanca::aparecerPB(){
_visiblePB=true;
}

sf::RectangleShape& PuertaBlanca::getDraw()
{
       if (_visiblePB) {
        return _puertaRec;
    } else {
        // Si la moneda no debe ser dibujada, devuelve una forma fuera de la pantalla
        static  sf::RectangleShape emptyShape;
        return emptyShape;
    }
}













