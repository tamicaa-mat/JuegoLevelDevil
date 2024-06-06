#include"Nivel2.h"


Nivel2::Nivel2(sf::RenderWindow& vent) : ventana(vent),pp(200,100),m(600.0,100.0,10),m2(400.0,100.0,10),m3(200.0,100.0,10), piso(800, 150),pisoArriba(200,145),trmp(0,200),pb(40, 65),obstaculo1(200, 430, 25, 25), obstaculo2(400, 430, 25, 25),vidas(3), gameOver(false), gameOverResolved(false)
{
    if (!fuente.loadFromFile("fuentes/Roboto-Black.ttf"))
    {
        // Manejo de error
    }
    textoNivel.setFont(fuente);
    textoNivel.setString("Nivel 1 Vidas: " + std::to_string(vidas));
    textoNivel.setCharacterSize(24);
    textoNivel.setFillColor(sf::Color::White);
    textoNivel.setPosition(10, 10);

    textoGameOver.setFont(fuente);
    textoGameOver.setString("GAME OVER\nPresione Enter para ir al menu principal");
    textoGameOver.setCharacterSize(50);
    textoGameOver.setFillColor(sf::Color::Red);
    textoGameOver.setPosition(100, 200);
}

void Nivel2::manejarEntrada()
{
    sf::Event evento;
    while (ventana.pollEvent(evento))
    {
        if (evento.type == sf::Event::Closed)
            ventana.close();
        if (gameOver && evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Enter)
        {
            gameOverResolved = true; // Indicar que se ha resuelto el estado de "Game Over"
        }
    }
}

void Nivel2::actualizar()
{
    pisoArriba.setColor(sf::Color::Green);
    pisoArriba.setPosition(200,145);
    pisoArriba.setSize(200,50);
    if (gameOver) return;

    pp.cmd();
    pp.update();

    // Comprobar colisiones
    if (pp.colisionaCon(obstaculo1) || pp.colisionaCon(obstaculo2))
    {
        vidas--;
        if (vidas > 0)
        {
            pp = Personaje(0,400); // Reiniciar la posición del personaje
        }
        else
        {
            // Activar estado de "Game Over"
            gameOver = true;
        }
    }

    if(pp.colisionaCon(m) || pp.colisionaCon(m2) || pp.colisionaCon(m3))
    {
        if (pp.colisionaCon(m))
        {
            m.desaparecer();
        }
        if (pp.colisionaCon(m2))
        {
            m2.desaparecer();
        }
        if (pp.colisionaCon(m3))
        {
            m3.desaparecer();
        }
    }

    if(pp.colisionaCon(trmp))
    {

        trmp.aparecer();
        vidas--;
        pp=Personaje(0,400);


    }


    textoNivel.setString("Nivel 2 Vidas: " + std::to_string(vidas));
}

void Nivel2::dibujar()
{
    ventana.clear();
    if (gameOver)
    {
        ventana.draw(textoGameOver);
    }
    else
    {
        ventana.draw(textoNivel);
        ventana.draw(pisoArriba.getdraw());
        ventana.draw(pp.getDraw());
        ventana.draw(m.getDraw());
        ventana.draw(m2.getDraw());
        ventana.draw(m3.getDraw());
        ventana.draw(piso.getdraw());
        ventana.draw(pb.getDraw());
        ventana.draw(trmp.getDraw());
        ventana.draw(obstaculo1.getDraw());
        ventana.draw(obstaculo2.getDraw());
    }
    ventana.display();
}

bool Nivel2::isGameOverResolved() const
{
    return gameOverResolved;
}
