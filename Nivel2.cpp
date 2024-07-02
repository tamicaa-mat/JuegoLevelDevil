#include"Nivel2.h"
#include <iostream>//cabecera para usar std::cout
Nivel2::Nivel2(sf::RenderWindow& vent, Jugador& jug) : ventana(vent), jugador(jug),
    pp(200, 100),
    m(600.0, 400.0, 10),
    m2(400.0, 100.0, 10),
    m3(0.0, 400.0, 10),
    piso(800, 150),
    pisoArriba(200, 145),
    trmp(170, 450),
    pb(700.0, 400.0),
    obstaculo1(550, 430, 25, 25),
    obstaculo2(400, 430, 25, 25),
    vidas(3),
    gameOver(false),
    gameOverResolved(false),
    contadorMonedas(jugador.getPuntaje())
{


    if (!fuente.loadFromFile("fuentes/Roboto-Black.ttf"))
    {
        std::cerr << "Error al cargar la fuente" << std::endl;

        exit(EXIT_FAILURE);
    }

    if (!fondoTexture.loadFromFile("fondo2.jpg"))
    {
        std::cerr << "Error al cargar la imagen de fondo" << std::endl;
    }
      if (!buffer.loadFromFile("moneda.ogg")) {
    std::cerr << "Error al cargar el archivo de sonido" << std::endl;
    } else {
    sound.setBuffer(buffer);
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

void Nivel2::manejarEntrada()
{
    sf::Event evento;
    while (ventana.pollEvent(evento))
    {
        if (evento.type == sf::Event::Closed)
            ventana.close();
        if (gameOver && evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Enter)
        {
            gameOverResolved = true;
        }
    }
}

void Nivel2::actualizar()
{
    if (gameOver) return;

    pisoArriba.setColor(sf::Color::Green);
    pisoArriba.setPosition(200,145);
    pisoArriba.setSize(200,50);
    pb.setVisible(true);
    float deltaTime = 1.0f / 60.0f; // Asumiendo 60 FPS
    ArchivoJugador archiJgdr;
    pp.cmd();
    pp.update();

    ////////////////////agregoahora

    trmp.actualizar(deltaTime);

    if((pp.getPosition().x<180&&pp.getPosition().y<=100)||(pp.getPosition().x>400&&pp.getPosition().y<=100))
    {
        pp.activarCaida();

    }


       if (pp.colisionaConTrampaN2(trmp))
    {
        std::cout << "Posición del personaje: (" << pp.getPosition().x << ", " << pp.getPosition().y << ")" << std::endl;
        std::cout << "Posición de la trampa: (" << trmp.getPosition().x << ", " << trmp.getPosition().y << ")" << std::endl;
        trmp.aparecer();
        pp.activarCaida();


    }




//TODO:ARREGLAR COLISION OBSTACULOS N2

    if (pp.colisionaCon(obstaculo1))
    {
        vidas--;
        if (vidas>0)
        {
            isGameOverModifica();
            pp.reset(200,100);
            trmp.reiniciar();
        }
        else
        {

            gameOver = true;
            jugador.setPuntaje(contadorMonedas);
            jugador.setNivel(2);
        }

    }

    if (pp.colisionaCon(obstaculo2))
    {
        vidas--;
        if (vidas>0)
        {
            isGameOverModifica();
            pp.reset(200,100);
            trmp.reiniciar();
        }
        else
        {

            gameOver = true;
            jugador.setNivel(2);
            jugador.setPuntaje(contadorMonedas);

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
            contadorMonedas++;
    }

 // std::cout << "Posición del personaje: (" << pp.getPosition().x << ", " << pp.getPosition().y << ")" << std::endl;
    if (pp.colisionaCon(trmp))
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
        if(vidas==3){
                contadorMonedas=10;
           }
            jugador.setNivel(2);
            jugador.setPuntaje(contadorMonedas);


    }

     if (pp.getPosition().y > 600)
        {
            vidas--;

            if (vidas>0)
            {
                isGameOverModifica();
                pp.reset(200, 100);
                trmp.reiniciar();
            }
            else
            {

                gameOver = true;
                jugador.setPuntaje(contadorMonedas);
                jugador.setNivel(1);
            }
        }


    textoVidas.setString("Nivel 2 Vidas: " + std::to_string(vidas));
    textoPuntos.setString("Puntos: " + std::to_string(contadorMonedas));


}

void Nivel2::dibujar()
{
    ventana.clear();

    ventana.draw(fondoSprite);

    if (gameOver)
    {
        ventana.draw(textoGameOver);
    }
    else
    {
        ventana.draw(textoVidas);
        ventana.draw(textoPuntos);
        ventana.draw(pisoArriba.getdraw());
        ventana.draw(m.getDraw());
        ventana.draw(m2.getDraw());
        ventana.draw(m3.getDraw());
        ventana.draw(piso.getdraw());
        ventana.draw(pb.getDraw());
        ventana.draw(trmp.getDraw());
        ventana.draw(pp.getDraw());
        ventana.draw(obstaculo1.getDraw());
        ventana.draw(obstaculo2.getDraw());

    }
    ventana.display();
}

bool Nivel2::isGameOverResolved() const
{
    return gameOverResolved;
}

bool Nivel2::isGameOver() const
{
    return gameOver;
}

void Nivel2::isGameOverModifica()
{
    m.aparecer();
    m2.aparecer();
    m3.aparecer();
    contadorMonedas=0;

}

int Nivel2::getContadorMonedas() const
{
    return contadorMonedas;
}
