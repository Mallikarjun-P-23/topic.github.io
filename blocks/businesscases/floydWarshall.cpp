#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define INF INT_MAX

// Floyd-Warshall Algorithm
void floydWarshall(vector<vector<int>>& graph, int V) {
    // dist[][] will hold the shortest distances between every pair of vertices
    vector<vector<int>> dist(V, vector<int>(V, INF));

    // Initialize the distance matrix with the given graph weights
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) {
                dist[i][j] = 0; // Distance to itself is zero
            }
            else if (graph[i][j] != -1) {
                dist[i][j] = graph[i][j]; // If there's a direct edge, use its weight
            }
        }
    }

    // Floyd-Warshall core algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j]; // Update distance if a shorter path is found
                }
            }
        }
    }

    // Print the shortest distance matrix
    cout << "Shortest distances between every pair of vertices: \n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int V; // Number of vertices
    cout << "Enter the number of vertices: ";
    cin >> V;

    // Create a graph represented by an adjacency matrix
    vector<vector<int>> graph(V, vector<int>(V, -1));

    // Input graph edges and weights
    cout << "Enter the adjacency matrix (use -1 for no direct edge):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    // Run the Floyd-Warshall algorithm
    floydWarshall(graph, V);

    return 0;
}
