#ifndef NIVELINTERMEDIO_H_INCLUDED
#define NIVELINTERMEDIO_H_INCLUDED

#include <SFML/Graphics.hpp>

class NivelIntermedio {
private:
    sf::RenderWindow& ventana;
    sf::Font fuente;
    sf::Text textoIntermedio;
    sf::Text botonJugarNivel2;
    sf::Text botonJugarNivel3;

public:
    NivelIntermedio(sf::RenderWindow& vent);
    void manejarEntrada();
    void actualizar();
    void dibujar();
    bool esBotonJugarNivel2Presionado();
    bool esBotonJugarNivel3Presionado();
};

#endif // NIVELINTERMEDIO_H_INCLUDED
