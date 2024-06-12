#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

#include <SFML/Graphics.hpp>

class MenuPrincipal {
private:
    sf::Font fuente;
    sf::Text textoBienvenida;
    sf::Text botonJugar;
    sf::Text botonRecords;
    sf::RenderWindow& ventana;
    bool botonJugarPresionado;
    bool botonRecordsPresionado;

public:
    MenuPrincipal(sf::RenderWindow& vent);
    void manejarEntrada();
    void actualizar();
    void dibujar();
    bool esBotonJugarPresionado() const;
    bool esBotonRecordsPresionado() const;
    void resetBotones();
};

#endif // MENUPRINCIPAL_H_INCLUDED
