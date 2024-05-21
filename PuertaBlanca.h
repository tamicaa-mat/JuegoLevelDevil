#ifndef PUERTABLANCA_H_INCLUDED
#define PUERTABLANCA_H_INCLUDED
#include <SFML/Graphics.hpp>

class PuertaBlanca {
private:
    bool _estadoPuerta; // Estado de la puerta (abierta/cerrada)
    sf::Vector2f _posicionPuerta; // Posici�n de la puerta
    sf::Color _colorPuerta; // Color de la puerta

public:
    // Constructor que inicializa la puerta en una posici�n y con un color espec�ficos
    PuertaBlanca();

    // M�todos para establecer la posici�n y el color de la puerta
    void setPosition();
    void setColor();

    // Otros m�todos para gestionar el estado de la puerta (abrir, cerrar, etc.) si es necesario
};

#endif // PUERTABLANCA_H_INCLUDED
