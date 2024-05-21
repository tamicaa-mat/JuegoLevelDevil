#ifndef MONEDAS_H_INCLUDED
#define MONEDAS_H_INCLUDED

#include <SFML/Graphics.hpp>


class Monedas {
private:
     _posicionMoneda; // Posici�n de la moneda
    sf::Color _color; // Color de la moneda
    float _radio; // Radio del c�rculo de la moneda

public:
    // Constructor que inicializa la moneda en una posici�n espec�fica y con un color y radio dados
    Monedas();

    // M�todos para obtener la posici�n, el color y el radio de la moneda

    sf::Vector2f getPosition();
    sf::Color getColor();
    float getRadius() ;
    // M�todos para establecer la posici�n, el color y el radio de la moneda
    void setPosition();
    void setColor();

    void setRadius();


};


#endif // MONEDAS_H_INCLUDED
