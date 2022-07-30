#include<iostream>
#include<vector>
using namespace std;

int dfs(int v,vector<bool> &visited,vector<int> adj[],int &edge){
    visited[v] = true;
    for (int u :adj[v] )
    {
        edge++;
        if(!visited[u])
            dfs(u,visited,adj,edge);
    }
    return edge;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<bool> visited(n,false);
        vector<int> adj[n];
        for(int i = 0;i<m;i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int maxedges = 0,edge = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                maxedges = max(maxedges,dfs(i,visited,adj,edge)/2);edge = 0;
            }
        }
        cout<<maxedges<<"\n";
    }
    return 0;
}
