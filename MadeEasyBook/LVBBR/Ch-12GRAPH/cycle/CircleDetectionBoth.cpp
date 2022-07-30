#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	// Undirected
	void addEdge(int u, int v, vector<int> adj[])
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bool detectCycle(vector<int> adj[], int V)
	{
		vector<bool> visited(V, false);
		for (int i = 0; i < V; ++i)
		{
			if (!visited[i] && dfsCycle(i, -1, adj, visited))
				return true;
		}
		return false;
	}
	bool dfsCycle(int u, vector<int> adj[], vector<bool> &visited, int previous)
	{
		visited[u] = true;
		for (int next : adj[u])
		{
			// perform dfs for only unvisited
			if (!visited[next])
				if (dfsCycle(next, adj, visited, u))
					return true;
			// if visited and is not previous of curr (next) a cycle exits
				else if (next != prev)
					return true;
		}
		// if no cycle exists
		return false;
	}


	// DIRECTED
	void addEdgeDIR(int u, int v, vector<int> adj[]) {
		adj[u].push_back(v);
	}

	void detectCycleDIR(vector<int> adj[], int V)
	{
		vector<bool> visited(V, false);
		vector<bool> dfsVisited(V, false);

		for (int i = 0; i < V; ++i)
		{
			if (!visited[i] && dfsCycleDIR(i, adj, visited, dfsVisited))
				return true;
		}
		return false;
	}

	bool dfsCycleDIR(int u, vector<int> adj[], vector<int> &visited, visited<bool>& dfsVisited)
	{
		visited[u] = dfsVisited[u] = true;
		for (int next : adj[u])
		{
			if (!visited[next])
			{
				if (dfsCycleDIR(next, adj, visited, dfsVisited))
					return true;
			}
			else if (dfsVisited[next]) //true
				return true;
		}
		dfsVisited[u] = false;
		return false;
	}
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
			// addEdge(u, v, adj);
			addEdgeDIR(u, v, adj);
		}
		cout << (detectCycle(adj, n) ? "Yes" : "No") << "\n";
	}

	return 0;
}
/*


*/