#include "DarNombreJugador.h"

DarNombreJugador::DarNombreJugador(sf::RenderWindow& vent) : ventana(vent), nombreIngresado(false) {
    fuente.loadFromFile("fuentes/Roboto-Black.ttf");
    textoInstruccion.setFont(fuente);
    textoInstruccion.setString("Ingrese su nombre y presione Enter:");
    textoInstruccion.setCharacterSize(30);
    textoInstruccion.setFillColor(sf::Color::White);
    textoInstruccion.setPosition(100, 100);

    textoNombre.setFont(fuente);
    textoNombre.setString("");
    textoNombre.setCharacterSize(30);
    textoNombre.setFillColor(sf::Color::White);
    textoNombre.setPosition(100, 200);
}

void DarNombreJugador::manejarEntrada() {
    sf::Event evento;
    while (ventana.pollEvent(evento)) {
        if (evento.type == sf::Event::Closed)
            ventana.close();
        if (evento.type == sf::Event::TextEntered) {
            if (evento.text.unicode == '\b') { // Backspace
                if (!nombreJugador.empty()) {
                    nombreJugador.pop_back();
                }
            } else if (evento.text.unicode == '\r') { // Enter
                if (!nombreJugador.empty()) {
                    nombreIngresado = true;
                }
            } else {
                nombreJugador += static_cast<char>(evento.text.unicode);
            }
            textoNombre.setString(nombreJugador);
        }
    }
}

void DarNombreJugador::actualizar() {
    // No hace nada por ahora
}

void DarNombreJugador::dibujar() {
    ventana.clear();
    ventana.draw(textoInstruccion);
    ventana.draw(textoNombre);
    ventana.display();
}

bool DarNombreJugador::esNombreIngresado() const {
    return nombreIngresado;
}

const std::string& DarNombreJugador::getNombreJugador() const {
    return nombreJugador;
}

void DarNombreJugador::resetNombreIngresado() {
    nombreIngresado = false;
    nombreJugador.clear();
    textoNombre.setString("");
}
