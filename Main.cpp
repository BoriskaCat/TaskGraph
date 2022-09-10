#include <iostream>
#include "SFML/Graphics.hpp"
#include "Top.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    Top A;
    A.setCenter(200, 200);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.setActive();
        A.Show(&window);
        window.display();
    }
}