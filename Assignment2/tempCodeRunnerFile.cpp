#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

class AdjListNode {
public:
    int v;
    int w;
    AdjListNode(int v, int w) {
        this->v = v;
        this->w = w;
    }
};

class PQNode {
public:
    int v;
    int key;
    PQNode(int v, int key) {
        this->v = v;
        this->key = key;
    }
};

class Comparator {
public:
    bool operator()(const PQNode &a, const PQNode &b) {
        return a.key > b.key;
    }
};

class Graph {
public:
    int V;
    list<AdjListNode> *adjList;

    Graph(int V) {
        this->V = V;
        adjList = new list<AdjListNode>[V];
    }

    void addEdge(int u, int v, int w) {
        adjList[u].push_back(AdjListNode(v, w));
        adjList[v].push_back(AdjListNode(u, w));
    }

    // Modified version of Prim's Algorithm to calculate the product of the weights
    void primsAlgorithm(int source) {
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> inMST(V, false);
        long long product = 1; // To store the product of weights
        priority_queue<PQNode, vector<PQNode>, Comparator> pq;
        
        key[source] = 0;
        pq.push(PQNode(source, key[source]));

        while (!pq.empty()) {
            int u = pq.top().v;
            pq.pop();

            if (inMST[u]) {
                continue;
            }
            inMST[u] = true;

            for (AdjListNode node : adjList[u]) {
                int v = node.v;
                int w = node.w;

                if (!inMST[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                    pq.push(PQNode(v, key[v]));
                }
            }
        }

        // Output the edges and compute the product of weights
        cout << "Edges:" << endl;
        for (int i = 1; i < V; ++i) {
            if (parent[i] != -1) {
                cout << parent[i] << " - " << i << endl;
                product *= key[i]; // Multiply the weight of the edge to the product
            }
        }
        cout << "Minimum product: " << product << endl;
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    Graph graph(V);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }
    graph.primsAlgorithm(0); // Starting from vertex 0
    return 0;
}