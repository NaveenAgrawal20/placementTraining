#include <iostream>
#include <vector>
using namespace std;

void addEdge(int u, int v, vector<int> adj[])
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool hasCycle(int u, vector<int> adj[], vector<bool> vis, int prev)
{
    vis[u] = true;
    for (auto i : adj[u])
    {
        if (!vis[i])
        {
            if (hasCycle(i, adj, vis, u))
                return true;
        }
        else
        {
            if (i != prev)
                return true;
        }
    }
    return false;
}
bool detectCycle(vector<int> adj[], int n)
{
    vector<bool> visited(n, false);
    for (int u = 0; u < n; ++u)
    {
        if (!visited[u] && hasCycle(u, adj, visited, -1))
            return true;
    }
    return false;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj[n];
    for (int i = 0; i < e; ++i)
    {
        int u, v;
        cin >> u >> v;
        addEdge(u, v, adj);
    }
    cout << (detectCycle(adj, n) ? "Yes" : "No") << "\n";
    // for(int i = 0;i<n;i++){
    //     cout<<"I = "<<i<<" -> ";
    //     for (int j = 0; j < adj[i].size(); j++)
    //     {
    //         cout<<adj[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}
/*
10 11
5 0
4 0
3 6
8 7
8 1
9 3
7 9
2 0
8 4
8 2
1 4
YES

10 9
0 2
0 5
1 2
2 4
2 8
3 5
3 7
4 9
6 7
NO
*/