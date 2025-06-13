#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

#define MAX 100

int minKey(int key[], bool mstSet[], int n) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[MAX][MAX], int n) {
    int totalCost = 0;
    cout << "Edge \tWeight\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
        totalCost += graph[i][parent[i]];
    }
    cout << "Total cost of MST: " << totalCost << endl;
}

void primMST(int graph[MAX][MAX], int n) {
    int parent[MAX]; // stores MST
    int key[MAX];    // min weight edge
    bool mstSet[MAX]; // vertices included in MST

    // Initialize
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;      // first vertex
    parent[0] = -1;  // root

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = true;

        for (int v = 0; v < n; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph, n);
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

    file.close();

    primMST(graph, n);

    return 0;
}
