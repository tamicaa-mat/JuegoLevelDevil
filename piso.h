#ifndef PISO_H_INCLUDED
#define PISO_H_INCLUDED
#include <SFML/Graphics.hpp>

class Piso {
private:
    sf::RectangleShape _forma; // Forma del piso

public:
    Piso(float ancho, float altura);

    // Método para dibujar el piso
 sf::RectangleShape& getdraw();

};




#endif // PISO_H_INCLUDED
