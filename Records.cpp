#include "Records.h"
#include <algorithm> // Para std::sort
#include "ArchivoJugador.h"
Records::Records(sf::RenderWindow& vent) : ventana(vent) {
    fuente.loadFromFile("fuentes/Roboto-Black.ttf");
    textoTitulo.setFont(fuente);
    textoTitulo.setString("Records");
    textoTitulo.setCharacterSize(50);
    textoTitulo.setFillColor(sf::Color::White);
    textoTitulo.setPosition(200, 50);

    cargarRecords();
}

void Records::cargarRecords() {

    FILE* p = fopen("partidas.dat", "rb");
    if (p == NULL) {
        sf::Text textoNoDatos;
        textoNoDatos.setFont(fuente);
        textoNoDatos.setString("No hay datos aun");
        textoNoDatos.setCharacterSize(30);
        textoNoDatos.setFillColor(sf::Color::White);
        textoNoDatos.setPosition(200, 200);
        textosJugadores.push_back(textoNoDatos);
        return;
    }
    std::vector<Jugador> jugadores;
    Jugador jugador("", 0);
    while (fread(&jugador, sizeof jugador, 1, p) == 1) {
        jugadores.push_back(jugador);
    }
    fclose(p);

    // Ordenar jugadores por puntaje de mayor a menor
    std::sort(jugadores.begin(), jugadores.end(), [](const Jugador& a, const Jugador& b) {
        return a.getPuntaje() > b.getPuntaje();
    });

    int y = 150;
    for (const auto& jug : jugadores) {
        sf::Text textoJugador;
        textoJugador.setFont(fuente);

        textoJugador.setString(jug.getNombre() + std::string(" Puntos: ") + std::to_string(jug.getPuntaje()) + std::to_string(jug.getNivel()));
        textoJugador.setCharacterSize(30);
        textoJugador.setFillColor(sf::Color::White);
        textoJugador.setPosition(200, y);
        y += 40;
        textosJugadores.push_back(textoJugador);
    }
}

void Records::manejarEntrada() {
    sf::Event evento;
    while (ventana.pollEvent(evento)) {
        if (evento.type == sf::Event::Closed)
            ventana.close();
        if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Escape) {
            ventana.close();
        }
    }
}

void Records::dibujar() {
    ventana.clear();
    ventana.draw(textoTitulo);
    for (const auto& texto : textosJugadores) {
        ventana.draw(texto);
    }
    ventana.display();
}
