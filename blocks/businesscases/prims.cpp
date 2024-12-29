#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int u, v, weight;
    Edge(int u, int v, int w) : u(u), v(v), weight(w) {}
};

class Graph {
public:
    int V;
    vector<vector<int>> adjMatrix;

    Graph(int V) {
        this->V = V;
        adjMatrix.resize(V, vector<int>(V, INT_MAX));
    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }
};

vector<Edge> prim(Graph& g) {
    vector<bool> inMST(g.V, false);
    vector<int> key(g.V, INT_MAX);
    vector<int> parent(g.V, -1);
    vector<Edge> mst;

    key[0] = 0;
    for (int count = 0; count < g.V - 1; count++) {
        int u = -1;
        for (int i = 0; i < g.V; i++) {
            if (!inMST[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        inMST[u] = true;

        for (int v = 0; v < g.V; v++) {
            if (g.adjMatrix[u][v] != INT_MAX && !inMST[v] && g.adjMatrix[u][v] < key[v]) {
                key[v] = g.adjMatrix[u][v];
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i < g.V; i++) {
        mst.push_back(Edge(parent[i], i, g.adjMatrix[i][parent[i]]));
    }

    return mst;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Graph g(V);

    cout << "Enter edges (u, v, weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    vector<Edge> mst = prim(g);

    cout << "Minimum Spanning Tree (MST):\n";
    for (const Edge& edge : mst) {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
    }

    return 0;
}