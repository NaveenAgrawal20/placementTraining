// C++ program to find distance of nearest
// cell having 1 in a binary matrix.
#include<bits/stdc++.h>
#define MAX 500
#define N 3
#define M 4
using namespace std;

// Making a class of graph with bfs function.
class graph
{
private:
	vector<int> g[MAX];
	int n,m;

public:
	graph(int a, int b)
	{
		n = a;
		m = b;
	}

	// Function to create graph with N*M nodes
	// considering each cell as a node and each
	// boundary as an edge.
	void createGraph()
	{
		int k = 1; // A number to be assigned to a cell

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				// If last row, then add edge on right side.
				if (i == n)
				{
					// If not bottom right cell.
					if (j != m)
					{
						g[k].push_back(k+1);
						g[k+1].push_back(k);
					}
				}

				// If last column, then add edge toward down.
				else if (j == m)
				{
					g[k].push_back(k+m);
					g[k+m].push_back(k);
				}

				// Else makes an edge in all four directions.
				else
				{
					g[k].push_back(k+1);
					g[k+1].push_back(k);
					g[k].push_back(k+m);
					g[k+m].push_back(k);
				}

				k++;
			}
		}
	}

	// BFS function to find minimum distance
	void bfs(bool visit[], int dist[], queue<int> q)
	{
		while (!q.empty())
		{
			int temp = q.front();
			q.pop();

			for (int i = 0; i < g[temp].size(); i++)
			{
				if (visit[g[temp][i]] != 1)
				{
					dist[g[temp][i]] =
					min(dist[g[temp][i]], dist[temp]+1);

					q.push(g[temp][i]);
					visit[g[temp][i]] = 1;
				}
			}
		}
	}

	// Printing the solution.
	void print(int dist[])
	{
		for (int i = 1, c = 1; i <= n*m; i++, c++)
		{
			cout << dist[i] << " ";

			if (c%m == 0)
				cout << endl;
		}
	}
};

// Find minimum distance
void findMinDistance(bool mat[N][M])
{
	// Creating a graph with nodes values assigned
	// from 1 to N x M and matrix adjacent.
	graph g1(N, M);
	g1.createGraph();

	// To store minimum distance
	int dist[MAX];

	// To mark each node as visited or not in BFS
	bool visit[MAX] = { 0 };

	// Initialising the value of distance and visit.
	for (int i = 1; i <= M*N; i++)
	{
		dist[i] = INT_MAX;
		visit[i] = 0;
	}

	// Inserting nodes whose value in matrix
	// is 1 in the queue.
	int k = 1;
	queue<int> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (mat[i][j] == 1)
			{
				dist[k] = 0;
				visit[k] = 1;
				q.push(k);
			}
			k++;
		}
	}

	// Calling for Bfs with given Queue.
	g1.bfs(visit, dist, q);

	// Printing the solution.
	g1.print(dist);
}

// Driven Program
int main()
{
	bool mat[N][M] =
	{
		0, 0, 0, 1,
		0, 0, 1, 1,
		0, 1, 1, 0
	};

	findMinDistance(mat);

	return 0;
}
/*
Example
Input
2
3 3
0 0 1 1 1 1 1 0 1
4 4
1 0 1 0 0 0 0 0 0 0 0 0 1 1 1 0

Output
1 1 0 0 0 0 0 1 0 
0 1 0 1 1 2 1 2 1 1 1 2 0 0 0 1 

Sample Test case explanation
N
=
3
 and 
M
=
3

Matrix = 
⎡
⎢
⎣
0
0
1
1
1
1
1
0
1
⎤
⎥
⎦

Distance for index 
(
0
,
0
)
 to the nearest 
1
 is at index 
(
1
,
0
)
 which is 
1
(
1
−
0
+
0
−
0
=
1
)
 so in distance matrix at index 
(
0
,
0
)
 input 
1
.

Distance matrix = 
⎡
⎢
⎣
1
1
0
0
0
0
0
1
0
⎤
⎥
⎦

*/