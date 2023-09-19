#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Friend {
    int id;
    int confidence;

    Friend(int _id, int _confidence) : id(_id), confidence(_confidence) {}
};

struct Edge {
    int u;
    int v;
    int closeness;

    Edge(int _u, int _v, int _closeness) : u(_u), v(_v), closeness(_closeness) {}
};

class Graph {
    int N;
    vector<int> confidenceLevels;
    vector<vector<Edge>> adjacencyList;

public:
    Graph(int n) {
        N = n;
        confidenceLevels.resize(N + 1);
        adjacencyList.resize(N + 1);
    }

    void setConfidenceLevel(int id, int confidence) {
        confidenceLevels[id] = confidence;
    }

    void addFriendship(int u, int v, int closeness) {
        adjacencyList[u].push_back(Edge(u, v, closeness));
        adjacencyList[v].push_back(Edge(v, u, closeness));
    }

    int getMinCloseness(int start) {
        vector<bool> visited(N + 1, false);
        visited[start] = true;
        queue<int> q;
        q.push(start);
        int minCloseness = -1;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (const Edge& edge : adjacencyList[current]) {
                if (!visited[edge.v]) {
                    visited[edge.v] = true;
                    q.push(edge.v);
                    if (minCloseness == -1 || edge.closeness < minCloseness) {
                        minCloseness = edge.closeness;
                    }
                }
            }
        }

        return minCloseness;
    }

    int getTotalConfidence(int start, int end) {
        if (start == end) return 0;

        vector<int> maxConfidence(N + 1, 0);
        vector<bool> visited(N + 1, false);
        visited[start] = true;
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (const Edge& edge : adjacencyList[current]) {
                if (!visited[edge.v]) {
                    visited[edge.v] = true;
                    q.push(edge.v);
                    maxConfidence[edge.v] = max(maxConfidence[current], confidenceLevels[edge.v]);
                }
            }
        }

        return maxConfidence[end] + maxConfidence[start];
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    Graph graph(N);

    for (int i = 1; i <= N; i++) {
        int confidence;
        cin >> confidence;
        graph.setConfidenceLevel(i, confidence);
    }

    for (int i = 0; i < M; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        graph.addFriendship(U, V, W);
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int queryType, A, B, X;
        cin >> queryType;

        if (queryType == 1) {
            cin >> A >> X;
            graph.setConfidenceLevel(A, X);
        } else if (queryType == 2) {
            cin >> A >> B >> X;
            graph.addFriendship(A, B, X);
        } else if (queryType == 3) {
            cin >> A;
            int minCloseness = graph.getMinCloseness(A);
            cout << minCloseness << endl;
        } else if (queryType == 4) {
            cin >> A >> B;
            int totalConfidence = graph.getTotalConfidence(A, B);
            cout << totalConfidence << endl;
        }
    }

    return 0;
}
