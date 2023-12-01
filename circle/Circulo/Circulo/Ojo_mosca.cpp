#include "Ojo_mosca.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;



void Ojo_mosca::calcularPosicion(int numPuntos, float radio) {
    std::vector<sf::Vector2f> puntos;

    for (int i = 0; i < numPuntos; ++i) {
        float angulo = 2 * 3.1416 * i / numPuntos;
        float x = radio * std::cos(angulo) + 400; // Centrar en x
        float y = radio * std::sin(angulo) + 400; // Centrar en y
        puntos.push_back(sf::Vector2f(x, y));
    }
}

void Ojo_mosca::dibujarOjo(int numPuntos) {
    std::vector<sf::Vector2f> puntos;
    sf::VertexArray lineas(sf::Lines);

    for (int i = 0; i < numPuntos; ++i) {
        for (int j = i + 1; j < numPuntos; ++j) {
            lineas.append(sf::Vertex(puntos[i], sf::Color::Red));
            lineas.append(sf::Vertex(puntos[j], sf::Color::Blue));
        }
    }

}


