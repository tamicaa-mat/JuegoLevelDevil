#ifndef MONEDAS_H_INCLUDED
#define MONEDAS_H_INCLUDED

#include <SFML/Graphics.hpp>


class Monedas {
private:
     _posicionMoneda; // Posición de la moneda
    sf::Color _color; // Color de la moneda
    float _radio; // Radio del círculo de la moneda

public:
    // Constructor que inicializa la moneda en una posición específica y con un color y radio dados
    Monedas();

    // Métodos para obtener la posición, el color y el radio de la moneda

    sf::Vector2f getPosition();
    sf::Color getColor();
    float getRadius() ;
    // Métodos para establecer la posición, el color y el radio de la moneda
    void setPosition();
    void setColor();

    void setRadius();


};


#endif // MONEDAS_H_INCLUDED
