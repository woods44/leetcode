#include <random>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>
#include <time.h>
#include <set>
using namespace std;

struct Graph
{
    int id;
    int x;
    int y;
};

double distance(Graph *it, Graph *to)
{
    int fromX = it->x;
    int fromY = it->y;
    int toX = to->x;
    int toY = to->y;
    cout << fromX << " " << fromY << endl;
    cout << toX << " " << toY << endl;
    return sqrt(pow((fromX - toX), 2) + pow((fromY - toY), 2));
}

int main()
{
    // vector<vector<int>> points({{-100, 0}, {-80, 58}, {-30, 95}, {80, 58}, {-80, -58}, {-30, -95}, {30, -95}, {80, -58}, {100, 0}});
    vector<vector<int>> points({{-100, 0}, {-80, 58}, {-30, 95}, {80, 58}});
    vector<Graph *> graphs;
    int id = 0;
    for (vector<int> p : points)
    {
        Graph *g = new Graph{id, p[0], p[1]};
        graphs.emplace_back(g);
        id++;
    }
    cout << distance(graphs[0], graphs[1]) << endl;
    for (Graph *g : graphs)
    {
        cout << g->id << ", ";
    }
    int x = 1;
    int y = 2;
    while (x < y)
    {
        swap(graphs[x++], graphs[y--]);
    }
    cout << endl;
    for (Graph *g : graphs)
    {

        cout << g->id << ", ";
    }
    cout << endl;
}