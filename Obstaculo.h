#ifndef OBSTACULO_H_INCLUDED
#define OBSTACULO_H_INCLUDED

#include <SFML/Graphics.hpp>

class Obstaculo {
private:

    sf::RectangleShape _shape;
   // bool _visibleObst;

public:
    Obstaculo(float x, float y, float width, float height);
    const sf::RectangleShape& getDraw() const;
   // void setVisible(bool visible);
    void aparecer();
};

#endif // OBSTACULO_H_INCLUDED
