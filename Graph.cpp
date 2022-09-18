#define _USE_MATH_DEFINES
#include <sstream>
#include <iostream>
#include <cmath>
#include "Graph.h"


Graph::Graph(std::ifstream* fileVar) : file(fileVar)
{
    int i = 0, j = 0, lineLength = 0;
    std::string line;

    if ((*file).is_open()) { getline((*file), line); }
    (*file).seekg(0, std::ios::beg);

    lineLength = (int) line.length();

    for (i = 0; i < lineLength; i++)
    {
        if (line[i] == ' ')
        {
            dimMatrix++;
        }
    }

    dimMatrix++;

    graphMatrix = new int* [dimMatrix];
    for (i = 0; i < dimMatrix; i++)
        graphMatrix[i] = new int[dimMatrix];

    for (int i = 0; i < dimMatrix; i++)
        for (int j = 0; j < dimMatrix; j++)
            *file >> graphMatrix[i][j];

    (*file).close();
}

Graph::~Graph()
{
    for (int i = 0; i < dimMatrix; i++)
        delete[] graphMatrix[i];

    if (mstMatrix != nullptr)
    {
        for (int i = 0; i < dimMatrix; i++)
            delete[] mstMatrix[i];
    }

    if (xCoord != nullptr)
    {
        delete[] xCoord;
        delete[] yCoord;
    }
}

int Graph::minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index = 0;

    for (int i = 0; i < dimMatrix; i++)
        if (mstSet[i] == false && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }

    return min_index;
}

void Graph::primMST()
{
    mstMatrix = new int* [dimMatrix];
    for (int i = 0; i < dimMatrix; i++)
        mstMatrix[i] = new int[dimMatrix];

    for (int i = 0; i < dimMatrix; i++)
    {
        for (int j = 0; j < dimMatrix; j++)
            mstMatrix[i][j] = 0;
    }

    // Array to store constructed MST
    int* parent = new int [dimMatrix];

    // Key values used to pick minimum weight edge in cut
    int* key = new int [dimMatrix];

    // To represent set of vertices included in MST
    bool* mstSet = new bool [dimMatrix];

    // Initialize all keys as INFINITE
    for (int i = 0; i < dimMatrix; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first
    // vertex.
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < dimMatrix - 1; count++) {
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        for (int v = 0; v < dimMatrix; v++) 
        {

            // graph[u][v] is non zero only for adjacent
            // vertices of m mstSet[v] is false for vertices
            // not yet included in MST Update the key only
            // if graph[u][v] is smaller than key[v]
            if (graphMatrix[u][v] && mstSet[v] == false && graphMatrix[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graphMatrix[u][v];
            }
        }
    }

    for (int i = 1; i < dimMatrix; i++)
        mstMatrix[parent[i]][i] = graphMatrix[parent[i]][i];

    for (int i = 1; i < dimMatrix; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (mstMatrix[i][j] != 0)
                mstMatrix[j][i] = mstMatrix[i][j];
        }
    }

    delete[] parent;
    delete[] key;
    delete[] mstSet;
}

void Graph::buildCoord()
{
    xCoord = new float [dimMatrix];
    yCoord = new float [dimMatrix];

    for (int i = 0; i < dimMatrix; i++) {
        xCoord[i] = (float) (400 + 300 * cos(-1 * M_PI_2 + i * 2 * M_PI / dimMatrix));
        yCoord[i] = (float) (400 + 300 * sin(-1 * M_PI_2 + i * 2 * M_PI / dimMatrix));
    }
}

void Graph::Show(sf::RenderWindow* window)
{
    if (xCoord == nullptr)
        buildCoord();

    for (int i = 0; i < dimMatrix; i++) 
    {
        for (int j = i; j < dimMatrix; j++) 
        {
            if (graphMatrix[i][j]) 
            {
                float cosVar = (float) ((xCoord[j] - xCoord[i]) / sqrt(pow(xCoord[j] - xCoord[i], 2) + pow(yCoord[j] - yCoord[i], 2)));
                float sinVar = (float) ((yCoord[j] - yCoord[i]) / sqrt(pow(xCoord[j] - xCoord[i], 2) + pow(yCoord[j] - yCoord[i], 2)));
                sf::Color macros = sf::Color::White;

                if (mstMatrix != nullptr && mstMatrix[i][j] != 0)
                    macros = sf::Color::Magenta;
                else
                    macros = sf::Color::White;


                Edge graphEdge(xCoord[i] + 50 * cosVar, yCoord[i] + 50 * sinVar,
                    xCoord[j] - 50 * cosVar, yCoord[j] - 50 * sinVar,
                    graphMatrix[i][j], macros);

                graphEdge.Show(window);
                graphEdge.~Edge();
            }
        }
    }

    for (int i = 0; i < dimMatrix; i++) {
        Top graphTop(xCoord[i], yCoord[i], i);
        graphTop.Show(window);
        graphTop.~Top();
    }
}
