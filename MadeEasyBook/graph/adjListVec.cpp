#include<iostream>
#include<vector>
using namespace std;

void printList(vector<int> vec[],int n){
    for(int i = 0;i<n;i++){
        cout<<"Adjacency nodes of node "<<i<<" is :\n";
        for(int ele:vec[i]) {
            cout<<"--> "<<ele<<"\n";
        }
    }
}

void addEdge(vector<int> vec[], int u, int v){
    vec[u].push_back(v);
    vec[v].push_back(u);
}


void DFSRecur(vector<int> adj[],vector<bool> &visited,int u){
    visited[u] = true;
//    cout<<u<<" ";
    for(int i = 0;i<adj[u].size();i++){
        if(!visited[adj[u][i]])
            DFSRecur(adj,visited,adj[u][i]);
    }
}
int DFS(vector<int> adj[],int nodes,int count){
    vector<bool> visited(nodes,false);
    for(int i = 0;i<nodes;i++){
        if (!visited[i]) {
            DFSRecur(adj, visited, i);
            count++;
        }
    }
    return count;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,e,count =0;
        cin>>n>>e;
        vector<int> *adj;
        adj = new vector<int>[n];
        for(int i = 0;i<n;i++){
            int u,v;
            cin>>u>>v;
            addEdge(adj,u,v);
        }
        cout<<DFS(adj,n,count)<<"\n";
    }
    return 0;
}
/*
2
4 4
0 1
0 2
0 3
1 2
4 4
0 1
1 2
2 3
2 3
7 7
0 1
0 2
2 3
1 4
4 5
1 6
5 6
 */