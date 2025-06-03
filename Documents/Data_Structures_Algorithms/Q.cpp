#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

void printMST(int parent[], int** graph, int V) {
    printf("\nEdges:\n");
    unsigned long long minProduct = 1;
    for (int i = 1; i < V; i++) {
        printf("%d—%d\n", parent[i], i);
        minProduct *= graph[i][parent[i]];
    }
    printf("\nMinimum product: %llu\n", minProduct);
}

void primMST(int** graph, int V) {
    int parent[V];  
    int key[V];   
    int inMST[V]; 

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        inMST[i] = 0;
    }

    key[0] = 0;     
    parent[0] = -1; 

    for (int count = 0; count < V - 1; count++) {

        int u = minKey(key, inMST, V);
        inMST[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && inMST[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph, V);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0; 
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    primMST(graph, n);
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
