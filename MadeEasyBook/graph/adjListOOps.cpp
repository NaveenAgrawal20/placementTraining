#include <iostream>
#include <list>
using namespace std;

class Graph{
    int nodes;
    list<int> *adjList;
public:
    Graph(int n){
        this->nodes = n;
        adjList = new list<int>[nodes];
    }
    void addEdge(int u, int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void printList(){
        for(int i = 0;i<nodes;i++){
            cout<<"Adjacency nodes of node "<<i<<" is :\n";
            for(int ele:adjList[i]) {
                cout<<"--> "<<ele<<"\n";
            }
        }
    }
    void BFS(int startVertex){
        bool *visited = new bool[nodes];
        for(int i = 0;i<nodes;i++)
            visited[i] = false;
        list<int> q; // act as queue
        q.push_back(startVertex);
        visited[startVertex] = true;
        while(!q.empty()){
            int current = q.front();q.pop_front();
            cout<<current<<" ";
            for(int ele:adjList[current]){
                if(!visited[ele]){
                    visited[ele] = true;
                    q.push_back(ele);
                }
            }
        }
    }
};

int main(){
    int n,e;
    cin>>n>>e;
    Graph graph(n);
    for(int i = 0;i<n;i++){
        int u,v;
        cin>>u>>v;
        graph.addEdge(u,v);
    }
    graph.printList();
    graph.BFS(0);
    return 0;
}
/*
7 7
0 1
0 2
2 3
1 4
1 6
2 5
5 6
*/