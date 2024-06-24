#include <SFML/Graphics.hpp>
#include "gamePlay.h"
#include "MenuPrincipal.h"
#include "DarNombreJugador.h"
#include "Jugador.h"
#include "Nivel1.h"
#include "NivelIntermedio.h"
#include "Nivel2.h"
#include "Records.h"
#include "Nivel3.h"
#include "Nivel4.h"

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
    bool nivel3Completado = false;
    bool nivel4Completado= false;

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
                    pedirNombreJugador = true;///agregar alguna condicion para que no lo pida  siempre, sino solo si queres iniciar una partida nueva, sino
                    ///te tiene que dar la opcion de continuar tu partida
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


        else if (nivel1Completado)// si se completo nivel1 , comienza nivel 2
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

            /// Crear y manejar el segundo nivel
            Nivel2 nivel2(ventana,*jugador);

            while (ventana.isOpen())
            {
                nivel2.manejarEntrada();
                nivel2.actualizar();
                nivel2.dibujar();

                ///Verificar si el estado de "Game Over" ha sido resuelto en el segundo nivel

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
                        nivel2Completado = true; // Indicar que el nivel 2 ha sido completado
                    }
                    break;
                }
            }
        }
        else
        {
            // Crear y manejar el primer nivel, si nivel1completado es falso, arranca nivel1
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


        ///agrego aca nivel3 prueba//////////////////////////////////////////////////////ELSE AQUI/////////////////////////////////////////////////////////////////////////

        if((nivel2Completado)&&(!nivel3Completado))
        {

            NivelIntermedio nivelIntermedio(ventana);

            while (ventana.isOpen())
            {
                nivelIntermedio.manejarEntrada();
                nivelIntermedio.actualizar();
                nivelIntermedio.dibujarN2();

                if (nivelIntermedio.esBotonJugarNivel3Presionado())
                {
                    nivel2Completado = false; // Resetear el estado del nivel intermedio
                    break;
                }
            }

            ///crear NIVEL3
            Nivel3 nivel3(ventana,*jugador);

            while (ventana.isOpen())
            {
                nivel3.manejarEntrada();
                nivel3.actualizar();
                nivel3.dibujar();

                ///Verificar si el estado de "Game Over" ha sido resuelto en el segundo nivel
                if (nivel3.isGameOverResolved())
                {
                    if (nivel3.isGameOver())   // Utiliza el nuevo método isGameOver
                    {
                        jugador->setPuntaje(nivel3.getContadorMonedas());
                        jugador->grabarArchivo(); // Guardar el puntaje del jugador en el archivo
                        juegoIniciado = false; // Si es "Game Over", regresar al menú principal
                        pedirNombreJugador = false; // Resetear para pedir el nombre del jugador otra vez
                        menuPrincipal.resetBotones(); // Resetear los botones
                        darNombreJugador.resetNombreIngresado(); // Resetear el estado del nombre ingresado
                    }
                    else
                    {
                        nivel3Completado = true;
                    }
                    break;

                }
            }
        }

        //////algo pasa del nivel 3 va al 1, y no al 4

        if((nivel3Completado)&&(!nivel4Completado)){


            NivelIntermedio nivelIntermedio(ventana);

            while (ventana.isOpen())
            {
                nivelIntermedio.manejarEntrada();
                nivelIntermedio.actualizar();
                nivelIntermedio.dibujarN3();

                if (nivelIntermedio.esBotonJugarNivel3Presionado())
                {
                    nivel3Completado = false; // Resetear el estado del nivel intermedio
                    break;
                }
            }

            ///crear NIVEL4
            Nivel4 nivel4(ventana,*jugador);

            while (ventana.isOpen())
            {
                nivel4.manejarEntrada();
                nivel4.actualizar();
                nivel4.dibujar();

                ///Verificar si el estado de "Game Over" ha sido resuelto en el segundo nivel
                if (nivel4.isGameOverResolved())
                {
                    if (nivel4.isGameOver())   // Utiliza el nuevo método isGameOver
                    {
                        jugador->setPuntaje(nivel4.getContadorMonedas());
                        jugador->grabarArchivo(); // Guardar el puntaje del jugador en el archivo
                        juegoIniciado = false; // Si es "Game Over", regresar al menú principal
                        pedirNombreJugador = false; // Resetear para pedir el nombre del jugador otra vez
                        menuPrincipal.resetBotones(); // Resetear los botones
                        darNombreJugador.resetNombreIngresado(); // Resetear el estado del nombre ingresado
                    }
                    else
                    {
                        nivel4Completado = true; //
                    }
                    break;

                }
            }
        }





        }




///////////////////////////////////////////////////////yo aca



    if (jugador)
    {
        delete jugador;
    }

    return 0;
}
