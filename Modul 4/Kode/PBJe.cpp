#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

typedef struct Edgee {
    int sc;
    int dest;
} Edge;

typedef struct Graf {
    int numVertex;
    int numEdges;
    Edge edges[MAX];
} Graph;

int findRoot(int parent[], int vertex) {
    while (parent[vertex] != vertex)
        vertex = parent[vertex];
    return vertex;
}

void unionSet(int parent[], int size[], int vertex1, int vertex2) {
    int root1 = findRoot(parent, vertex1);
    int root2 = findRoot(parent, vertex2);

    if (root1 != root2) {
        if (size[root1] < size[root2]) {
            parent[root1] = root2;
            size[root2] += size[root1];
        } else {
            parent[root2] = root1;
            size[root1] += size[root2];
        }
    }
}

int countEdges(Graph* graph) {
    int parent[MAX], size[MAX];

    for (int i = 0; i < graph->numVertex; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    for (int i = 0; i < graph->numEdges; i++) {
        int first = graph->edges[i].sc;
        int second = graph->edges[i].dest;
        unionSet(parent, size, first, second);
    }

    int count = 0;
    for (int i = 0; i < graph->numVertex; i++) {
        if (parent[i] == i)
            count++;
    }
    return count - 1;
}

int main() {
    int V, N;
    cin >> V >> N;

    Graph graf;
    graf.numVertex = V;
    graf.numEdges = N;

    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        graf.edges[i].sc = A;
        graf.edges[i].dest = B;
    }

    int minEdge = countEdges(&graf);
    cout << minEdge << endl;

    return 0;
}
