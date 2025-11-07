#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> iPair; // (distance, vertex)

class Graph {
    int V;
    vector<vector<iPair>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
        // For undirected graph, uncomment the next line
        // adj[v].push_back(make_pair(u, w));
    }

    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
        pq.push(make_pair(0, src));

        while (!pq.empty()) {
            int u = pq.top().second;
            int currDist = pq.top().first;
            pq.pop();

            if (currDist > dist[u]) continue; // Skip outdated entry

            for (auto &edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        // Print shortest distances
        cout << "Vertex\tDistance from Source\n";
        for (int i = 0; i < V; i++)
            cout << i << "\t" << dist[i] << "\n";
    }
};

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1, 9);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(0, 4, 3);
    g.addEdge(2, 1, 2);
    g.addEdge(2, 3, 4);

    int source = 0;
    cout << "Dijkstra's shortest paths from vertex " << source << ":\n";
    g.dijkstra(source);

    return 0;
}
