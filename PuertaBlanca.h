<<<<<<< HEAD
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

    // M�todo para dibujar la puerta
 sf::RectangleShape& getDraw();

};












#endif // PUERTABLANCA_H_INCLUDED
=======
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

    // M�todo para dibujar la puerta
 sf::RectangleShape& getDraw();

};












#endif // PUERTABLANCA_H_INCLUDED
>>>>>>> 6f61caf099bd79490bf4755cf2e83f910632a5e9
