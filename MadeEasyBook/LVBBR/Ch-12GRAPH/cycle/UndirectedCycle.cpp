#include <iostream>
#include <vector>

using namespace std;

void addEdge(int u, int v, vector<int> adj[]) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool hasCycle(int u, vector<int> adj[], vector<int> &visited, int previous) {
    visited[u] = 1;
    for(int v:adj[u]){
        if(visited[v] == 0){
            if(hasCycle(v,adj,visited,u))
                return true;
        }else{
            if(v != previous){
                return true;
            }
        }
    }
    return false;
}


bool detectCycle(vector<int> adj[], int n) {
    vector<int> visited(n, 0);
    for (int i = 0; i < n; ++i) {
        if (visited[i] == 0 && hasCycle(i, adj, visited, -1))
            return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, e;
        cin >> n >> e;
        vector<int> adj[n];
        for (int i = 0; i < e; ++i) {
            int u, v;
            cin >> u >> v;
            addEdge(u, v, adj);
        }
        cout << (detectCycle(adj, n) ? "Yes":"No") << "\n";
    }

    return 0;
}