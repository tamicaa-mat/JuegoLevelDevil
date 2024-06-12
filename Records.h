#ifndef RECORDS_H_INCLUDED
#define RECORDS_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>
#include "Jugador.h"

class Records {
private:
    sf::Font fuente;
    sf::Text textoTitulo;
    std::vector<sf::Text> textosJugadores;
    sf::RenderWindow& ventana;

public:
    Records(sf::RenderWindow& vent);
    void cargarRecords();
    void manejarEntrada();
    void dibujar();
};

#endif // RECORDS_H_INCLUDED
