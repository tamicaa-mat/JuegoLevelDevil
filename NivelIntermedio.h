#ifndef NIVELINTERMEDIO_H_INCLUDED
#define NIVELINTERMEDIO_H_INCLUDED

#include <SFML/Graphics.hpp>

class NivelIntermedio {
private:
    sf::RenderWindow& ventana;
    sf::Font fuente;

    sf::Text textoIntermedio1;
    sf::Text textoIntermedio2;

    sf::Text botonJugarNivel2;
    sf::Text botonJugarNivel3;

    sf::Text textoIntermedio3;
    sf::Text botonJugarNivel4;


public:
    NivelIntermedio(sf::RenderWindow& vent);
    void manejarEntrada();
    void actualizar();
    void dibujar();
    void dibujarN2();
    void dibujarN3();
    bool esBotonJugarNivel2Presionado();
    bool esBotonJugarNivel3Presionado();
    bool esBotonJugarNivel4Presionado();
};

#endif // NIVELINTERMEDIO_H_INCLUDED
