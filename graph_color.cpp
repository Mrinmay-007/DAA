#include <iostream>
using namespace std;

#define MAX 20

bool isSafe(int v, int graph[MAX][MAX], int color[], int c, int n) {
    for (int i = 0; i < n; i++)
        if (graph[v][i] && color[i] == c)
            return false;
    return true;
}

bool solveGraphColoring(int graph[MAX][MAX], int m, int color[], int v, int n) {
    if (v == n)
        return true; // All vertices are assigned

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c, n)) {
            color[v] = c;

            if (solveGraphColoring(graph, m, color, v + 1, n))
                return true;

            color[v] = 0; // Backtrack
        }
    }

    return false;
}

void graphColoring(int graph[MAX][MAX], int m, int n) {
    int color[MAX] = {0};

    if (!solveGraphColoring(graph, m, color, 0, n)) {
        cout << "No solution exists\n";
        return;
    }

    // Print result
    cout << "Solution exists. Assigned colors:\n";
    for (int i = 0; i < n; i++)
        cout << "Vertex " << i << " ---> Color " << color[i] << endl;
}

int main() {
    int graph[MAX][MAX], n, m;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    cout << "Enter number of colors (m): ";
    cin >> m;

    graphColoring(graph, m, n);
    return 0;
}
