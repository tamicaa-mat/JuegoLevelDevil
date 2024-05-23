#include "Nivel1.h"

Nivel1::Nivel1(sf::RenderWindow& vent) : ventana(vent), piso(800, 150), pb(40, 65), obstaculo1(200, 420, 25, 25), obstaculo2(400, 420, 25, 25), vidas(3), gameOver(false), gameOverResolved(false) {
    if (!fuente.loadFromFile("fuentes/Roboto-Black.ttf")) {
        // Manejo de error
    }
    textoNivel.setFont(fuente);
    textoNivel.setString("Nivel 1 Vidas: " + std::to_string(vidas));
    textoNivel.setCharacterSize(24);
    textoNivel.setFillColor(sf::Color::White);
    textoNivel.setPosition(10, 10);

    textoGameOver.setFont(fuente);
    textoGameOver.setString("GAME OVER\nPresione Enter para ir al menu principal");
    textoGameOver.setCharacterSize(50);
    textoGameOver.setFillColor(sf::Color::Red);
    textoGameOver.setPosition(100, 200);
}

void Nivel1::manejarEntrada() {
    sf::Event evento;
    while (ventana.pollEvent(evento)) {
        if (evento.type == sf::Event::Closed)
            ventana.close();
        if (gameOver && evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Enter) {
            gameOverResolved = true; // Indicar que se ha resuelto el estado de "Game Over"
        }
    }
}

void Nivel1::actualizar() {
    if (gameOver) return;

    pp.cmd();
    pp.update();

    // Comprobar colisiones
    if (pp.colisionaCon(obstaculo1) || pp.colisionaCon(obstaculo2)) {
        vidas--;
        if (vidas > 0) {
            pp = Personaje(); // Reiniciar la posición del personaje
        } else {
            // Activar estado de "Game Over"
            gameOver = true;
        }
    }

    textoNivel.setString("Nivel 1 Vidas: " + std::to_string(vidas));
}

void Nivel1::dibujar() {
    ventana.clear();
    if (gameOver) {
        ventana.draw(textoGameOver);
    } else {
        ventana.draw(textoNivel);
        ventana.draw(pb.getDraw());
        ventana.draw(piso.getdraw());
        ventana.draw(m.getDraw());
        ventana.draw(obstaculo1.getDraw());
        ventana.draw(obstaculo2.getDraw());
        ventana.draw(pp.getDraw());
    }
    ventana.display();
}

bool Nivel1::isGameOverResolved() const {
    return gameOverResolved;
}
