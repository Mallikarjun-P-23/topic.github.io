#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
using namespace std;

void bellmanFord(int vertices, int edges, vector<tuple<int, int, int>> &graph, int source) {
    vector<int> distance(vertices, INT_MAX);
    distance[source] = 0;

    for (int i = 1; i <= vertices - 1; ++i) {
        for (auto &[u, v, w] : graph) {
            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    for (auto &[u, v, w] : graph) {
        if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
            cout << "Graph contains a negative-weight cycle." << endl;
            return;
        }
    }

    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < vertices; ++i) {
        cout << i << "\t" << (distance[i] == INT_MAX ? "INF" : to_string(distance[i])) << endl;
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    vector<tuple<int, int, int>> graph;
    for (int i = 0; i < edges; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.emplace_back(u, v, w);
    }

    int source;
    cin >> source;

    bellmanFord(vertices, edges, graph, source);

    return 0;
}