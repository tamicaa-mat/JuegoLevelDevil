#include <SFML/Audio.hpp>
#include <iostream> //cabecera para usar std::cout
#include "Nivel1.h"
Nivel1::Nivel1(sf::RenderWindow& vent, const Jugador& jugador) : ventana(vent), jugador(jugador),
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
    contadorMonedasN1(0)
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

    if (!buffer.loadFromFile("moneda.ogg")) {
    std::cerr << "Error al cargar el archivo de sonido" << std::endl;
    } else {
    sound.setBuffer(buffer);
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
    ArchivoJugador archiJgdr;
    float deltaTime = 1.0f / 60.0f; // Asumiendo 60 FPS
    pb.setVisible(true);
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
            jugador.setNivel(1);
            jugador.setPuntaje(getContadorMonedas());

        }
    }

    if(pp.colisionaCon(m) || pp.colisionaCon(m2) || pp.colisionaCon(m3))
    {
        if (pp.colisionaCon(m))
        {
            m.desaparecer();
            sound.play();

        }
        if (pp.colisionaCon(m2))
        {
            m2.desaparecer();
            sound.play();

        }
        if (pp.colisionaCon(m3))
        {
            m3.desaparecer();
            sound.play();

        }

         contadorMonedasN1++;
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

        gameOverResolved = true;
        if(vidas==3){
            jugador.setNivel(1);
            jugador.setPuntaje(contadorMonedasN1);
        }

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
            jugador.setPuntaje(contadorMonedasN1);
            jugador.setNivel(1);
        }
    }
    textoVidas.setString("Nivel 1 Vidas: " + std::to_string(vidas));
    textoPuntos.setString("Puntos: " + std::to_string(contadorMonedasN1));
}

void Nivel1::dibujar()
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

bool Nivel1::isGameOverResolved() const
{
    return gameOverResolved;//si resolvio el nivel, si se paso
}

bool Nivel1::isGameOver() const
{
    return gameOver;

}

void Nivel1::isGameOverModifica()
{
    m.aparecer();
    m2.aparecer();
    m3.aparecer();
    contadorMonedasN1=0;
}


int Nivel1::getContadorMonedas() const
{
    return contadorMonedasN1;
}
