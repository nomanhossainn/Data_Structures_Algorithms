#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

class Edge{
    public:
    int u;
    int v;
    int w;
    Edge(int u, int v, int w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
};

bool comparator(const Edge &a, const Edge &b){
    return a.w<b.w;
}

class Graph{
    public:
    int V;
    int E;
    int vertexSet[100];
    vector <Edge> edgesVector;

    Graph(int V,int E){
        this->V=V;
        this->E=E;
    }

    void makeSet(){
        for(int i=1;i<=V;i++){
            vertexSet[i]=i;
        }
    }

    int findSet(int a){
        if(vertexSet[a]==a){
                return a;
        }else{
            int x= findSet(vertexSet[a]);
            return x;
        }


    }

    void unionVertices(int a,int b){
        int u=findSet(a);
        int v=findSet(b);
        if(u==v){
            return;
        }else{
            vertexSet[u]=v;
        }


    }

    void addEdge(int u,int v, int w){
        edgesVector.push_back(Edge(u,v,w));
    }

    void printEdgesVector(){
        for(Edge e:edgesVector){
            cout<<"("<<e.u<<","<<e.v<<","<<e.w<<")"<<endl;
        }
    }



    void mstKruskal(){
        vector <Edge> A;
        makeSet();
        sort(edgesVector.begin(),edgesVector.end(),comparator);
        for(Edge e : edgesVector){
            int u=e.u;
            int v=e.v;
            if(findSet(u)!=findSet(v)){
                A.push_back(e);
                unionVertices(u,v);
            }


        }

        cout<<"The selected edges:"<<endl;
        for(Edge e:A){
            cout<<"("<<e.u<<","<<e.v<<","<<e.w<<")"<<endl;
        }
    }
};

int main(){
    int V,E;
    cin>>V;
    cin>>E;
    Graph graph(V,E);

    for(int i=1;i<=E;i++){
        int u,v,w;
        cin>>u;
        cin>>v;
        cin>>w;
        graph.addEdge(u,v,w);
    }

    graph.printEdgesVector();
    graph.mstKruskal();
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


