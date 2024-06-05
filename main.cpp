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
#include "NivelIntermedio.h"

int main() {
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "SFML Window");
    ventana.setFramerateLimit(60);

    MenuPrincipal menuPrincipal(ventana);

    bool juegoIniciado = false;
    bool nivel1Completado = false;

    while (ventana.isOpen()) {
        if (!juegoIniciado) {
            // Mostrar el menú principal
            menuPrincipal.manejarEntrada();
            menuPrincipal.actualizar();
            menuPrincipal.dibujar();

            // Verificar si el botón "Jugar" ha sido presionado
            if (menuPrincipal.esBotonJugarPresionado()) {
                juegoIniciado = true;
                nivel1Completado = false; // Reiniciar el estado de nivel completado
            }
        } else if (nivel1Completado) {
            // Mostrar la pantalla intermedia
            NivelIntermedio nivelIntermedio(ventana);

            while (ventana.isOpen()) {
                nivelIntermedio.manejarEntrada();
                nivelIntermedio.actualizar();
                nivelIntermedio.dibujar();

                if (nivelIntermedio.esBotonJugarNivel2Presionado()) {
                    nivel1Completado = false; // Resetear el estado del nivel intermedio
                    break;
                }
            }

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
        } else {
            // Crear y manejar el primer nivel
            Nivel1 nivel1(ventana);

            while (ventana.isOpen()) {
                nivel1.manejarEntrada();
                nivel1.actualizar();
                nivel1.dibujar();

                // Verificar si el estado de "Game Over" ha sido resuelto
                if (nivel1.isGameOverResolved()) {
                    if (nivel1.isGameOver()) { // Utiliza el nuevo método isGameOver
                        juegoIniciado = false; // Si es "Game Over", regresar al menú principal
                    } else {
                        nivel1Completado = true; // Indicar que el nivel 1 ha sido completado
                    }
                    break;
                }
            }
        }
    }

    return 0;
}
