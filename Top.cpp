#include <iostream>
#include <sstream>
#include "Top.h"


void Top::setCenter(float xVar, float yVar)
{
    x = xVar;
    y = yVar;
}

void Top::Show(RenderWindow* window)
{
    CircleShape TopMain(radius);
    TopMain.setFillColor(Color::Black);
    TopMain.setOutlineThickness(5);
    TopMain.setPosition(x - radius, y - radius);

    Font font;
    if (!font.loadFromFile("VinnytsiaSansBold.ttf"))
    {
        std::cout << "Load font error\n";
    }

    std::string TopID;
    std::stringstream ss;
    ss << static_cast<char> (0x41 + ID);
    ss >> TopID;

    Text text;
    text.setFont(font);
    text.setString(TopID);
    text.setFillColor(Color::White);
    text.setCharacterSize(40);
    text.setPosition(x - 15, y - 25);

    (*window).draw(TopMain);
    (*window).draw(text);
}