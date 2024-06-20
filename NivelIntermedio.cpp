#include "NivelIntermedio.h"

NivelIntermedio::NivelIntermedio(sf::RenderWindow& vent) : ventana(vent) {
    fuente.loadFromFile("fuentes/Roboto-Black.ttf");

    textoIntermedio1.setFont(fuente);
    textoIntermedio1.setString("Nivel 1 Completado");
    textoIntermedio1.setCharacterSize(50);
    textoIntermedio1.setFillColor(sf::Color::White);
    textoIntermedio1.setPosition(150, 100);

    botonJugarNivel2.setFont(fuente);
    botonJugarNivel2.setString("Jugar Nivel 2");
    botonJugarNivel2.setCharacterSize(30);
    botonJugarNivel2.setFillColor(sf::Color::White);
    botonJugarNivel2.setPosition(300, 300);


    textoIntermedio2.setFont(fuente);
    textoIntermedio2.setString("Nivel 2 Completado");
    textoIntermedio2.setCharacterSize(50);
    textoIntermedio2.setFillColor(sf::Color::White);
    textoIntermedio2.setPosition(150, 100);

    botonJugarNivel3.setFont(fuente);
    botonJugarNivel3.setString("Jugar Nivel 3");
    botonJugarNivel3.setCharacterSize(30);
    botonJugarNivel3.setFillColor(sf::Color::White);
    botonJugarNivel3.setPosition(300, 300);



}

void NivelIntermedio::manejarEntrada() {
    sf::Event evento;
    while (ventana.pollEvent(evento)) {
        if (evento.type == sf::Event::Closed)
            ventana.close();
    }
}

void NivelIntermedio::actualizar() {

}

void NivelIntermedio::dibujar() {
    ventana.clear();
    ventana.draw(textoIntermedio1);
    ventana.draw(botonJugarNivel2);
    ventana.display();
}
/////////////////agrego

void NivelIntermedio::dibujarN2() {
    ventana.clear();
    ventana.draw(textoIntermedio2);
    ventana.draw(botonJugarNivel3);
    ventana.display();
}

bool NivelIntermedio::esBotonJugarNivel2Presionado() {
    return sf::Mouse::isButtonPressed(sf::Mouse::Left) && botonJugarNivel2.getGlobalBounds().contains(ventana.mapPixelToCoords(sf::Mouse::getPosition(ventana)));
}

bool NivelIntermedio::esBotonJugarNivel3Presionado() {
    return sf::Mouse::isButtonPressed(sf::Mouse::Left) && botonJugarNivel3.getGlobalBounds().contains(ventana.mapPixelToCoords(sf::Mouse::getPosition(ventana)));
}
