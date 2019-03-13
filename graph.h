#ifndef GRAPH_H
#define GRAPH_H

#include <icon.h>
#include <list>

using std::vector;
using std::cout;
using std::list;


// Helper functions to track the gamefield as an unweighted graph
// for Single Player Mode

// Detailed annotations in cpp file

void add_edge(vector<int> graph[], int s, int d);

void delete_edge(vector<int> graph[], int s, int d);

bool dijkstra(vector<int> graph[], int s, int d, int pred[], int dist[]);

vector<int> ShortestPath(vector<int> graph[],int s, int d);

#endif // GRAPH_H
