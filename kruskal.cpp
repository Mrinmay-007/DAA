#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#define MAX 100

struct Edge {
    int u, v, weight;
};

// For sorting edges by weight
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Find parent (with path compression)
int findParent(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = findParent(parent, parent[i]);
}

// Union sets
void unionSets(int parent[], int u, int v) {
    int pu = findParent(parent, u);
    int pv = findParent(parent, v);
    parent[pu] = pv;
}

void kruskal(Edge edges[], int V, int E) {
    // Sort edges by weight
    sort(edges, edges + E, compare);

    int parent[MAX];
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int totalCost = 0;
    cout << "Edge \tWeight\n";

    for (int i = 0, count = 0; count < V - 1 && i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        if (findParent(parent, u) != findParent(parent, v)) {
            cout << u << " - " << v << "\t" << w << "\n";
            unionSets(parent, u, v);
            totalCost += w;
            count++;
        }
    }

    cout << "Total cost of MST: " << totalCost << endl;
}

int main() {
    ifstream file("graph.txt");
    if (!file) {
        cout << "Cannot open file!" << endl;
        return 1;
    }

    int V, E;
    file >> V >> E;

    Edge edges[MAX];
    for (int i = 0; i < E; i++) {
        file >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    file.close();

    kruskal(edges, V, E);

    return 0;
}
