#include <iostream>
#include <vector>

using namespace std;

void addEdge(int u, int v, vector<int> adj[]) {
    adj[u].push_back(v);

}

bool hasCycle(int u, vector<int> adj[], vector<int> &visited, vector<int> predecessor) {
    visited[u] = 1;
    predecessor[u] = 1;
    for(int v:adj[u]){
        if(visited[v] == 1 && predecessor[v] == 1)
                return true;
        else{
            return hasCycle(v,adj,visited,predecessor);
        }
    }
    return false;
}

bool detectCycle(vector<int> adj[], int n) {
    vector<int> visited(n, 0);
    vector<int> predecessor(n,0);
    for (int i = 0; i < n; ++i) {
        if (visited[i] == 0 && hasCycle(i, adj, visited, predecessor))
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
/*
2
3 3
0 1
0 2
1 2
 o = No
3 3
0 1
1 2
2 0
 out = Yes
Input 1
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

Output 1
no

Input 2
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

Output 2
No

4
3 3
0 1
0 2
1 2
3 3
0 1
1 2
2 0
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
 */