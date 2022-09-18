#pragma once

#include "SFML/Graphics.hpp"

using namespace sf;


class Edge {
public:
	Edge(float x1Var, float y1Var, float x2Var, float y2Var, int weightVar, Color macrosVar)
		: x1(x1Var), y1(y1Var), x2(x2Var), y2(y2Var), weight(weightVar), macros(macrosVar)
	{}

	virtual ~Edge() {}

	void Show(RenderWindow* window);

private:
	float x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	int weight = 0;
	Color macros;
};

