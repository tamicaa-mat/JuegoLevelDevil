#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>
#include "Obstaculo.h"
#include "Monedas.h"
#include "Trampa.h"
#include "PuertaBlanca.h"

enum ESTADO {
    QUIETO,
    CAMINANDO_ADELANTE,
    CAMINANDO_ATRAS,
    SALTANDO,
    SALTANDO_ADELANTE,
    SALTANDO_ATRAS,
    CAYENDO,
};

class Personaje {
private:
    sf::CircleShape _shape;
    ESTADO _estado;
    float _velocidadSalto;
    float _velocidadSaltoHorizontal;
    float _velocidadMovimiento;
    float _velocidadCaida;
    bool fueraJuego;
    sf::Vector2f _posicion;

public:
    Personaje(float x, float y);
    void cmd();
    void update();
    sf::Drawable& getDraw();
    void activarCaida();
    bool colisionaCon(const Obstaculo& obstaculo);
    bool colisionaCon(const Moneda& moneda) const;
    bool colisionaCon(const Trampa& trampa);
    bool colisionPuertaBlanca(const PuertaBlanca& puertablanca);
    sf::Vector2f getPosition() const;
    void caer();
    void reset(float x, float y); // Nuevo método para restablecer la posición y el estado
};

#endif // PERSONAJE_H
