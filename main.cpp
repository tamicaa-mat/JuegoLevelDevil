#include <SFML/Graphics.hpp>
#include "gamePlay.h"
#include "Personaje.h"
#include "PuertaBlanca.h"
#include "Monedas.h"
#include "piso.h"
#include "MenuPrincipal.h"
#include "Nivel1.h"
#include "Obstaculo.h"

int main() {
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "SFML Window");
    ventana.setFramerateLimit(60);

    MenuPrincipal menuPrincipal(ventana);

    bool juegoIniciado = false;

    while (ventana.isOpen()) {
        if (!juegoIniciado) {
            // Mostrar el men� principal
            menuPrincipal.manejarEntrada();
            menuPrincipal.actualizar();
            menuPrincipal.dibujar();

            // Verificar si el bot�n "Jugar" ha sido presionado
            if (menuPrincipal.esBotonJugarPresionado()) {
                juegoIniciado = true;
            }
        } else {
            // Crear y manejar el primer nivel
            Nivel1 nivel1(ventana);

            while (ventana.isOpen()) {
                nivel1.manejarEntrada();
                nivel1.actualizar();
                nivel1.dibujar();

                // Verificar si el estado de "Game Over" ha sido resuelto
                if (nivel1.isGameOverResolved()) {
                    juegoIniciado = false;
                    break;
                }
            }
        }
    }

    return 0;
}
