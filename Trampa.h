#ifndef TRAMPA_H_INCLUDED
#define TRAMPA_H_INCLUDED


class Trampa {
private:
    sf::RectangleShape _trampa;
    sf::Vector2f _setPosition();
    bool _visible;

public:
Trampa(float posX, float posY);

const sf::RectangleShape& getDraw() const;
void setVisible(bool visible);
 sf::Vector2f getPosition()const;
 void aparecer();

};





#endif // TRAMPA_H_INCLUDED
