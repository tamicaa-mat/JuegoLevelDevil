#include <SFML/Graphics.hpp>
#include "gamePlay.h"
#include "Personaje.h"
#include "PuertaBlanca.h"
#include "Monedas.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
    window.setFramerateLimit(60);// se ve mas lento el movimiento

    Personaje p;
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
        p.cmd();//lee teclado
        p.update();



        window.clear();//BORRA LA PANTALLA
        // Dibujar aquí
        window.draw(p.getDraw());
        window.display();//PARA MOSTRAR LA PANTALLA
    }
    ////////////////////wwwwwwwwwwwwwwwwwwwwwwwwwww
    return 0;
}
