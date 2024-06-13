#include"Nivel2.h"
#include <iostream> //cabecera para usar std::cout
Nivel2::Nivel2(sf::RenderWindow& vent, Jugador& jug) : ventana(vent), jugador(jug),
    pp(200, 100),
    m(600.0, 400.0, 10),
    m2(400.0, 100.0, 10),
    m3(0.0, 400.0, 10),
    piso(800, 150),
    pisoArriba(200, 145),
    trmp(170, 450),
    pb(40, 65),
    obstaculo1(550, 430, 25, 25),
    obstaculo2(400, 430, 25, 25),
    vidas(3),
    gameOver(false),
    gameOverResolved(false),
    contadorMonedas(0)
{


    if (!fuente.loadFromFile("fuentes/Roboto-Black.ttf"))
    {
        std::cerr << "Error al cargar la fuente" << std::endl;
        // Manejar el error aquí, por ejemplo, cerrando el programa
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
    float deltaTime = 1.0f / 60.0f; // Asumiendo 60 FPS
    pp.cmd();
    pp.update();

    ////////////////////agregoahora

     trmp.actualizar(deltaTime);

    if((pp.getPosition().x<180&&pp.getPosition().y<=100)||(pp.getPosition().x>400&&pp.getPosition().y<=100)){
        pp.activarCaida();

        }
         std::cout << "Posición del personaje: (" << pp.getPosition().x << ", " << pp.getPosition().y << ")" << std::endl;



//TODO:ARREGLAR COLISION OBSTACULOS N2

    if (pp.colisionaCon(obstaculo1) || pp.colisionaCon(obstaculo2))
    {
        vidas--;
        if (vidas > 0)
        {
            pp = Personaje(200,100); // Reiniciar la posición del personaje
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

        //std::cout << "Posición del personaje ANTES: (" << pp.getPosition().x << ", " << pp.getPosition().y << ")" << std::endl;

    if (pp.colisionaConTrampaN2(trmp))    // Condición para hacer aparecer la trampa
    {
    std::cout << "Posición del personaje: (" << pp.getPosition().x << ", " << pp.getPosition().y << ")" << std::endl;
    std::cout << "Posición de la trampa: (" << trmp.getPosition().x << ", " << trmp.getPosition().y << ")" << std::endl;
        trmp.aparecer();
        //pp.setEstado(QUIETO);
        pp.activarCaida();
        vidas--;
    }
    if(pp.getPosition().y>600)
    {
        pp.reset(200,100);
        trmp.reiniciar();
        if(vidas==0)
        {
            gameOver=true;
            jugador.setPuntaje(contadorMonedas);
            jugador.grabarArchivo();
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
