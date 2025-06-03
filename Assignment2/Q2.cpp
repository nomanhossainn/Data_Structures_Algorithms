#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the vertex with minimum key value,
// from the set of vertices not yet included in MST
int minKey(int key[], int inMST[], int V) {
    int min = INT_MAX, min_index;

    for (int i = 0; i < V; i++) {
        if (inMST[i] == 0 && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }

    return min_index;
}

// Function to print the edges of the MST and calculate the minimum product
void printMST(int parent[], int** graph, int V) {
    printf("\nEdges:\n");
    unsigned long long minProduct = 1;
    for (int i = 1; i < V; i++) {
        printf("%d—%d\n", parent[i], i);
        minProduct *= graph[i][parent[i]];
    }
    printf("\nMinimum product: %llu\n", minProduct);
}

// Function to find the minimum product spanning tree using Prim's algorithm
void primMST(int** graph, int V) {
    int parent[V];  // Array to store constructed MST
    int key[V];     // Key values used to pick minimum weight edge in cut
    int inMST[V];   // To represent set of vertices included in MST

    // Initialize all keys as infinite
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        inMST[i] = 0;
    }

    // Always include first  vertex in MST.
    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, inMST, V);

        // Add the picked vertex to the MST Set
        inMST[u] = 1;

        // Update key value and parent index of the adjacent vertices
        // of the picked vertex. Consider only those vertices which are
        // not yet included in MST
        for (int v = 0; v < V; v++) {
            // graph[u][v] is non zero only for adjacent vertices of m
            // inMST[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && inMST[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the edges of the MST and calculate the minimum product
    printMST(parent, graph, V);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Create a 2D array for the graph
    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0; // Initialize all values to 0
        }
    }

    // Read the edges and weights
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        // Update the adjacency matrix
        graph[u][v] = w;
        graph[v][u] = w; // Undirected graph, so update both entries
    }

    // Find and print the minimum product spanning tree
    primMST(graph, n);

    // Free the allocated memory
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
