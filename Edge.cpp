#include <iostream>
#include <sstream>
#include "Edge.h"


void Edge::Show(RenderWindow* window)
{
    Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(x1, y1), macros),
        sf::Vertex(sf::Vector2f(x2, y2), macros)
    };

    Font font;
    if (!font.loadFromFile("VinnytsiaSansReg.ttf"))
    {
        std::cout << "Load font error\n";
    }

    CircleShape TopMain(20);
    TopMain.setFillColor(Color::Black);
    TopMain.setPosition((x1 + x2) / 2 - 20, (y1 + y2) / 2 - 20);

    std::string weightString;
    std::stringstream ss;
    ss << weight;
    ss >> weightString;

    Text text;
    text.setFont(font);
    text.setString(weightString);
    text.setFillColor(Color::White);
    text.setCharacterSize(20);
    text.setPosition((x1 + x2) / 2 - 9, (y1 + y2) / 2 - 13);

    (*window).draw(line, 2, sf::Lines);
    (*window).draw(TopMain);
    (*window).draw(text);
}