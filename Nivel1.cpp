#include "Nivel1.h"

Nivel1::Nivel1(sf::RenderWindow& vent) : ventana(vent),
    pp(0,400),
    m(250.0,350.0,10),
    m2(500,350.0,10),
    m3(550.0,350.0,10),
    piso(800, 150),
    trmp(500,450),
    pb(40, 65),
    obstaculo1(200, 430, 25, 25),
    obstaculo2(400, 430, 25, 25),
    vidas(3), gameOver(false),
    gameOverResolved(false),
    contadorMonedas(0)
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

void Nivel1::manejarEntrada()
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

void Nivel1::actualizar()
{
    if (gameOver) return;

    pp.cmd();
    pp.update();

    // Comprobar colisiones
    if (pp.colisionaCon(obstaculo1) || pp.colisionaCon(obstaculo2))
    {
        vidas--;
        if (vidas > 0)
        {
            pp = Personaje(0,400);

            // Reiniciar la posición del personaje///////////////////necesito que la trampa vuelva a ponerse oculta
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
            contadorMonedas++;
        }
        if (pp.colisionaCon(m2))
        {
            m2.desaparecer();
            contadorMonedas++;
        }
        if (pp.colisionaCon(m3))
        {
            m3.desaparecer();
            contadorMonedas++;
        }
    }

    if(pp.colisionaCon(trmp)&&vidas>0)
    {
        trmp.aparecer();
        vidas--;
        pp = Personaje(0,400);
            // Reiniciar la posición del personaje
    }
    else if(pp.colisionaCon(trmp)&&vidas==0){
        gameOver=true;
    }


//
    if (pp.colisionPuertaBlanca(pb))
    {
        if(vidas==3)
            gameOverResolved = true;////////////////////////////como hago para que pase al nivel dos
        contadorMonedas==10;
    }

    textoNivel.setString("Nivel 1 Vidas: " + std::to_string(vidas));

    textoNivel.setString("Nivel 1 Puntos: " + std::to_string(contadorMonedas));
}

void Nivel1::dibujar()
{
    ventana.clear();
    if (gameOver)
    {
        ventana.draw(textoGameOver);
    }
    else
    {
        ventana.draw(textoNivel);
        ventana.draw(pb.getDraw());
        ventana.draw(pp.getDraw());
        ventana.draw(m.getDraw());
        ventana.draw(m2.getDraw());
        ventana.draw(m3.getDraw());
        ventana.draw(piso.getdraw());
        ventana.draw(trmp.getDraw());
        ventana.draw(obstaculo1.getDraw());
        ventana.draw(obstaculo2.getDraw());
    }
    ventana.display();
}

bool Nivel1::isGameOverResolved() const
{
    return gameOverResolved;
}
