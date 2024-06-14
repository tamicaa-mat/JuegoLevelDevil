#include <SFML/Graphics.hpp>
#include "gamePlay.h"
#include "MenuPrincipal.h"
#include "DarNombreJugador.h"
#include "Jugador.h"
#include "Nivel1.h"
#include "NivelIntermedio.h"
#include "Nivel2.h"
#include "Records.h"

int main()
{
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "SFML Window");
    ventana.setFramerateLimit(60);

    MenuPrincipal menuPrincipal(ventana);
    DarNombreJugador darNombreJugador(ventana);
    Jugador* jugador = nullptr;

    bool juegoIniciado = false;
    bool nivel1Completado = false;
    bool nivel2Completado = false;
    bool pedirNombreJugador = false;
    bool mostrarRecords = false;

    while (ventana.isOpen())
    {
        if (!juegoIniciado && !mostrarRecords)
        {
            if (!pedirNombreJugador)
            {
                menuPrincipal.manejarEntrada();
                menuPrincipal.actualizar();
                menuPrincipal.dibujar();

                if (menuPrincipal.esBotonJugarPresionado())
                {
                    pedirNombreJugador = true;
                }
                if (menuPrincipal.esBotonRecordsPresionado())
                {
                    mostrarRecords = true;
                }
            }
            else
            {
                darNombreJugador.manejarEntrada();
                darNombreJugador.actualizar();
                darNombreJugador.dibujar();

                if (darNombreJugador.esNombreIngresado())
                {
                    if (jugador)
                    {
                        delete jugador;
                    }
                    jugador = new Jugador(darNombreJugador.getNombreJugador());
                    juegoIniciado = true;
                    nivel1Completado = false;
                    pedirNombreJugador = false; // Resetear para la próxima vez
                }
            }
        }
        else if (mostrarRecords)
        {
            Records records(ventana);

            while (ventana.isOpen())
            {
                records.manejarEntrada();
                records.dibujar();
            }
            mostrarRecords = false; // Resetear para volver al menú principal
            menuPrincipal.resetBotones(); // Resetear los botones
        }
        else if (nivel1Completado)
        {
            // Mostrar la pantalla intermedia
            NivelIntermedio nivelIntermedio(ventana);

            while (ventana.isOpen())
            {
                nivelIntermedio.manejarEntrada();
                nivelIntermedio.actualizar();
                nivelIntermedio.dibujar();

                if (nivelIntermedio.esBotonJugarNivel2Presionado())
                {
                    nivel1Completado = false; // Resetear el estado del nivel intermedio
                    break;
                }
            }

            // Crear y manejar el segundo nivel falta nivel 3 en main
            Nivel2 nivel2(ventana,*jugador);

            while (ventana.isOpen())
            {
                nivel2.manejarEntrada();
                nivel2.actualizar();
                nivel2.dibujar();

                // Verificar si el estado de "Game Over" ha sido resuelto en el segundo nivel
                if (nivel2.isGameOverResolved())
                {
                    if (nivel2.isGameOver())   // Utiliza el nuevo método isGameOver
                    {
                        jugador->setPuntaje(nivel2.getContadorMonedas());
                        jugador->grabarArchivo(); // Guardar el puntaje del jugador en el archivo
                        juegoIniciado = false; // Si es "Game Over", regresar al menú principal
                        pedirNombreJugador = false; // Resetear para pedir el nombre del jugador otra vez
                        menuPrincipal.resetBotones(); // Resetear los botones
                        darNombreJugador.resetNombreIngresado(); // Resetear el estado del nombre ingresado
                    }
                    else
                    {
                        nivel2Completado = true; // Indicar que el nivel 1 ha sido completado
                    }
                    break;
                }
            }
        }
        else
        {
            // Crear y manejar el primer nivel
            Nivel1 nivel1(ventana, *jugador);

            while (ventana.isOpen())
            {
                nivel1.manejarEntrada();
                nivel1.actualizar();
                nivel1.dibujar();

                // Verificar si el estado de "Game Over" ha sido resuelto
                if (nivel1.isGameOverResolved())
                {
                    if (nivel1.isGameOver())   // Utiliza el nuevo método isGameOver
                    {
                        jugador->setPuntaje(nivel1.getContadorMonedas());
                        jugador->grabarArchivo(); // Guardar el puntaje del jugador en el archivo
                        juegoIniciado = false; // Si es "Game Over", regresar al menú principal
                        pedirNombreJugador = false; // Resetear para pedir el nombre del jugador otra vez
                        menuPrincipal.resetBotones(); // Resetear los botones
                        darNombreJugador.resetNombreIngresado(); // Resetear el estado del nombre ingresado
                    }
                    else
                    {
                        nivel1Completado = true; // Indicar que el nivel 1 ha sido completado
                    }
                    break;
                }
            }
        }
    }

    if (jugador)
    {
        delete jugador;
    }

    return 0;
}
