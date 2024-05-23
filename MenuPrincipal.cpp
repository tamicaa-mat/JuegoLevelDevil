#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal(sf::RenderWindow& vent) : ventana(vent) {
    fuente.loadFromFile("fuentes/Roboto-Black.ttf"); // Asegúrate de tener una fuente en el directorio del proyecto
    textoBienvenida.setFont(fuente);
    textoBienvenida.setString("Bienvenidos");
    textoBienvenida.setCharacterSize(50);
    textoBienvenida.setFillColor(sf::Color::White);
    textoBienvenida.setPosition(200, 100);

    botonJugar.setFont(fuente);
    botonJugar.setString("Jugar");
    botonJugar.setCharacterSize(30);
    botonJugar.setFillColor(sf::Color::White);
    botonJugar.setPosition(350, 300);
}

void MenuPrincipal::manejarEntrada() {
    sf::Event evento;
    while (ventana.pollEvent(evento)) {
        if (evento.type == sf::Event::Closed)
            ventana.close();
        if (evento.type == sf::Event::MouseButtonPressed) {
            if (evento.mouseButton.button == sf::Mouse::Left) {
                if (botonJugar.getGlobalBounds().contains(ventana.mapPixelToCoords(sf::Mouse::getPosition(ventana)))) {
                    ventana.close();
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
    ventana.draw(textoBienvenida);
    ventana.draw(botonJugar);
    ventana.display();
}

bool MenuPrincipal::esBotonJugarPresionado() {
    return sf::Mouse::isButtonPressed(sf::Mouse::Left) && botonJugar.getGlobalBounds().contains(ventana.mapPixelToCoords(sf::Mouse::getPosition(ventana)));
}
