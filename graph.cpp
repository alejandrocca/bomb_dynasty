#include <graph.h>

/**
 * @brief add_edge
 *        adds an unweighted doubly linked edge to graph
 * @param <vector<int>> graph   - graph to add edge to
 *        <int> s               - source node
 *        <int> d               - destination node
 */
void add_edge(vector<int> graph[], int s, int d)
{
    graph[s].push_back(d);
    graph[d].push_back(s);
}

/**
 * @brief delete_edge
 *        deletes an edge to graph for both directions
 * @param <vector<int>> graph   - graph to delete edge from
 *        <int> s               - source node
 *        <int> d               - destination node
 */
void delete_edge(vector<int> graph[], int s, int d)
{
    std::vector<int>::iterator it = std::find(graph[s].begin(),graph[s].end(), d);
    if (it != graph[s].end()){
        // if edge exists
        graph[s].erase(it);
    }

    std::vector<int>::iterator it2 = std::find(graph[d].begin(),graph[d].end(), s);
    if (it2 != graph[s].end()){
        // if edge exists
        graph[d].erase(it2);
    }
}

/**
 * @brief dijkstra
 * @param <vector<int>> graph[]     - graph to traverse
 *        <int> s                   - source node
 *        <int> d                   - destination node
 *        <int> pred[]              - array to store path
 *        <int> dist[]              - array to store distance
 * @return <bool>                   - true if source and destination nodes are connected; false otherwise
 */
bool dijkstra(vector<int> graph[], int s, int d, int pred[], int dist[]){


    // Preparation of containers
    list<int> l;                                        // nodes to be scanned

    bool visited[100];                                  // if nodes visited at least once


    // Initialization
    for (int i = 0; i < 100; i++) {
        // Initialize info for each node: visited = 0; distance = infinity
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }

    // First Step: visit the source node
    visited[s] = true;
    dist[s] = 0;
    l.push_back(s);

    // Dijkstra's Algorithm
    while (!l.empty()) {
        // traverse thru all nodes in graph: tracked with index i
        int i = l.front();
        l.pop_front();
        for (size_t j = 0; j < graph[i].size(); ++j) {
            // for the jth node that the ith node is connected to:
            if (visited[graph[i][j]] == false) {
                // if node hasn't been traversed:
                visited[graph[i][j]] = true;
                dist[graph[i][j]] = dist[i] + 1;
                pred[graph[i][j]] = i;
                l.push_back(graph[i][j]);

                // Return true if d is traversed
                if (graph[i][j] == d) return true;
            }
        }
    }

    // Return false if d is not found
    return false;
}

/**
 * @brief ShortestPath
 * @param vector<int> graph[], <int> s, <int> d
 * @return vector<int> path - shortest path from s to d on graph
 */
vector<int> ShortestPath(vector<int> graph[],int s, int d){
    // Preparation of Containers
    vector<int> path;
    int pred[100], dist[100];

    // Traverse thru nodes
    bool dijk = dijkstra(graph, s, d, pred, dist);

    if (dijk == false){
        // if d is not found (s and d are not connected) -> return an empty path
         return path;
    }

    else{
        // if d is found -> construct path
        int i = d;
        path.push_back(i);
        while (pred[i] != -1) {
            // construct path by pushing back each preceeding node stored in pred[]
            path.push_back(pred[i]);
            i = pred[i];
        }
        return path;
    }
}
