#include<bits/stdc++.h>
using namespace std;

class Solution
{
	unordered_map<int, vector<int>> adjList;
	vector<vector<int>> ans;
	/*
	disc => node discovered till now
	low => lowest node that can be reached
	*/
	vector<int> disc{0}, low{0};
	int id = 0; //times of visit

public:
	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
	{
		// Build adjacency
		for(vector<int> con:connections)
		{
			adjList[con[0]].push_back(con[1]);
			adjList[con[1]].push_back(con[0]);
		}

	    // discovered and Low  (init = 0)
	    disc = vector<int>(n);
	    low = vector<int>(n);

	    // is Node visited ? 
	    vector<bool> visited(n);

	    // Trajan Brigde
	    dfs(visited,0,-1);
	    return ans;    
	}
	void dfs(vector<bool>& visited, int curr,int prev)
	{
		visited[curr] = true;
		disc[curr] = low[curr] = id++; // post increment
		for(int nextNode:adjList[curr])
		{
			if(nextNode == prev)
				continue;
			// not visited or Cross Edge
			if(visited[nextNode] == false)
			{
				dfs(visited, nextNode, curr);
				// update curr's low value after recursion completes for nextNode
				low[curr] = min(low[curr],low[nextNode]);

				// if there is no path for v to reach back to previous vertices of curr
				if(low[nextNode] > disc[curr])
					ans.push_back({curr,nextNode});
			}
			// BackEdge
			else
			{
				// cannot use low[nextNode] (here refered as low[v])
				/*Note that low[v] = min(low[v], disc[curr]) is the correct way to update low[v] if curr is on stack (visited). 
				Because if curr is on the stack already, (v, curr) is a back-edge in the DFS tree 
				and therefore curr is not in the subtree of v. 
				Because low[v] takes into account nodes reachable only through the nodes in the subtree of v 
				we must stop at curr and use disc[curr] instead of low[curr]*/
				low[curr] = min(low[curr], disc[nextNode]);
			}
		}
	}
};

int main()
{
	 vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3}};
	 Solution s;
	 vector<vector<int>> ans = s.criticalConnections(4,connections);
	 for(auto e:ans)
	 	for(auto val:e)
	 		cout<<val<<' ';
	return 0;
}