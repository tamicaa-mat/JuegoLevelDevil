#include <iostream>

#include"Nivel3.h"

Nivel3::Nivel3(sf::RenderWindow& vent, Jugador& jug) : ventana(vent), jugador(jug),
    pp(0, 400),
    m(50.0, 400.0, 10),
    m2(100.0, 400.0, 10),
    m3(150.0, 400.0, 10),
    m4(200.0, 400.0, 10),
    m5(250.0, 400.0, 10),
    m6(300.0, 400.0, 10),
    m7(350.0, 400.0, 10),
    m8(400.0, 400.0, 10),
    m9(450.0, 400.0, 10),
    m10(500.0, 400.0, 10),
    piso(800, 150),
    trmp(400, 400),
    pb(40, 65),
    obstaculo1(550.0, 430.0, 25.0, 25.0),
    obstaculo2(400.0, 430.0, 25.0, 25.0),
    vidas(3),
    gameOver(false),
    gameOverResolved(false),
    contadorMonedas(0)
{


    if (!fuente.loadFromFile("fuentes/Roboto-Black.ttf"))
    {
        std::cerr << "Error al cargar la fuente" << std::endl;

        exit(EXIT_FAILURE);
    }

        if (!fondoTexture.loadFromFile("fondo2.jpg")) {
            std::cerr << "Error al cargar la imagen de fondo" << std::endl;
        }


    fondoSprite.setTexture(fondoTexture);
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
void Nivel3::manejarEntrada()
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

void Nivel3::actualizar()
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

    if(pp.colisionaCon(m) || pp.colisionaCon(m2) || pp.colisionaCon(m3)||pp.colisionaCon(m4)||pp.colisionaCon(m5)||pp.colisionaCon(m6)||pp.colisionaCon(m7)||pp.colisionaCon(m9)||pp.colisionaCon(m10))
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
         if (pp.colisionaCon(m4))
        {
            m2.desaparecer();
            contadorMonedas++;
        }
         if (pp.colisionaCon(m5))
        {
            m2.desaparecer();
            contadorMonedas++;
        }
         if (pp.colisionaCon(m6))
        {
            m2.desaparecer();
            contadorMonedas++;
        }

         if (pp.colisionaCon(m7))
        {
            m2.desaparecer();
            contadorMonedas++;
        }
         if (pp.colisionaCon(m9))
        {
            m2.desaparecer();
            contadorMonedas++;
        }
         if (pp.colisionaCon(m10))
        {
            m2.desaparecer();
            contadorMonedas++;
        }

    }

    ///se activa la trampa si colisiona con moneda8
    if(pp.colisionaCon(m8)){
        trmp.aparecer();
        pp.activarCaida();
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



    // Comprobar si el jugador pasa por una posición determinada para activar la trampa
    if (pp.colisionaCon(trmp))    // Condición para hacer aparecer la trampa
    {
    std::cout << "Posición del personaje: (" << pp.getPosition().x << ", " << pp.getPosition().y << ")" << std::endl;
    std::cout << "Posición de la trampa: (" << trmp.getPosition().x << ", " << trmp.getPosition().y << ")" << std::endl;
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
    std::cout << "Posición del personaje: (" << pp.getPosition().x << ", " << pp.getPosition().y << ")" << std::endl;
    std::cout << "Posición de la puerta: (" << pb.getPosition().x << ", " << pb.getPosition().y << ")" << std::endl;

        gameOverResolved = true; // Indicar que se ha completado el nivel
    }
    if (pp.getPosition().y > 600)
    {
        vidas--;
        pp.reset(0, 400); // Reiniciar la posición del jugador
        trmp.reiniciar(); // Reiniciar la trampa
    }
    textoVidas.setString("Nivel 1 Vidas: " + std::to_string(vidas));
    textoPuntos.setString("Puntos: " + std::to_string(contadorMonedas));
}


void Nivel3::dibujar()
{
    ventana.clear();


    ventana.draw(fondoSprite);  // Dibujar el fondo primero




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

bool Nivel3::isGameOverResolved() const
{
    return gameOverResolved;
}

bool Nivel3::isGameOver() const
{
    return gameOver;
}

int Nivel3::getContadorMonedas() const {
    return contadorMonedas;
}






















