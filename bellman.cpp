#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int src, dest, weight;
};

class Graph {
    int V, E;
    vector<Edge> edges;

public:
    Graph(int V, int E) : V(V), E(E) {}

    void addEdge(int src, int dest, int weight) {
        edges.push_back({src, dest, weight});
    }

    bool detectNegativeCycle(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Relax all edges V-1 times
        for (int i = 1; i <= V-1; ++i) {
            for (const auto& edge : edges) {
                int u = edge.src;
                int v = edge.dest;
                int w = edge.weight;
                if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Check for negative-weight cycles by relaxing one more time
        for (const auto& edge : edges) {
            int u = edge.src;
            int v = edge.dest;
            int w = edge.weight;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                // Negative cycle detected
                return true;
            }
        }
        return false;
    }
};

int main() {
    int V = 5, E = 8;
    Graph g(V, E);

    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);

    if (g.detectNegativeCycle(0))
        cout << "Graph contains a negative weight cycle\n";
    else
        cout << "No negative weight cycle detected\n";

    return 0;
}
