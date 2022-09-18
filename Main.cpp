#include <iostream>
#include <fstream>
#include "Graph.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    std::ifstream file("D:\\Projects\\Task_1\\input.txt");
    Graph graph(&file);

    graph.primMST();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        graph.Show(&window);
        window.display();
    }

    return 0;
}