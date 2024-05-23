
#ifndef PUERTABLANCA_H_INCLUDED
#define PUERTABLANCA_H_INCLUDED
#include <SFML/Graphics.hpp>

class PuertaBlanca
{
private:
    sf::RectangleShape _puertaRec;
    sf::Vector2f _posicionPuertaBlanca;
public:
    PuertaBlanca(float ancho, float altura);

    // Método para dibujar la puerta
 sf::RectangleShape& getDraw();

};
#endif // PUERTABLANCA_H_INCLUDED


