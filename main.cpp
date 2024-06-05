
#include <SFML/Graphics.hpp>
#include "gamePlay.h"
#include "Personaje.h"
#include "PuertaBlanca.h"
#include "Monedas.h"
#include "piso.h"
#include "MenuPrincipal.h"
#include "Nivel1.h"
#include "Obstaculo.h"
#include "Nivel2.h"

int main() {
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "SFML Window");
    ventana.setFramerateLimit(60);

    MenuPrincipal menuPrincipal(ventana);

    bool juegoIniciado = false;

    while (ventana.isOpen()) {
        if (!juegoIniciado) {
            // Mostrar el menú principal
            menuPrincipal.manejarEntrada();
            menuPrincipal.actualizar();
            menuPrincipal.dibujar();

            // Verificar si el botón "Jugar" ha sido presionado
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

            // Si el juego terminó porque el jugador murió, iniciar el segundo nivel
            if (!juegoIniciado) {
                // Crear y manejar el segundo nivel
                Nivel2 nivel2(ventana);

                while (ventana.isOpen()) {
                    nivel2.manejarEntrada();
                    nivel2.actualizar();
                    nivel2.dibujar();

                    // Verificar si el estado de "Game Over" ha sido resuelto en el segundo nivel
                    if (nivel2.isGameOverResolved()) {
                        juegoIniciado = false;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
