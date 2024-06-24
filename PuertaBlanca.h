
#ifndef PUERTABLANCA_H_INCLUDED
#define PUERTABLANCA_H_INCLUDED
#include <SFML/Graphics.hpp>

class PuertaBlanca
{
private:
    sf::RectangleShape _puertaRec;
    sf::Vector2f _posicionPuertaBlanca;
public:
    PuertaBlanca(float x, float y);
    //PuertaBlanca();
 void setPosition(float x, float y);

 sf::Vector2f getPosition() const;
    // Método para dibujar la puerta
 sf::RectangleShape& getDraw();

};



#endif // PUERTABLANCA_H_INCLUDED


