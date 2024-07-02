#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


#include "MenuPrincipal.h"
#include "DarNombreJugador.h"
#include "Jugador.h"
#include "Nivel1.h"
#include "NivelIntermedio.h"
#include "Nivel2.h"
#include "Records.h"
#include "Nivel3.h"
#include "Nivel4.h"
#include "ArchivoJugador.h"

int main()
{
     sf::RenderWindow ventana(sf::VideoMode(800, 600), "SFML Window");
    ventana.setFramerateLimit(60);

    MenuPrincipal menuPrincipal(ventana);
    DarNombreJugador darNombreJugador(ventana);
    Jugador objJugador;
    ArchivoJugador archiJugador;
    int numNivel = 0;
    bool juegoIniciado = false;
    bool nivel1Completado = false;
    bool nivel2Completado = false;
    bool nivel3Completado = false;
    bool nivel4Completado = false;
    int puntajePartida=0;
    bool pedirNombreJugador = false;
    bool mostrarRecords = false;
    bool continuaPartida = false;


    while (ventana.isOpen())
    {
        if (!juegoIniciado && !mostrarRecords && !continuaPartida)
        {
            if(!pedirNombreJugador)
            {
                menuPrincipal.manejarEntrada();
                menuPrincipal.actualizar();
                menuPrincipal.dibujar();

                if (menuPrincipal.esBotonJugarPresionado())
                {
                    pedirNombreJugador = true;
                    menuPrincipal.resetBotones();

                }
                if (menuPrincipal.esBotonRecordsPresionado())
                {
                    mostrarRecords = true;
                    menuPrincipal.resetBotones();
                }
                if (menuPrincipal.esBotonContinuarPartidaPresionado())
                {

                    continuaPartida=true;
                    menuPrincipal.resetBotones();

                }
            }

            else
            {
                darNombreJugador.manejarEntrada();
                darNombreJugador.actualizar();
                darNombreJugador.dibujar();

                if (darNombreJugador.esNombreIngresado())
                {
                    objJugador.setNombre(darNombreJugador.getNombreJugador());
                    juegoIniciado = true;
                    nivel1Completado = false;
                    pedirNombreJugador = false;
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
            mostrarRecords = false;
            menuPrincipal.resetBotones();
        }
        else if(continuaPartida){

        numNivel = archiJugador.nivelJugador();
        //objJugador.setPuntaje(archiJugador.leerPuntajeJugador());



                    switch (numNivel)
                    {
                    case 1:
                        nivel1Completado = false;
                        break;
                    case 2:
                        nivel1Completado=true;
                        nivel2Completado = false;
                        break;
                    case 3:
                        nivel1Completado=true;
                        nivel2Completado=true;
                        nivel3Completado = false;
                        break;
                    case 4:
                        nivel1Completado=true;
                        nivel2Completado=true;
                        nivel3Completado=true;
                        nivel4Completado = false;
                        break;
                    }
                    juegoIniciado=true;
                    continuaPartida=false;
        }


        else if (nivel1Completado)
        {
            NivelIntermedio nivelIntermedio(ventana);

            while (ventana.isOpen())
            {
                nivelIntermedio.manejarEntrada();
                nivelIntermedio.actualizar();
                nivelIntermedio.dibujar();

                if (nivelIntermedio.esBotonJugarNivel2Presionado())
                {
                    nivel1Completado = false;
                    break;
                }
            }

            Nivel2 nivel2(ventana, objJugador);

            while (ventana.isOpen())
            {
                nivel2.manejarEntrada();
                nivel2.actualizar();
                nivel2.dibujar();

                if (nivel2.isGameOverResolved())
                {
                    if (nivel2.isGameOver())
                    {
                        objJugador.getNivel();
                        objJugador.getPuntaje();
                        objJugador.getNombre();
                        archiJugador.grabarArchivo(objJugador);
                        juegoIniciado = false;
                        pedirNombreJugador = false;
                        menuPrincipal.resetBotones();
                        darNombreJugador.resetNombreIngresado();
                    }
                    else
                    {
                        nivel2Completado = true;
                    }
                    break;
                }
            }
        }
        else
        {
            Nivel1 nivel1(ventana, objJugador);

            while (ventana.isOpen())
            {
                nivel1.manejarEntrada();
                nivel1.actualizar();
                nivel1.dibujar();

                if (nivel1.isGameOverResolved())
                {
                    if (nivel1.isGameOver())
                    {
                        objJugador.getNivel();
                        objJugador.getPuntaje();
                        objJugador.getNombre();
                        archiJugador.grabarArchivo(objJugador);
                        juegoIniciado = false;
                        pedirNombreJugador = false;
                        menuPrincipal.resetBotones();
                        darNombreJugador.resetNombreIngresado();
                    }
                    else
                    {
                        nivel1Completado = true;

                    }
                    break;
                }
            }
        }

        if ((nivel2Completado) && (!nivel3Completado))
        {
            NivelIntermedio nivelIntermedio(ventana);

            while (ventana.isOpen())
            {
                nivelIntermedio.manejarEntrada();
                nivelIntermedio.actualizar();
                nivelIntermedio.dibujarN2();

                if (nivelIntermedio.esBotonJugarNivel3Presionado())
                {
                    nivel2Completado = false;
                    break;
                }
            }

            Nivel3 nivel3(ventana, objJugador);

            while (ventana.isOpen())
            {
                nivel3.manejarEntrada();
                nivel3.actualizar();
                nivel3.dibujar();

                if (nivel3.isGameOverResolved())
                {
                    if (nivel3.isGameOver())
                    {
                        objJugador.getNivel();
                        objJugador.getPuntaje();
                        objJugador.getNombre();
                        archiJugador.grabarArchivo(objJugador);
                        juegoIniciado = false;
                        pedirNombreJugador = false;
                        menuPrincipal.resetBotones();
                        darNombreJugador.resetNombreIngresado();
                    }
                    else
                    {
                        nivel3Completado = true;
                    }
                    break;
                }
            }
        }

        if ((nivel3Completado) && (!nivel4Completado))
        {
            NivelIntermedio nivelIntermedio(ventana);

            while (ventana.isOpen())
            {
                nivelIntermedio.manejarEntrada();
                nivelIntermedio.actualizar();
                nivelIntermedio.dibujarN3();

                if (nivelIntermedio.esBotonJugarNivel3Presionado())
                {
                    nivel3Completado = false;
                    break;
                }
            }

            Nivel4 nivel4(ventana, objJugador);

            while (ventana.isOpen())
            {
                nivel4.manejarEntrada();
                nivel4.actualizar();
                nivel4.dibujar();

                if (nivel4.isGameOverResolved())
                {
                    if (nivel4.isGameOver())
                    {
                        objJugador.getNivel();
                        objJugador.getPuntaje();
                        objJugador.getNombre();
                        archiJugador.grabarArchivo(objJugador);
                        juegoIniciado = false;
                        pedirNombreJugador = false;
                        menuPrincipal.resetBotones();
                        darNombreJugador.resetNombreIngresado();
                    }
                    else
                    {
                        nivel4Completado = true;
                    }
                    break;
                }
            }
        }
    }


    system("pause");
    return 0;
}


