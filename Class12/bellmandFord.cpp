// #include<iostream>
// #include<list>
// #include<queue>
// #include<vector>
// using namespace std;
// class AdjListNode{
//     public:
//     int v;
//     int w;

//     AdjListNode(int v,int w){
//         this->v=v;
//         this->w=w;
//     }

// };


// class Graph{
//     public:
//     int V;
//     list <AdjListNode> *adjList;

//     Graph(int V){
//         this->V=V;
//         adjList = new list <AdjListNode> [V+1];
//     }

//     void addEdge(int u,int v, int w){
//         adjList[u].push_back(AdjListNode( v, w));
//         adjList[v].push_back(AdjListNode( u, w));
//     }

//     void printAdjList(){
//         for(int i=1;i<=V;i++){
//             for(AdjListNode x : adjList[i]){
//                 cout<<"("<<x.v<<","<<x.w<<")"<<" ";
//             }
//             cout<<endl;
//         }
//     }



//     void bellManFordAlgorithm(int s){
//         int d[V+1];
//         int p[V+1];

//         for(int i=1;i<=V;i++){
//             d[i]=9999;
//             p[i]=-1;
//         }

//         d[s]=0;
//         for(int i=1;i<=V-1;i++){
//             // taking all the edges
//             for(int i=1;i<=V;i++){
//                 for(AdjListNode aln:adjList[i]){
//                     int u=i;
//                     int v= aln.v;
//                     int w=aln.w;
//                     if(d[u]+w<d[v]){
//                         d[v]=d[u]+w;
//                         p[v]=u;
//                     }
//                 }

//             }

//         }
//         for(int i=1;i<=V;i++){
//             cout<<"parent of "<<i<<" is "<<p[i]<<endl;

//         }

//     }
// };

// int main(){
//     int V,E;
//     cin>>V;
//     cin>>E;

//     Graph graph(V);

//     for(int i=1;i<=E;i++){
//         int u,v,w;
//         cin>>u;
//         cin>>v;
//         cin>>w;
//         graph.addEdge(u,v,w);
//     }

//     graph.printAdjList();
//     cout<<"After running bellmanford's algorithm"<<endl;
//     graph.bellManFordAlgorithm(1);

// }

/*
5 7
1 2 2
1 3 1
2 3 4
2 4 3
3 4 1
3 5 5
4 5 1
*/

#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

class AdjListNode{
public:
    int v;
    int w;

    AdjListNode(int v, int w){
        this->v = v;
        this->w = w;
    }
};

class Graph{
public:
    int V;
    list<AdjListNode> *adjList;

    Graph(int V){
        this->V = V;
        adjList = new list<AdjListNode>[V + 1];
    }

    void addEdge(int u, int v, int w){
        adjList[u].push_back(AdjListNode(v, w));
        adjList[v].push_back(AdjListNode(u, w));
    }

    void printAdjList(){
        for(int i = 1; i <= V; i++){
            for(list<AdjListNode>::iterator it = adjList[i].begin(); it != adjList[i].end(); ++it){
                AdjListNode x = *it;
                cout << "(" << x.v << "," << x.w << ") ";
            }
            cout << endl;
        }
    }

    void bellManFordAlgorithm(int s){
        int d[V + 1];
        int p[V + 1];

        for(int i = 1; i <= V; i++){
            d[i] = 9999;
            p[i] = -1;
        }

        d[s] = 0;
        for(int i = 1; i <= V - 1; i++){
            for(int j = 1; j <= V; j++){
                for(list<AdjListNode>::iterator it = adjList[j].begin(); it != adjList[j].end(); ++it){
                    int u = j;
                    int v = (*it).v;
                    int w = (*it).w;
                    if(d[u] + w < d[v]){
                        d[v] = d[u] + w;
                        p[v] = u;
                    }
                }
            }
        }

        for(int i = 1; i <= V; i++){
            cout << "parent of " << i << " is " << p[i] << endl;
        }
    }
};

int main(){
    int V, E;
    cin >> V;
    cin >> E;

    Graph graph(V);

    for(int i = 1; i <= E; i++){
        int u, v, w;
        cin >> u;
        cin >> v;
        cin >> w;
        graph.addEdge(u, v, w);
    }

    graph.printAdjList();
    cout << "After running Bellman-Ford's algorithm" << endl;
    graph.bellManFordAlgorithm(1);

    return 0;
}

