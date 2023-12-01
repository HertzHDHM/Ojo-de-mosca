#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Ojo de Mosca");

    int nVertices = 15; 
    float radio = 200.0f;
    std::vector<sf::Vector2f> vertices;

    for (int i = 0; i < nVertices; ++i) {
        float angulo = 2 * 3.1416 * i / nVertices;
        float x = radio * std::cos(angulo) + 400; 
        float y = radio * std::sin(angulo) + 400;
        vertices.push_back(sf::Vector2f(x, y));
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        sf::VertexArray lineas(sf::Lines);

        for (int i = 0; i < nVertices; ++i) {
            for (int j = i + 1; j < nVertices; ++j) {
                lineas.append(sf::Vertex(vertices[i], sf::Color::Red));
                lineas.append(sf::Vertex(vertices[j], sf::Color::Blue));
            }
        }

        window.draw(lineas);
        window.display();
    }

    return 0;
}