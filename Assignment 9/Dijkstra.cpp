#include <iostream>
using namespace std;

#define INF 999999

int minDist(int dist[], bool visited[], int V) {
    int min = INF, min_index = -1;
    for (int i = 0; i < V; i++)
        if (!visited[i] && dist[i] < min)
            min = dist[i], min_index = i;
    return min_index;
}

void dijkstra(int graph[10][10], int src, int V) {
    int dist[10];
    bool visited[10];

    for (int i = 0; i < V; i++)
        dist[i] = INF, visited[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDist(dist, visited, V);
        visited[u] = true;

        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    cout << "Vertex  Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t" << dist[i] << "\n";
}
