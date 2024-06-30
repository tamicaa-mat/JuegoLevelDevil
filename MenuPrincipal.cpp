#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal(sf::RenderWindow& vent) : ventana(vent), botonJugarPresionado(false), botonRecordsPresionado(false),botonContinuarPartidaPresionado(false) {

     if (!fondoTexture.loadFromFile("fondo2.jpg")) {
            std::cerr << "Error al cargar la imagen de fondo" << std::endl;
        }
        fondoSprite.setTexture(fondoTexture);


    fuente.loadFromFile("fuentes/Roboto-Black.ttf");
    textoBienvenida.setFont(fuente);
    textoBienvenida.setString("Level 63");
    textoBienvenida.setCharacterSize(50);
    textoBienvenida.setFillColor(sf::Color::White);
    textoBienvenida.setPosition(300, 100);

    botonJugar.setFont(fuente);
    botonJugar.setString("* Jugar");
    botonJugar.setCharacterSize(30);
    botonJugar.setFillColor(sf::Color::White);
    botonJugar.setPosition(350, 300);

    botonRecords.setFont(fuente);
    botonRecords.setString("* Ver Partidas");
    botonRecords.setCharacterSize(30);
    botonRecords.setFillColor(sf::Color::White);
    botonRecords.setPosition(350, 350);

    botonContinuarPartida.setFont(fuente);
    botonContinuarPartida.setString("* Continuar Partida");
    botonContinuarPartida.setCharacterSize(30);
    botonContinuarPartida.setFillColor(sf::Color::White);
    botonContinuarPartida.setPosition(350, 400);


}

void MenuPrincipal::manejarEntrada() {
    sf::Event evento;
    while (ventana.pollEvent(evento)) {
        if (evento.type == sf::Event::Closed)
            ventana.close();
        if (evento.type == sf::Event::MouseButtonPressed) {
            if (evento.mouseButton.button == sf::Mouse::Left) {
                if (botonJugar.getGlobalBounds().contains(ventana.mapPixelToCoords(sf::Mouse::getPosition(ventana)))) {
                    botonJugarPresionado = true;

                }
                if (botonRecords.getGlobalBounds().contains(ventana.mapPixelToCoords(sf::Mouse::getPosition(ventana)))) {
                    botonRecordsPresionado = true;
                }
                 if (botonContinuarPartida.getGlobalBounds().contains(ventana.mapPixelToCoords(sf::Mouse::getPosition(ventana)))) {
                    botonContinuarPartidaPresionado = true;
                }

            }
        }
    }
}

void MenuPrincipal::actualizar() {
    // Cualquier actualización si es necesaria
}

void MenuPrincipal::dibujar() {
    ventana.clear();

    ventana.draw(fondoSprite);
    ventana.draw(textoBienvenida);
    ventana.draw(botonJugar);
    ventana.draw(botonRecords);
    ventana.draw(botonContinuarPartida);
    ventana.display();
}

bool MenuPrincipal::esBotonJugarPresionado() const {
    return botonJugarPresionado;
}

bool MenuPrincipal::esBotonRecordsPresionado() const {
    return botonRecordsPresionado;

}


bool MenuPrincipal::esBotonContinuarPartidaPresionado() const {

    return botonContinuarPartidaPresionado;

}

int MenuPrincipal::nivelJugador(){
    int numPartida=0,numNivel=0;
    Jugador objJug;
    ArchivoJugador archiJug;
    std::cout<<"Ingrese su numero de partida: "<<std::endl;
    std::cin>>numPartida;
    objJug=archiJug.leerRegistro(numPartida);
    numNivel=objJug.getNivel();
    return numNivel;
}

void MenuPrincipal::resetBotones() {
    botonJugarPresionado = false;
    botonRecordsPresionado = false;
    botonContinuarPartidaPresionado=false;
}
