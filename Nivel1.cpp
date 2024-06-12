#include "Nivel1.h"
#include <iostream> //cabecera para usar std::cout

Nivel1::Nivel1(sf::RenderWindow& vent, Jugador& jug) : ventana(vent), jugador(jug),
    pp(0,400),
    m(250.0,350.0,10),
    m2(500,350.0,10),
    m3(550.0,350.0,10),
    piso(800, 150),
    trmp(600,450),
    pb(700, 350),
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
    textoVidas.setFont(fuente);
    textoVidas.setCharacterSize(24);
    textoVidas.setFillColor(sf::Color::White);
    textoVidas.setPosition(10, 10);

    textoPuntos.setFont(fuente);
    textoPuntos.setCharacterSize(24);
    textoPuntos.setFillColor(sf::Color::White);
    textoPuntos.setPosition(10, 40);

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

    float deltaTime = 1.0f / 60.0f; // Asumiendo 60 FPS

    pp.cmd();
    pp.update();

    // Actualizar la trampa
    trmp.actualizar(deltaTime);

    // Comprobar colisiones con obstáculos y trampa
    if (pp.colisionaCon(obstaculo1) || pp.colisionaCon(obstaculo2))
    {
        vidas--;
        if (vidas > 0)
        {
            pp.reset(0,400);
            trmp.reiniciar(); // Reiniciar la trampa cuando el jugador muere
        }
        else
        {
            gameOver = true;
            jugador.setPuntaje(contadorMonedas);
            jugador.grabarArchivo();
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

    // Comprobar si el jugador pasa por una posición determinada para activar la trampa
    if (pp.colisionaCon(trmp))    // Condición para hacer aparecer la trampa
    {
        trmp.aparecer();
        pp.activarCaida();
        vidas--;
    }
    if(pp.getPosition().y>600)
    {
        pp.reset(0,400);
        trmp.reiniciar();
        if(vidas==0)
        {
            gameOver=true;
            jugador.setPuntaje(contadorMonedas);
            jugador.grabarArchivo();
        }
    }

    if (pp.colisionPuertaBlanca(pb))
    {
        gameOverResolved = true; // Indicar que se ha completado el nivel
    }
    if (pp.getPosition().y > 600)
    {
        vidas--;
        pp.reset(0, 400); // Reiniciar la posición del jugador
        trmp.reiniciar(); // Reiniciar la trampa
    }
    textoVidas.setString("Nivel 1 Vidas: " + std::to_string(vidas));
    textoPuntos.setString("Nivel 1 Puntos: " + std::to_string(contadorMonedas));
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
        ventana.draw(textoVidas);
        ventana.draw(textoPuntos);
        ventana.draw(pb.getDraw());
        ventana.draw(m.getDraw());
        ventana.draw(m2.getDraw());
        ventana.draw(m3.getDraw());
        ventana.draw(piso.getdraw());
        ventana.draw(trmp.getDraw());
        ventana.draw(pp.getDraw()); // Dibuja el jugador por encima de la trampa
        ventana.draw(obstaculo1.getDraw());
        ventana.draw(obstaculo2.getDraw());
    }
    ventana.display();
}

bool Nivel1::isGameOverResolved() const
{
    return gameOverResolved;
}

bool Nivel1::isGameOver() const
{
    return gameOver;
}

int Nivel1::getContadorMonedas() const {
    return contadorMonedas;
}
