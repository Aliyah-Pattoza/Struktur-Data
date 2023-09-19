#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest, weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

struct Graph {
    int sf;
    vector<vector<int>> adj;

    Graph(int vertic) : sf(vertic), adj(vertic, vector<int>(vertic, 0)) {}

    void addEdge(int src, int dest, int weight) {
        adj[src][dest] = weight;
        adj[dest][src] = weight;
    }

    int minDistance(vector<int>& dist, vector<bool>& spt) {
        int min = INT_MAX, min_index;
        for (int v = 0; v < sf; v++) {
            if (spt[v] == 0 && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    void printSolusi(vector<int>& dist) {
        cout << dist[sf - 1] << endl;
    }

    void dijkstra(int src) {
        vector<int> dist(sf, INT_MAX);
        vector<bool> spt(sf, 0);

        dist[src] = 0;

        for (int count = 0; count < sf - 1; count++) {
            int u = minDistance(dist, spt);
            spt[u] = true;

            for (int v = 0; v < sf; v++) {
                if (!spt[v] && adj[u][v] != 0 && dist[u] != INT_MAX && max(dist[u], adj[u][v]) < dist[v]) {
                    dist[v] = max(dist[u], adj[u][v]);
                }
            }
        }
        printSolusi(dist);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph graph(n);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph.addEdge(a - 1, b - 1, c);
    }

    graph.dijkstra(0);

    return 0;
}
