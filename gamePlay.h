#ifndef GAMEPLAY_H_INCLUDED
#define GAMEPLAY_H_INCLUDED
#include <SFML/Graphics.hpp>
#include"Personaje.h"
#include"PuertaBlanca.h"
#include"Monedas.h"

class gamePlay{
private:
Personaje _p;
PuertaBlanca _puerta;
Monedas _monedas;

public:
gamePlay ();
void update();
void draw(sf::RenderTarget& target,sf::RenderStates states) const;



};





#endif // GAMEPLAY_H_INCLUDED
