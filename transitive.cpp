#include <iostream>
#include <vector>

using namespace std;

// Function to compute the transitive closure using Warshall's algorithm
void transitiveClosure(vector<vector<int>>& graph) {
    int V = graph.size();

    // Initialize the transitive closure matrix with the given graph
    vector<vector<int>> tc(V, vector<int>(V, 0));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            tc[i][j] = graph[i][j];
        }
    }

    // Update transitive closure matrix
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                tc[i][j] = tc[i][j] || (tc[i][k] && tc[k][j]);
            }
        }
    }

    // Print the transitive closure matrix
    cout << "Transitive closure of the given graph is:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << tc[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example directed graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 1},
        {1, 0, 0, 0}
    };

    transitiveClosure(graph);

    return 0;
}
