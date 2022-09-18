#pragma once

#include "SFML/Graphics.hpp"

using namespace sf;


class Top {
public:
    Top(float xVar, float yVar, int IDVar)
        : x(xVar), y(yVar), ID(IDVar)
    {}

    virtual ~Top() {}

    void Show(RenderWindow* window);

private:
    float x = 0, y = 0;
    float radius = 30;
    int ID;

    void setCenter(float xVar, float yVar);
};

