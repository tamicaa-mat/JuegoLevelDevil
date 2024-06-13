#ifndef TRAMPA_H_INCLUDED
#define TRAMPA_H_INCLUDED

#include <SFML/Graphics.hpp>

class Trampa {
private:
    sf::RectangleShape _trampa;
    sf::Vector2f _posicionInicial;
    bool _visible;
    bool _animando;
    float _tiempoAnimacion;
    float _duracionAnimacion;

public:
    Trampa(float posX, float posY);
    const sf::RectangleShape& getDraw() const;
    void setVisible(bool visible);
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;
    void aparecer();
    void reiniciar();
    void actualizar(float deltaTime);
    bool getVisible() const;

};

#endif // TRAMPA_H_INCLUDED


