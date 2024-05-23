<<<<<<< HEAD
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
        }
    }

    return 0;
}
=======
#include <SFML/Graphics.hpp>
#include "gamePlay.h"
#include "Personaje.h"
#include "PuertaBlanca.h"
#include "Monedas.h"
#include "piso.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
    window.setFramerateLimit(60);// se ve mas lento el movimiento

    Personaje pp;
    Moneda m;
    Piso piso(800,150);
    PuertaBlanca pb(40,65);
    //GAMELOOP
    while (window.isOpen())
    {
        //CMD() LO PRIMERO QUE HACE
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //PROCESAMIENTO shape

        pp.cmd();//lee teclado
        pp.update();



        window.clear();//BORRA LA PANTALLA
        // Dibujar aquí
        window.draw(pb.getDraw());
        window.draw(piso.getdraw());
        window.draw(m.getDraw());
        window.draw(pp.getDraw());
        window.display();//PARA MOSTRAR LA PANTALLA
    }
    ////////////////////wwwwwwwwwwwwwwwwwwwwwwwwwwwtaaaaaaaaaaammmmmmm
    return 0;
}
>>>>>>> 6f61caf099bd79490bf4755cf2e83f910632a5e9
