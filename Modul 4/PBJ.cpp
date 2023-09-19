#include <bits/stdc++.h>
#define MAX_VERTICES 1000

typedef struct Edge_e{
    int first;
    int second;
} Edge;

typedef struct Graph_g{
    int numVertex;
    int numEdges;
    Edge edges[MAX_VERTICES];
} Graph;

void initializeGraph(Graph *graph, int numVertex, int numEdges) {
    graph->numVertex = numVertex;
    graph->numEdges = numEdges;

    for (int i = 0; i < numEdges; i++) {
        int first, second;
        scanf ("%d %d", &first, &second);
        graph->edges[i].first = first;
        graph->edges[i].second = second;
    }
}

int findRoot(int parent[], int vertex) {
    while (parent[vertex] != vertex)
        vertex = parent[vertex];
    return vertex;
}

void unionVertices(int parent[], int size[], int vertex1, int vertex2) {
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

int minimumEdgesToConnect(Graph* graph) {
    int parent[MAX_VERTICES], size[MAX_VERTICES];

    for (int i = 0; i < graph->numVertex; i++) {
        parent[i] = i;
        size[i] = 1;
    }

   for (int i = 0; i < graph->numEdges; i++) {
        int first = graph->edges[i].first;
        int second = graph->edges[i].second;
        unionVertices(parent, size, first, second);
    }

    int count = 0;
    for (int i = 0; i < graph->numVertex; i++) {
        if (parent[i] == i)
            count++;
    }

    return count - 1;
}

int main(){
   int v, n;
   scanf ("%d %d", &v, &n);

   Graph graph;
   initializeGraph(&graph, v, n);

   int minEdges = minimumEdgesToConnect(&graph);
    printf("%d\n", minEdges);
}
