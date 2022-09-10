#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Top : public CircleShape
{
public:
    Top() {}
    virtual ~Top() {}

    void setCenter(float xVar, float yVar)
    {
        x = xVar;
        y = yVar;
    }

    void Show(RenderWindow *window) 
    { 
        CircleShape TopMain(radius);
        TopMain.setFillColor(Color::Black);
        TopMain.setOutlineThickness(5);
        TopMain.setPosition(x, y);

        (*window).draw(TopMain);
    }

    void Setx(float xVar) { x = xVar; }
    void Sety(float yVar) { y = yVar; }
    float Getx() { return x; }
    float Gety() { return y; }

private:
    float x, y;
    const int radius = 95;
};

