#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

#define MAX 100

int minDistance(int dist[], bool visited[], int n) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[MAX];       // shortest distance from src to i
    bool visited[MAX];   // visited[i] is true if shortest path to i is finalized

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print result
    cout << "Vertex\tDistance from Source " << src << endl;
    for (int i = 0; i < n; i++) {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    ifstream file("graph.txt");
    if (!file) {
        cout << "Cannot open file!" << endl;
        return 1;
    }

    int n;
    file >> n;

    int graph[MAX][MAX];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            file >> graph[i][j];

    int src;
    file >> src;

    file.close();

    dijkstra(graph, n, src);

    return 0;
}
