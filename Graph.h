#pragma once

#include <fstream>
#include "Top.h"
#include "Edge.h"


class Graph {
public:
    Graph(std::ifstream* fileVar);
	virtual ~Graph();

	void primMST();

	void Show(sf::RenderWindow* window);

private:
    std::ifstream* file = nullptr;
    int** graphMatrix = nullptr;
	int** mstMatrix = nullptr;
	float* xCoord = nullptr;
	float* yCoord = nullptr;
	int dimMatrix = 0;

	int minKey(int key[], bool mstSet[]);
	void buildCoord();
};

