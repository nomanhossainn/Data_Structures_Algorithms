#include<iostream>
#include<list>
using namespace std;
class AdjListNode{
    public:
    int v;
    int w;

    AdjListNode(int v,int w){
        this->v=v;
        this->w=w;
    }

};
class Graph{
    public:
    int V;
    list <AdjListNode> *adjList;

    Graph(int V){
        this->V=V;
        adjList = new list <AdjListNode> [V+1];
    }

    void addEdge(int u,int v, int w){
        adjList[u].push_back(AdjListNode( v, w));
        adjList[v].push_back(AdjListNode( u, w));
    }

    void printAdjList(){
        for(int i=1;i<=V;i++){
            for(AdjListNode x : adjList[i]){
                cout<<"("<<x.v<<","<<x.w<<")"<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int V,E;
    cin>>V;
    cin>>E;

    Graph graph(V);

    for(int i=1;i<=E;i++){
        int u,v,w;
        cin>>u;
        cin>>v;
        cin>>w;
        graph.addEdge(u,v,w);
    }

    graph.printAdjList();


}

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

