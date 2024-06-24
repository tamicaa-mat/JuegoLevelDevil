#include "Nivel4.h"



Nivel4::Nivel4(sf::RenderWindow& vent, Jugador& jug) : ventana(vent), jugador(jug),
    pp(0,400),
    m(250.0,350.0,10),
    m2(500,350.0,10),
    m3(550.0,350.0,10),
    piso(800, 150),
    trmp(550,450),
    pb(700.0, 400.0),
    obstaculo1(200.0, 430.0, 25.0, 25.0),
    obstaculo2(400.0, 430.0, 25.0, 25.0),
    vidas(3), gameOver(false),
    gameOverResolved(false),
    contadorMonedas(0)
{
    if (!fuente.loadFromFile("fuentes/Roboto-Black.ttf"))
    {
        // Manejo de error
    }


    if (!fondoTexture.loadFromFile("fondo2.jpg"))
    {
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


void Nivel4::manejarEntrada()
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


void Nivel4::actualizar()
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
            isGameOverModifica();
            pp.reset(0,400);
            trmp.reiniciar();
            // Reiniciar la trampa cuando el jugador muere
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

    /// colision con trampa horizontal
    if (pp.colisionaCon(trmp))    // Condición para hacer aparecer la trampa
    {
        std::cout << "Posición del personaje: (" << pp.getPosition().x << ", " << pp.getPosition().y << ")" << std::endl;
        std::cout << "Posición de la trampa: (" << trmp.getPosition().x << ", " << trmp.getPosition().y << ")" << std::endl;
        trmp.aparecer();
        pp.activarCaida();

    }

    if (pp.colisionPuertaBlanca(pb))
    {
        std::cout << "Posición del personaje: (" << pp.getPosition().x << ", " << pp.getPosition().y << ")" << std::endl;
        std::cout << "Posición de la puerta: (" << pb.getPosition().x << ", " << pb.getPosition().y << ")" << std::endl;

        gameOverResolved = true; // Indicar que se ha completado el nivel
    }

    ///????? este bloque IF creo que esta de mas
    if(pp.getPosition().y>600)
    {
        vidas--;
        pp.reset(0,400);
        trmp.reiniciar();
        isGameOverModifica();
        if(vidas==0)
        {

            gameOver=true;
            jugador.setPuntaje(contadorMonedas);
            jugador.grabarArchivo();
        }
    }
    textoVidas.setString("Nivel 4 Vidas: " + std::to_string(vidas));
    textoPuntos.setString("Puntos: " + std::to_string(contadorMonedas));
}

void Nivel4::dibujar()
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

bool Nivel4::isGameOverResolved() const
{
    return gameOverResolved;//si resolvio el nivel, si se paso
}

bool Nivel4::isGameOver() const
{
    return gameOver;

}

void Nivel4::isGameOverModifica()
{
    m.aparecer();
    m2.aparecer();
    m3.aparecer();
    contadorMonedas=0;
}


int Nivel4::getContadorMonedas() const
{
    return contadorMonedas;
}









