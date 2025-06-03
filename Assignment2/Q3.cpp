#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the vertex with minimum key value
int minKey(int key[], int inMST[], int V) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++) {
        if (inMST[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
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
    int parent[V];  // Store the MST
    int key[V];     // Key values used to pick minimum weight edge
    int inMST[V];   // To represent set of vertices included in MST

    // Initialize keys and MST set
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        inMST[i] = 0;
    }

    key[0] = 0;     // Start from the first vertex
    parent[0] = -1; // The first node is always the root of MST

    // Construct the MST
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, inMST, V); // Pick the minimum key vertex
        inMST[u] = 1; // Include the picked vertex in MST

        // Update key value and parent index of adjacent vertices
        for (int v = 0; v < V; v++) {
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

    // Allocate memory for the adjacency matrix
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
