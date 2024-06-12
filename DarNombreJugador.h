#ifndef DARNOMBREJUGADOR_H_INCLUDED
#define DARNOMBREJUGADOR_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>

class DarNombreJugador {
private:
    sf::Font fuente;
    sf::Text textoInstruccion;
    sf::Text textoNombre;
    sf::RenderWindow& ventana;
    std::string nombreJugador;
    bool nombreIngresado;

public:
    DarNombreJugador(sf::RenderWindow& vent);
    void manejarEntrada();
    void actualizar();
    void dibujar();
    bool esNombreIngresado() const;
    const std::string& getNombreJugador() const;
    void resetNombreIngresado();
};

#endif // DARNOMBREJUGADOR_H_INCLUDED
