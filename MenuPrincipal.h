#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

#include <SFML/Graphics.hpp>

class MenuPrincipal {
private:
    sf::Font fuente;
    sf::Text textoBienvenida;
    sf::Text botonJugar;
    sf::RenderWindow& ventana;

public:
    MenuPrincipal(sf::RenderWindow& vent);
    void manejarEntrada();
    void actualizar();
    void dibujar();
    bool esBotonJugarPresionado();
};

#endif // MENUPRINCIPAL_H_INCLUDED
