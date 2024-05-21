#include "gamePlay.h"
#include"Personaje.h"
gamePlay::gamePlay(){


}


void gamePlay::update(){
_shape.update();

}

void gamePlay::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Limpiar la ventana con un color de fondo (por ejemplo, blanco)
    target.clear(sf::Color::White);

    // Dibujar el fondo del piso
    sf::RectangleShape floor(sf::Vector2f(target.getSize().x, 50)); // Supongamos que el piso tiene una altura de 50 píxeles
    floor.setFillColor(sf::Color(128, 128, 128)); // Gris oscuro, puedes ajustar el color según lo necesites
    floor.setPosition(0, target.getSize().y - 50); // Coloca el piso en la parte inferior de la ventana

    // Dibujar el personaje, la puerta, las monedas, etc. (suponiendo que ya están definidos y listos para ser dibujados)
    // Por ejemplo:
    target.draw(floor, states);
    target.draw(_p, states); // Dibuja el personaje
    target.draw(_puerta, states); // Dibuja la puerta
    target.draw(_monedas, states); // Dibuja las monedas
}



