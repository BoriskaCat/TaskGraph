#include <iostream>
#include "SFML/Graphics.hpp"
#include "GraphWindow.h"
#include "Header.h"

int main()
{
	//sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");

    sf::CircleShape TopExample1(95);
    TopExample1.setFillColor(sf::Color(0, 0, 0));
    TopExample1.setOutlineThickness(5);
    TopExample1.setPosition(100, 200);

    sf::CircleShape TopExample2(100);
    TopExample2.setFillColor(sf::Color(0, 0, 0));
    TopExample2.setOutlineThickness(5);
    TopExample2.setPosition(500, 200);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        example();
        window.draw(TopExample1);
        window.draw(TopExample2);
        window.display();
    }

	std::cout << "Hello, world!\n";
}