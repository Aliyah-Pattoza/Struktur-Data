#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> parent;
vector<int> path;

void bfs(int start, int target) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == target) {
            int curr = node;
            while (curr != start) {
                path.push_back(curr);
                curr = parent[curr];
            }
            path.push_back(start);
            return;
        }

        for (int i = 0; i < graph[node].size(); i++) {
            int neighbor = graph[node][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }
}

void CariJalur(int N, int E) {
    graph.resize(N + 1);
    visited.resize(N + 1, false);
    parent.resize(N + 1, -1);

    for (int i = 0; i < E; i++) {
        int A, B;
        cin >> A >> B;
        if (A < 1 || A > N || B < 1 || B > N) {
            return;
        }
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    int Start = 1;
    int target = N;

    bfs(Start, target);

    if (!path.empty()) {
        cout << path.size() << endl;
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i];
            if (i != 0) {
                cout << " ";
            }
        }
    } else {
        cout << "RIP LAPET 2023" << endl;
    }
}

int main() {
    int N, E;
    cin >> N >> E;

    if (N < 2 || N > 100000 || E < 2 || E > 100000) {
        return 0;
    }

    CariJalur(N, E);

    return 0;
}
