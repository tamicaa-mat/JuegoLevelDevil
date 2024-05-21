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
        window.draw(piso.getdraw());
        window.draw(m.getDraw());
        window.draw(pp.getDraw());
        window.display();//PARA MOSTRAR LA PANTALLA
    }
    ////////////////////wwwwwwwwwwwwwwwwwwwwwwwwwwwtaaaaaaaaaaammmmmmm
    return 0;
}
