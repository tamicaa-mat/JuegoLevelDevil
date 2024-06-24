#ifndef OBSTACULO_H_INCLUDED
#define OBSTACULO_H_INCLUDED

#include <SFML/Graphics.hpp>


class Obstaculo {
private:
    sf::RectangleShape _shape;
    sf::Vector2f _position;
    float _velocidadHorizontal;
    bool _visibleObst;

public:
    Obstaculo(float x, float y, float width, float height);
    const sf::RectangleShape& getDraw() const;
    void moverIzquierda();
    void setVelocidadHorizontal(float velocidad);
    void setPosicion(float x, float y);
    void aparecer();
    //void setVisible(bool visible);


};
#endif // OBSTACULO_H_INCLUDED
