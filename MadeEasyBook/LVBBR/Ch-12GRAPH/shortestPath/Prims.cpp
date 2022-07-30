#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

void addAdj(vector<pair<int, int>> *adj, int u, int v, int dis)
{
    adj[u].push_back(make_pair(v, dis));
}

void PrimMST(vector<pair<int, int>> *adj, int s, int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    int distance[n], path[n];
    int status[n],PERM = 1,TEMP = 0; // to limit dijkstra for only +ve weight 
    for (int i = 0; i < n; ++i)
    {
        distance[i] =INT_MAX;
        status[i] = TEMP;

        path[i] = -1;
    }
    distance[s] = 0;
    pq.push(make_pair(0, s)); // here 0 is distance // we prioritize on basis of difference
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        status[u] = PERM;
        for (pair<int, int> ele : adj[u])
        {
            int v = ele.first;
            int dis = ele.second;
            if (status[v] == TEMP && dis < distance[v])
            {
                distance[v] = dis;
                path[v] = u;
                pq.push(make_pair(distance[v], v));
            }
        }
    }
    cout << "\nPATH IS\n";
    
    for(int i:path){
        cout<<i<<"\t\t";
    }
    cout << "Edge \tWeight\n";
    for (int i = 0; i < n; i++)
    {
        if (path[i] != -1)
        {
            cout << path[i] << " - " << i << "\t" << distance[i] << "\n";
        }
    }
    cout << endl;
}

int main()
{
    int n, nv;
    cin >> n >> nv;
    vector<pair<int, int>> *adj;
    adj = new vector<pair<int, int>>[nv];
    for (int i = 1; i <= n; ++i)
    {
        int u, v, dis;
        cin >> u >> v >> dis;
        addAdj(adj, u, v, dis);
    }
    PrimMST(adj, 0, nv);

    return 0;
}
/*
22 6
0 1 6
0 2 2
0 3 3
0 4 10
1 3 11
1 5 9
2 3 14
2 4 8
3 4 7
3 5 5
4 5 4
1 0 6
2 0 2
3 0 3
4 0 10
3 1 11
5 1 9
3 2 14
4 2 8
4 3 7
5 3 5
5 4 4

14 10
0 1 2
0 3 6
1 0 2
1 2 3
1 3 8
1 4 5
2 1 3
2 4 7
3 0 6
3 1 8
3 4 9
4 1 5
4 2 7
4 3 9


14 9
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7



DISCONNECTED DEEPLIC
20 8
0 1 6
0 2 3
0 3 8
1 4 9
2 3 7
2 4 5
3 4 4
5 6 2
5 7 8
6 7 5
1 0 6
2 0 3
3 0 8
4 1 9
3 2 7
4 2 5
4 3 4
6 5 2
7 5 8
7 6 5
*/