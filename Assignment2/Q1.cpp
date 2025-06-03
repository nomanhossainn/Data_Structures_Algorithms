#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E;
    struct Edge* edge;
};

// Function to create a new graph
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*) malloc(E * sizeof(struct Edge));
    return graph;
}

// Function to find the minimum product spanning tree using Prim's algorithm
void primMST(struct Graph* graph) {
    int V = graph->V;
    int parent[V];
    int key[V];
    int inMST[V];

    // Initialize all keys as infinite
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        inMST[i] = 0;
    }

    // Always include the first vertex in MST
    key[0] = 0;
    parent[0] = -1;  // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices
        // not yet included in MST
        int minKey = INT_MAX, minIndex;
        for (int v = 0; v < V; v++) {
            if (inMST[v] == 0 && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        // Add the picked vertex to the MST
        inMST[minIndex] = 1;

        // Update key value and parent index of the adjacent vertices
        // of the picked vertex. Consider only those vertices which are
        // not yet included in MST
        for (int v = 0; v < V; v++) {
            if (graph->edge[minIndex * V + v].weight && inMST[v] == 0 && graph->edge[minIndex * V + v].weight < key[v]) {
                parent[v] = minIndex;
                key[v] = graph->edge[minIndex * V + v].weight;
            }
        }
    }

    // Print the edges of the MST
    printf("\nEdges:\n");
    for (int i = 1; i < V; i++) {
        printf("%d—%d\n", parent[i], i);
    }

    // Calculate and print the minimum product
    unsigned long long minProduct = 1;
    for (int i = 1; i < V; i++) {
        minProduct *= graph->edge[parent[i] * V + i].weight;
    }
    printf("\nMinimum product: %llu\n", minProduct);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n, n * n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph->edge[u * n + v].src = u;
        graph->edge[u * n + v].dest = v;
        graph->edge[u * n + v].weight = w;
        graph->edge[v * n + u].src = v;
        graph->edge[v * n + u].dest = u;
        graph->edge[v * n + u].weight = w;
    }

    primMST(graph);

    return 0;
}
