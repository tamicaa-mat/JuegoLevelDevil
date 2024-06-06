#include "NivelIntermedio.h"

NivelIntermedio::NivelIntermedio(sf::RenderWindow& vent) : ventana(vent) {
    fuente.loadFromFile("fuentes/Roboto-Black.ttf"); // Aseg�rate de tener una fuente en el directorio del proyecto

    textoIntermedio.setFont(fuente);
    textoIntermedio.setString("Nivel 1 Completado");
    textoIntermedio.setCharacterSize(50);
    textoIntermedio.setFillColor(sf::Color::White);
    textoIntermedio.setPosition(150, 100);

    botonJugarNivel2.setFont(fuente);
    botonJugarNivel2.setString("Jugar Nivel 2");
    botonJugarNivel2.setCharacterSize(30);
    botonJugarNivel2.setFillColor(sf::Color::White);
    botonJugarNivel2.setPosition(300, 300);
}

void NivelIntermedio::manejarEntrada() {
    sf::Event evento;
    while (ventana.pollEvent(evento)) {
        if (evento.type == sf::Event::Closed)
            ventana.close();
    }
}

void NivelIntermedio::actualizar() {
    // Cualquier actualizaci�n si es necesaria
}

void NivelIntermedio::dibujar() {
    ventana.clear();
    ventana.draw(textoIntermedio);
    ventana.draw(botonJugarNivel2);
    ventana.display();
}

bool NivelIntermedio::esBotonJugarNivel2Presionado() {
    return sf::Mouse::isButtonPressed(sf::Mouse::Left) && botonJugarNivel2.getGlobalBounds().contains(ventana.mapPixelToCoords(sf::Mouse::getPosition(ventana)));
}