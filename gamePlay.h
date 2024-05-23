<<<<<<< HEAD
#ifndef GAMEPLAY_H_INCLUDED
#define GAMEPLAY_H_INCLUDED
#include <SFML/Graphics.hpp>
#include"Personaje.h"
#include"PuertaBlanca.h"
#include"Monedas.h"

class gamePlay{
private:
Personaje _p;
//PuertaBlanca _puerta;
//Monedas _monedas;

public:
gamePlay ();
void update();
void draw(sf::RenderTarget& target,sf::RenderStates states) const;



};





#endif // GAMEPLAY_H_INCLUDED
=======
#ifndef GAMEPLAY_H_INCLUDED
#define GAMEPLAY_H_INCLUDED
#include <SFML/Graphics.hpp>
#include"Personaje.h"
#include"PuertaBlanca.h"
#include"Monedas.h"

class gamePlay{
private:
Personaje _p;
//PuertaBlanca _puerta;
//Monedas _monedas;

public:
gamePlay ();
void update();
void draw(sf::RenderTarget& target,sf::RenderStates states) const;



};





#endif // GAMEPLAY_H_INCLUDED
>>>>>>> 6f61caf099bd79490bf4755cf2e83f910632a5e9
